//
//
//

#include "PlayerView.h"


PlayerView::PlayerView(const std::shared_ptr<ProcessManager> logic){
    /*** Initialization ***/

    // Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) csci437_error("SDL could not initialize!");

    // Initialize IMG
    if ( IMG_Init( IMG_INIT_PNG ) < 0 ) csci437_error("IMG could not initialize!");

    // Initialize Mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) csci437_error("Mixer could not initialize!");

    // Create window
    window = SDL_CreateWindow( "Flip Out", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL ) csci437_error("Window could not be created!");

    // init TTF
    if( TTF_Init() < 0 ) csci437_error("Unable to initialize TTF!");

    // Small delay to allow the system to create the window.
    SDL_Delay(100);

    // Create renderer
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL) csci437_error("Unable to create renderer!");

    //Create textures
    createTexture();

    //Create music
    level1Theme = Mix_LoadMUS( "../resource/Planet X_final.wav");
    bossTheme = Mix_LoadMUS("../resource/01_-_Pictionary_-_NES_-_Title.ogg");
    titleTheme = Mix_LoadMUS("../resource/01_-_Silver_Surfer_-_NES_-_Title_Screen.ogg");
    victoryTheme = Mix_LoadMUS("../resource/09_-_Silver_Surfer_-_NES_-_Hi_Score.ogg");

    //Create soundeffects
    jumpSound = Mix_LoadWAV("../resource/impactPlank_medium_004.ogg");
    flipSound = Mix_LoadWAV("../resource/forceField_001.ogg");
    shootSound = Mix_LoadWAV("../resource/LaserRetro_001.ogg");
    damageSound = Mix_LoadWAV("../resource/damage.ogg");
    dieSound = Mix_LoadWAV("../resource/dieSound.ogg");

    Mix_AllocateChannels(16);

    // Update the surface
    SDL_UpdateWindowSurface( window );

    this->logic = logic;
    offset = 0;
    firstThird = SCREEN_WIDTH / 3;
    secondThird = SCREEN_WIDTH / 2;

    camRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT*2 };
    curRect = { 0, 0, 80, 80 };
    tileRect = { 0, 0, 16, 16 };
    enemyRect = { 0, 0, 64, 64 };
    playerRect = { 0, 0, 78, 78 };
    UIRectSrc = { 0, 0, 16, 16 };
    UIRectDst = { 20, 20, 80, 80 };
    pickupRectSrc = { 0, 0, 32, 32 };
    pickupRectDst = { 0, 0, 32, 32 };

    hasStarted = false;
    currentLevel = 1;
    player_hp = logic->getPlayer()->getHitPoints();
}

void PlayerView::csci437_error(const std::string& msg){
    std::cerr << msg << " (" << SDL_GetError() << ")" << std::endl;
    exit(0);
}

void PlayerView::update(unsigned long long delta){

    if (!(SDL_GetWindowFlags(window) & SDL_WINDOW_INPUT_FOCUS) || (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED)){
        Mix_PauseMusic();
        if (!victory && hasStarted){
            hasPaused = true;
        }
    }
    else if (Mix_PausedMusic()){
        Mix_ResumeMusic();
    }
    
    if (!hasStarted && !Mix_PlayingMusic()){
        Mix_PlayMusic (titleTheme, -1);
    }
    
    if (logic->getCurrentLevel() == 3 && currentLevel != 3){
        Mix_HaltMusic();
        Mix_PlayMusic (bossTheme, -1);
    }

    if (victory && !Mix_PlayingMusic()){
        Mix_PlayMusic(victoryTheme,-1);
    }
    
    if (logic->getPlayer()->getXPosition()==SCREEN_WIDTH / 8 && logic->getPlayer()->getYPosition()==SCREEN_HEIGHT / 2){
        offset = 0;
        firstThird = SCREEN_WIDTH / 3;
        secondThird = SCREEN_WIDTH / 2;
    }

    if (logic->getCurrentLevel() == 3 && !hasPaused){
        if (currentLevel != logic->getCurrentLevel()){
            currentLevel = logic->getCurrentLevel();
            offset = 0;
        }
        if (logic->getPlayer()->getHitPoints() == 0){
            offset = 0;
        }
        offset += 0.1 * delta;
    }
    else if (logic->getCurrentLevel() != 3){
        if (currentLevel != logic->getCurrentLevel()){
            currentLevel = logic->getCurrentLevel();
            offset = 0;
        }
        if (logic->getPlayer()->getXPosition() + logic->getPlayer()->getWidth() > (secondThird + offset)){
            float deltaDist = logic->getPlayer()->getXPosition() + logic->getPlayer()->getWidth() - (secondThird + offset);
            offset += deltaDist;
        }
        else if (logic->getPlayer()->getXPosition() < (firstThird + offset) && offset > 0){
            float deltaDist = (firstThird + offset) - logic->getPlayer()->getXPosition();
            offset -= deltaDist;
        }
    }

    if (offset < 0){
        offset = 0;
    }

    if(logic->getPlayer()->justJumped() && !victory){
        Mix_PlayChannel(8,jumpSound,0);
    }
    if(logic->playerJustShot() && !victory){
        if (!logic->getPlayer()->getLaser()){
            Mix_Volume(9,64);
            Mix_PlayChannel(9,shootSound,0);
        }
        else{
            Mix_Volume(9,16);
            Mix_PlayChannel(9,shootSound,0);
        }
    }
    if (logic->getPlayer()->getHitPoints() != player_hp && !victory) {
        Mix_PlayChannel(10, damageSound, 0);
        player_hp = logic->getPlayer()->getHitPoints();
    }
    for (auto enemy : logic->getAIProcesses()){
        if(enemy->getState() == DESTROYED && !victory)
        {
            Mix_PlayChannel(11, dieSound, 0);
        }
    }

    windowRect.x = logic->getPlayer()->getXPosition() - offset;
    windowRect.y = logic->getPlayer()->getYPosition();
    windowRect.w = logic->getPlayer()->getWidth();
    windowRect.h = logic->getPlayer()->getHeight();
    camRect.x = offset * 0.3;

    flip = logic->getPlayer()->getFlip()-1;
    left = logic->getPlayer()->getFaceLeft();

    draw();
}

void PlayerView::getInput(void){
    while( SDL_PollEvent( &e ) != 0 )
    {
        // User requests quit
        if( e.type == SDL_QUIT ) running = false;

        if (!hasStarted){
            if( e.type == SDL_KEYDOWN ){
                if( e.key.keysym.sym == SDLK_SPACE ){ 
                    Mix_HaltMusic();
                    Mix_PlayMusic (level1Theme, -1);
                    hasStarted = true;
                    hasPaused = true;
                }
                else if( e.key.keysym.sym == SDLK_l ){
                    logic->setInput(6,1);
                }
                else if( e.key.keysym.sym == SDLK_a ){
                    logic->setInput(6,2);
                }
                else if( e.key.keysym.sym == SDLK_s ){
                    logic->setInput(6,3);
                }
                else if( e.key.keysym.sym == SDLK_e ){
                    logic->setInput(6,4);
                }
                else if( e.key.keysym.sym == SDLK_r ){
                    logic->setInput(6,5);
                }
                else{
                    logic->setInput(6,6);
                }
            }
            return;
        }

        if (hasPaused){
            if( e.type == SDL_KEYDOWN ){
                if( e.key.keysym.sym == SDLK_SPACE ){ 
                    hasPaused = false;
                }
            }
            return;
        }

        if (victory){
            if( e.type == SDL_KEYDOWN ){
                if( e.key.keysym.sym == SDLK_SPACE ){ 
                    running = false;
                }
            }
            return;
        }


        // User presses a key
        if( e.type == SDL_KEYDOWN )
        {
            if( e.key.keysym.sym == SDLK_w ) logic->setInput(2,1);
            if( e.key.keysym.sym == SDLK_a )
            {
                logic->setInput(0,1);
            }
            if( e.key.keysym.sym == SDLK_d )
            {
                logic->setInput(1,1);
            }
            if( e.key.keysym.sym == SDLK_e )
            {
                logic->setInput(3,1);
                Mix_PlayChannel(7, flipSound, 0);
            }
            if( e.key.keysym.sym == SDLK_1)
            {
                logic->setInput(5,1);
            }
            if( e.key.keysym.sym == SDLK_2)
            {
                logic->setInput(5,2);
            }
            if( e.key.keysym.sym == SDLK_ESCAPE)
            {
                hasPaused = true;
                SDL_Delay(100);
                SDL_PumpEvents();
            }
        }

        //handles mouse input for shooting
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                shoot = true;
                logic->setInput(4,1);

                if (e.button.x + offset <= player_x) {
                    left = true;
                }

                if (e.button.x + offset >= player_x) {
                    left = false;
                }
            }
        }

        if (e.type == SDL_MOUSEBUTTONUP) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                logic->setInput(4,0);
            }
        }

        if (e.type == SDL_KEYUP) {
            if (e.key.keysym.sym == SDLK_w) logic->setInput(2,0);
            if (e.key.keysym.sym == SDLK_a) logic->setInput(0,0);
            if (e.key.keysym.sym == SDLK_d) logic->setInput(1,0);
        }
    }
    //sets the angle for shooting based on the mouse position
    int x,y;
    SDL_GetMouseState(&x,&y);
    if (x + offset < logic->getPlayer()->getXPosition() - 16 || x + offset > logic->getPlayer()->getXPosition() + playerRect.w){
        if (flip == false) {
            player_y = (logic->getPlayer()->getYPosition() + 22);
        }

        if (flip == true) {
            player_y = (logic->getPlayer()->getYPosition() + 45);
        }

        if (left == false) {
            player_x = (logic->getPlayer()->getXPosition() + playerRect.w);
        }

        if (left == true) {
            player_x = (logic->getPlayer()->getXPosition() - 15);
        }

        delta_y = y - player_y;
        delta_x = x + offset - player_x;

        angle = (((atan2( delta_y, delta_x)) * 180) / M_PI);
        logic->setAngle(angle);
    }
}

const bool& PlayerView::isRunning(void) const{
    return running;
}

PlayerView::~PlayerView(void){
    /*** Clean Up ***/

    // Destroy Texture
    SDL_DestroyTexture( playerSprite );
    playerSprite = NULL;
    SDL_DestroyTexture( backgroundT );
    backgroundT = NULL;
    SDL_DestroyTexture( tileMapT );
    tileMapT = NULL;
    SDL_DestroyTexture( enemyT );
    enemyT = NULL;
    SDL_DestroyTexture( UIT );
    UIT = NULL;
    SDL_DestroyTexture( titleT );
    titleT = NULL;
    SDL_DestroyTexture( pauseT );
    pauseT = NULL;
    SDL_DestroyTexture( bossT );
    bossT = NULL;

    // Destroy sound
    Mix_FreeChunk(jumpSound);
    jumpSound = NULL;
    Mix_FreeChunk(flipSound);
    flipSound = NULL;
    Mix_FreeChunk(shootSound);
    shootSound = NULL;
    Mix_FreeChunk(damageSound);
    damageSound = NULL;
    Mix_FreeChunk(dieSound);
    dieSound = NULL;
    //destroy music
    Mix_HaltMusic();
    Mix_FreeMusic(level1Theme);
    level1Theme = NULL;
    Mix_FreeMusic(bossTheme);
    bossTheme = NULL;
    Mix_FreeMusic(titleTheme);
    titleTheme = NULL;
    Mix_FreeMusic(victoryTheme);
    victoryTheme = NULL;

    // Destroy renderer
    SDL_DestroyRenderer( renderer );
    renderer = NULL;

    // Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    // Quit SDL subsystems
    SDL_Quit();
}

void PlayerView::draw()
{
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );

    //Title screen drawing
    if (!hasStarted && !hasPaused){
        //Creation and destruction handled per-tick
        //Game not happening during this stage, does not effect performance
        camRect.h = SCREEN_HEIGHT;
        SDL_RenderCopy( renderer, titleT, NULL, NULL );
        camRect.h = SCREEN_HEIGHT*2;
        SDL_RenderPresent( renderer );
        return;
    }

    if ( victory ){
        camRect.h = SCREEN_HEIGHT;
        SDL_RenderCopy( renderer, victoryT, NULL, NULL );
        camRect.h = SCREEN_HEIGHT*2;
        SDL_RenderPresent( renderer );
        return;
    }

    //draw background
    SDL_RenderCopy( renderer, backgroundT, &camRect, NULL );

    if (hasPaused){
        camRect.h = SCREEN_HEIGHT;
        SDL_RenderCopy( renderer, pauseT, NULL, NULL );
        camRect.h = SCREEN_HEIGHT*2;
        SDL_RenderPresent( renderer );
        return;
    }

    // draw platforms and spikes
    for (auto platform : logic->getInactiveProcesses())
    {
        int n = platform->getActor()->getWidth() / 80;
        int initX = platform->getActor()->getXPosition() - offset;
        curRect.y = platform->getActor()->getYPosition();

        for ( int i = 0; i < n; i++ )
        {
            curRect.x = initX;
            if ( platform->getActor()->getActorType() == PLATFORM ) {
                tileRect.x = 0;
                tileRect.y = 0;
                SDL_RenderCopy( renderer, tileMapT, &tileRect, &curRect );
            }
            if ( platform->getActor()->getActorType() == SPIKE )
            {
                tileRect.x = 16;
                tileRect.y = 0;
                if ( platform->getActor()->getVerticalDirection() ) SDL_RenderCopy( renderer, tileMapT, &tileRect, &curRect );
                else SDL_RenderCopyEx(renderer, tileMapT, &tileRect, &curRect, 0, NULL, SDL_FLIP_VERTICAL);
            }
            initX += 80;
        }

    }

    // draw enemies
    for (auto enemy : logic->getAIProcesses())
    {
        int n = enemy->getActor()->getWidth() / 80;
        int initX = enemy->getActor()->getXPosition() - offset;
        curRect.y = enemy->getActor()->getYPosition();

        if ( enemy->getActorId() == LEG)
        {
            enemyRect.x = 0;
            enemyRect.y = 0;
            enemyRect.w = 6;
            enemyRect.h = 64;
            curRect.x = enemy->getActor()->getXPosition() - offset;
            curRect.w = enemy->getActor()->getWidth();
            curRect.h = enemy->getActor()->getHeight();
            SDL_Point rot = { curRect.w / 2 ,0};
            SDL_RenderCopyEx(renderer,bossT,&enemyRect,&curRect,enemy->getActor()->getRotation(),&rot,SDL_FLIP_NONE);

            enemyRect.x = 6;
            enemyRect.y = 0;
            enemyRect.w = 8;
            enemyRect.h = 8;
            curRect.x = enemy->getActor()->getXPosition() - offset;
            curRect.y = enemy->getActor()->getYPosition() - 10;
            curRect.w = 20;
            curRect.h = 20;
            SDL_RenderCopy(renderer,bossT,&enemyRect,&curRect);
            curRect.w = 80;
            curRect.h = 80;
        }
        if ( enemy->getActorId() == TYRANTULA){
            if ( enemy->getActor()->getHitPoints() <= 0 ){
                victory = true;
                Mix_HaltMusic();
            }
            enemyRect.x = 14;
            enemyRect.y = 0;
            enemyRect.w = 36;
            enemyRect.h = 36;
            curRect.x = enemy->getActor()->getXPosition() - offset;
            curRect.y = enemy->getActor()->getYPosition() - 10;
            curRect.w = enemy->getActor()->getWidth();
            curRect.h = enemy->getActor()->getHeight();
            SDL_RenderCopy(renderer,bossT,&enemyRect,&curRect);

            // draw boss HP bar
            enemyRect.x = 6;
            enemyRect.y = 52;
            enemyRect.w = 1;
            enemyRect.h = 4;
            curRect.x = 55;
            curRect.y = 695;
            curRect.w = 10;
            curRect.h = 50;
            for ( int i = 0; i < enemy->getActor()->getHitPoints(); i++ ){
                SDL_RenderCopy(renderer,bossT,&enemyRect,&curRect);
                curRect.x += 10;
            }
            enemyRect.x = 6;
            enemyRect.y = 58;
            enemyRect.w = 58;
            enemyRect.h = 6;
            curRect.x = 55;
            curRect.y = 700;
            curRect.w = 900;
            curRect.h = 50;
            SDL_RenderCopy(renderer,bossT,&enemyRect,&curRect);

            //reset dimension
            curRect.w = 80;
            curRect.h = 80;
        }   
        
        for ( int i = 0; i < n; i++ )
        {
            curRect.x = initX;
            if ( enemy->getActor()->getActorType() == FLYING_ENEMY )
            {
                enemyRect.x = 64;
                enemyRect.y = 0;
                enemyRect.w = 64;
                enemyRect.h = 64;

                if (enemy->getActor()->getxVel() <= 0) {
                    SDL_RenderCopy( renderer, enemyT, &enemyRect, &curRect );
                }
                else if (enemy->getActor()->getxVel() > 0){
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 0, NULL, SDL_FLIP_HORIZONTAL);
                }
            }
            if ( enemy->getActor()->getActorType() == WALKING_ENEMY )
            {
                enemyRect.x = 0;
                enemyRect.y = 0;
                enemyRect.w = 64;
                enemyRect.h = 64;
                if ( enemy->getActor()->getVerticalDirection() && enemy->getActor()->getxVel() <= 0) {
                    SDL_RenderCopy( renderer, enemyT, &enemyRect, &curRect );
                }
                else if (enemy->getActor()->getVerticalDirection() && enemy->getActor()->getxVel() > 0){
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 0, NULL, SDL_FLIP_HORIZONTAL);
                }
                else if (!enemy->getActor()->getVerticalDirection() && enemy->getActor()->getxVel() <= 0){
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 0, NULL, SDL_FLIP_VERTICAL);
                }
                else {
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 180, NULL, SDL_FLIP_NONE);
                }
            }
            if ( enemy->getActor()->getActorType() == LOBBING_ENEMY || enemy->getActorId() == LOBBING_ENEMY)
            {
                enemyRect.x = 0;
                enemyRect.y = 64;
                enemyRect.w = 64;
                enemyRect.h = 64;
                if ( enemy->getActor()->getVerticalDirection() && !enemy->getActor()->getHorizontalDirection()) {
                    SDL_RenderCopy( renderer, enemyT, &enemyRect, &curRect );
                }
                else if (enemy->getActor()->getVerticalDirection() && enemy->getActor()->getHorizontalDirection()){
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 0, NULL, SDL_FLIP_HORIZONTAL);
                }
                else if (!enemy->getActor()->getVerticalDirection() && !enemy->getActor()->getHorizontalDirection()){
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 0, NULL, SDL_FLIP_VERTICAL);
                }
                else {
                    SDL_RenderCopyEx(renderer, enemyT, &enemyRect, &curRect, 180, NULL, SDL_FLIP_NONE);
                }
            }
            initX += 80;
        }

    }


    //draw player
    if (logic->getPlayer()->getCurrentWeapon() == 1) {
        playerRect.x = 0;
        playerRect.w = 78;
        windowRect.w = 80;
    }
    if (logic->getPlayer()->getCurrentWeapon() == 2) {
        playerRect.x = 78;
        playerRect.w = 98;
        windowRect.w = 100;
    }
    if ((logic->getPlayer()->getIsInvincible() && int(logic->getPlayer()->getIFrames()) % 300 > 150) || !logic->getPlayer()->getIsInvincible()){
        if (flip && !left) SDL_RenderCopyEx(renderer, playerSprite, &playerRect, &windowRect, 0, NULL, SDL_FLIP_VERTICAL);
        else if (!flip && !left) SDL_RenderCopyEx(renderer, playerSprite, &playerRect, &windowRect, 0, NULL, SDL_FLIP_NONE);
        else if (flip && left) SDL_RenderCopyEx(renderer, playerSprite, &playerRect, &windowRect, 180, NULL, SDL_FLIP_NONE);
        else if (!flip && left) SDL_RenderCopyEx(renderer, playerSprite, &playerRect, &windowRect, 180, NULL, SDL_FLIP_VERTICAL);
    }
    // boxRGBA(renderer, logic->getPlayer()->getXPosition() - offset, logic->getPlayer()->getYPosition(), logic->getPlayer()->getXPosition() + logic->getPlayer()->getWidth() - offset, logic->getPlayer()->getYPosition() + logic->getPlayer()->getHeight(), 255,255,255,255);


    //draw bullets
        std::vector<std::shared_ptr<ActiveProcess>> projectiles = logic->getProjectileProcesses();
        for (int i = 0; i < projectiles.size(); i ++) {
            if (projectiles[i]->getActorId() == PLAYER_PISTOL_PROJECTILE || projectiles[i]->getActorId() == ENEMY_PISTOL_PROJECTILE) {
                tileRect.x = 0;
                tileRect.y = 16;
            }
            if (projectiles[i]->getActorId() == PLAYER_SPREAD_PROJECTILE || projectiles[i]->getActorId() == ENEMY_LOBBING_PROJECTILE) {
                tileRect.x = 16;
                tileRect.y = 16;
            }
            SDL_Rect rect{};
            rect.x = (projectiles[i]->getActor()->getXPosition() - offset);
            rect.y = (projectiles[i]->getActor()->getYPosition());
            rect.h = (projectiles[i]->getActor()->getHeight());
            rect.w = (projectiles[i]->getActor()->getWidth());
            bool horizontalDirection = projectiles[i]->getActor()->getHorizontalDirection();
            bool verticalDirection = projectiles[i]->getActor()->getVerticalDirection();
            if ( verticalDirection && !horizontalDirection) SDL_RenderCopyEx(renderer, tileMapT, &tileRect, &rect, 0, NULL, SDL_FLIP_VERTICAL);
            else if (!verticalDirection && !horizontalDirection) SDL_RenderCopyEx(renderer, tileMapT, &tileRect, &rect, 0, NULL, SDL_FLIP_NONE);
            else if (verticalDirection && horizontalDirection) SDL_RenderCopyEx(renderer, tileMapT, &tileRect, &rect, 180, NULL, SDL_FLIP_NONE);
            else if (!verticalDirection && horizontalDirection) SDL_RenderCopyEx(renderer, tileMapT, &tileRect, &rect, 180, NULL, SDL_FLIP_VERTICAL);
        }

    //placeholder for drawing level end pickup
    std::shared_ptr<InactiveProcess> levelEnd = logic->getLevelEndPickup();
    // boxRGBA(renderer, (levelEnd->getActor()->getXPosition() - offset), levelEnd->getActor()->getYPosition(), (levelEnd->getActor()->getXPosition() - offset) + 20, 
    //     levelEnd->getActor()->getYPosition()+20, 255, 0, 0, 128);
    pickupRectDst.x = levelEnd->getActor()->getXPosition() - offset;
    pickupRectDst.y = levelEnd->getActor()->getYPosition();
    if (logic->getCurrentLevel()==1){
        pickupRectSrc.x = 0;
        pickupRectSrc.y = 0;
    }
    if (logic->getCurrentLevel()==2){
        pickupRectSrc.x = 32;
        pickupRectSrc.y = 0;
    }
    if (logic->getCurrentLevel()==3){
        pickupRectSrc.x = 0;
        pickupRectSrc.y = 32;
    }
    SDL_RenderCopy( renderer, pickupT, &pickupRectSrc, &pickupRectDst );


    for (std::shared_ptr<InactiveProcess> healthPickup : logic->getHealthProcesses()){
        if (healthPickup->getState() == RUNNING){
            UIRectSrc.x = 16;
            UIRectSrc.y = 0;
            pickupRectDst.x = healthPickup->getActor()->getXPosition() - offset;
            pickupRectDst.y = healthPickup->getActor()->getYPosition();
            if (healthPickup -> getActor()->getVerticalDirection() == 0){
                SDL_RenderCopyEx( renderer, UIT, &UIRectSrc, &pickupRectDst, 180, NULL, SDL_FLIP_NONE);}
        else{SDL_RenderCopyEx( renderer, UIT, &UIRectSrc, &pickupRectDst, 180, NULL, SDL_FLIP_VERTICAL);}
        }
    }

    //draw UI
    UIRectDst.x = 20;
    UIRectDst.y = 20;
    UIRectSrc.x = 0;
    UIRectSrc.y = 0;

    //draw HP
    UIRectSrc.x = 16;
    for (int i = 0; i < logic->getPlayer()->getHitPoints(); i++){
        SDL_RenderCopy( renderer, UIT, &UIRectSrc, &UIRectDst );
        UIRectDst.x += 90;
    }
    //draw gadget
    UIRectSrc.x = 0;
    UIRectDst.x = 20;
    UIRectDst.y += 90;
    SDL_RenderCopy( renderer, UIT, &UIRectSrc, &UIRectDst );
    UIRectDst.x += 90;
    //draw weapon
    UIRectSrc.y = 16;
    if (logic->getPlayer()->getCurrentWeapon() == 1) UIRectSrc.x = 0;
    if (logic->getPlayer()->getCurrentWeapon() == 2) UIRectSrc.x = 16;
    SDL_RenderCopy( renderer, UIT, &UIRectSrc, &UIRectDst );

    SDL_RenderPresent( renderer );

}

void PlayerView::createTexture(){
    SDL_Surface* temp = IMG_Load("../resource/Player_Texture.png");
    playerSprite = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/Background.PNG");
    backgroundT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/Tile_Map.png");
    tileMapT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/Enemy_Texture.PNG");
    enemyT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/UI_sheet.PNG");
    UIT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/Title_Screen.PNG");
    titleT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/Victory_Screen.PNG");
    victoryT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/PauseScreen.png");
    pauseT = SDL_CreateTextureFromSurface(renderer, temp);
    temp = IMG_Load("../resource/Tyrantula_Texture.PNG");
    bossT = SDL_CreateTextureFromSurface(renderer,temp);
    temp = IMG_Load("../resource/Pickup_Texture.PNG");
    pickupT = SDL_CreateTextureFromSurface(renderer,temp);
    temp = IMG_Load("../resource/Window_Icon.PNG");
    SDL_SetWindowIcon(window,temp);
    SDL_FreeSurface(temp);
    temp = NULL;

}

const bool& PlayerView::gameStarted() const{
    return hasStarted;
}

const bool& PlayerView::gamePaused(void) const{
    return hasPaused;
}

const bool& PlayerView::gameVictory(void) const{
    return victory;
}