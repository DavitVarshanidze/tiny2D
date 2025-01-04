#include <iostream>
#include <SDL2/SDL.h
#include "Game.h"

Game::Game() {
  isRunning = false; // 

  std::cout << "game constructor called" << std::endl;
  
}

Game::~Game() {
  std::cout << "game destructor called" << std::endl;
  
}

void Game::Initialize() {
  // Initialising
  if (SDL_Init(SDL_INIT_EVERYTHIN) != 0) {
    std::cerr << "Error initialising SDL" << std::endl;
    return;
  }
  // Create Window
  window = SDL_CreateWindow(
			    NULL,
			    SDL_WINDOWPOS_CENTERED,
			    SDL_WINDOWPOS_CENTERED,
			    800,
			    600,
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

  isRunning = true;
}
 
void Game::ProcessInput() {
  SDL_Event = sdlEvent;
  while (SDL_PollEvent(&sdlEvent)) {
    switch(sdlEvent.type) {
      case SDL_QUIT:
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

void Game::Update() {
  
}

void Game::Render() {
  
}

void Game::Run() {
  while (isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Game::Destroy() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
