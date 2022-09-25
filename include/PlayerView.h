//
// Grabs input from keyboard and mouse, interfaces with ProcessManager to draw.
//

#ifndef CSCI437_PLAYERVIEW_H
#define CSCI437_PLAYERVIEW_H

#include "ProcessManager.h"
#include "ProjectileActor.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <stdio.h>


class PlayerView {
public:
    PlayerView(const std::shared_ptr<ProcessManager> logic);
    ~PlayerView(void);
    void update(unsigned long long delta);
    void getInput(void);
    void csci437_error(const std::string& msg);
    const bool& isRunning(void) const;
    const bool& gameStarted(void) const;
    const bool& gamePaused(void) const;
    const bool& gameVictory(void) const;
private:
    void createTexture(void);
    void draw(void);
    std::shared_ptr<ProcessManager> logic;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    bool running = true;
    //Screen dimension constants
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    SDL_Rect windowRect;
    bool flip = false;
    bool left = false;
    float offset;
    float firstThird;
    float secondThird;
    SDL_Rect camRect;
    SDL_Texture* playerSprite;
    SDL_Texture* backgroundT;
    SDL_Texture* pauseT;
    SDL_Texture* tileMapT;
    SDL_Texture* enemyT;
    SDL_Texture* UIT;
    SDL_Texture* titleT;
    SDL_Texture* victoryT;
    SDL_Texture* pickupT;
    SDL_Rect bulletRect;
    SDL_Rect tileRect;
    SDL_Rect enemyRect;
    SDL_Rect playerRect;
    SDL_Rect curRect;
    SDL_Rect UIRectSrc;
    SDL_Rect UIRectDst;
    SDL_Rect pickupRectSrc;
    SDL_Rect pickupRectDst;
    //for player projectile
    int weapon = 1;
    bool shoot = false;
    float PROJECTILE_SPEED = 2.0f;
    //music
    Mix_Music* level1Theme;
    Mix_Music* bossTheme;
    Mix_Music* titleTheme;
    Mix_Music* victoryTheme;
    //sounds
    Mix_Chunk* jumpSound;
    Mix_Chunk* flipSound;
    Mix_Chunk* shootSound;
    Mix_Chunk* damageSound;
    Mix_Chunk* dieSound;
    bool victory = false;
    bool hasStarted;
    bool hasPaused = false;
    //projectile angle
    float delta_y;
    float delta_x;
    float angle;
    float player_x;
    float player_y;
    float player_hp;
    int currentLevel;
    SDL_Texture* bossT;
};


#endif //CSCI437_PLAYERVIEW_H