//Using SDL and standard IO
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <iostream>
#include <stdio.h>
#include "Actor.h"
#include "InactiveActor.h"
#include "PlatformActor.h"
#include "SpikeActor.h"
#include "PlayerActor.h"
#include "ProcessManager.h"
#include "InactiveProcess.h"
#include "PlayerView.h"
#include "AIView.h"
#include "LegActor.h"

int main(int argc, char** argv)
{
  /*** Initialization ***/
  
  std::shared_ptr<ProcessManager> logic = std::make_shared<ProcessManager>();
  logic->init();
  PlayerView playerView = PlayerView(logic);
  AIView aiView = AIView(logic);  
  unsigned long long previous = SDL_GetTicks();
  unsigned long long delta;

  // While application is running
  while( playerView.isRunning() ){ 
    delta = SDL_GetTicks() - previous;
    previous = SDL_GetTicks();

    if (delta > 100){
      delta = 100;
    }
    
    if (!playerView.gamePaused()){
      aiView.makeDecision(delta);
    }
    playerView.getInput();

    if (playerView.gameStarted() && !playerView.gamePaused() && !playerView.gameVictory()){
    logic->update(delta);
    }
    playerView.update(delta);
  }

  logic->destroy();
  
  // Done.
  return 0;

}
