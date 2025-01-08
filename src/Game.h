#ifndef GAME_H // Header guards
#define GAME_H //

#include <SDL2/SDL.h>

class Game {
  private:
    bool          isRunning;
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

#endif //
