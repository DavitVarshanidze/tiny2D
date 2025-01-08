#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

Game::Game() {
  isRunning = false; // Start of compiler, needs to be set false

  std::cout << "game constructor called" << std::endl;
  
}

Game::~Game() {
  std::cout << "game destructor called" << std::endl;
  
}

void Game::Initialize() {
  // Initialising
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initialising SDL" << std::endl;
    return;
  }
  // Create Window
  SDL_DisplayMode displayMode;
  SDL_GetCurrentDisplayMode(0, &displayMode);
  windowWidth  = 800;
  windowHeight = 600;
  window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			windowWidth,
			windowHeight,
			SDL_WINDOW_BORDERLESS
  );
  if (!window) {
    std::cerr << "Error creating SDL window" << std::endl;
    return;
  }
  // Create Renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "Error creating SDL renderer" << std::endl;
    return;
  }
  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

  isRunning = true; // End of initialising reverting back to true
}
 
void Game::ProcessInput() {
  // Handling key press events
  SDL_Event sdlEvent;
  while (SDL_PollEvent(&sdlEvent)) {
    switch(sdlEvent.type) {
      case SDL_QUIT: // SDL_QUIT is like when you click on 'X' it's when OS does that "QUIT" function
	isRunning = false;
	break;
      case SDL_KEYDOWN:
	if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
	  isRunning = false;
	}
	break;
    }
  }
}

void Game::Setup() {
  
}

void Game::Update() {
  
}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
  SDL_RenderClear(renderer);

  // Draw a rectangle
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_Rect player = { 10, 10, 20, 20 };
  SDL_RenderFillRect(renderer, &player);
  
  SDL_RenderPresent(renderer);
}

void Game::Run() {
  Setup();
  while (isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Game::Destroy() {
  // Destroy after quiting the program, we need it to avoid memory leaks
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
