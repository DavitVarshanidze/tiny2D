#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game {
  private:
    bool          isRunning;
    int millisecsPreviousFrame = 0;
    SDL_Window*   window;
    SDL_Renderer* renderer;
  
  public:
    // Constructor & Destructor 
    Game();
    ~Game();

    // Loop
    void Initialize();
    void Run();
    void Setup();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    // Window variables for width/height
    int windowWidth;
    int windowHeight;
};

#endif
