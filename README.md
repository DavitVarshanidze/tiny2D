# 2D Game Engine

This is a simple 2D game engine built using **SDL2**, **Lua**, and **C++**. It provides basic functionality for rendering 2D graphics, handling user input, and integrating Lua scripts for game logic. The engine is designed to be lightweight, modular, and easy to extend for your own game projects.

## Features

- **SDL2 Integration**: Utilizes SDL2 for window management, event handling, and graphics rendering.
- **Lua Scripting**: Embedded Lua for game logic scripting, allowing easy game customization.
- **C++ Backend**: The core engine is written in C++, providing performance and flexibility.
- **Makefile**: A simple Makefile to build the project.
- **Basic Game Loop**: Implements a standard game loop with update and render phases.

## Requirements

Before you begin, ensure you have the following installed:

- **SDL2**: The Simple DirectMedia Layer (SDL) library is required for graphics, input, and window handling.
- **Lua**: Lua is used to script game logic.
- **C++ Compiler**: A C++ compiler (like GCC or Clang) to build the engine.
- **Make**: The Make utility is used to compile the project with the provided Makefile.

### Installing SDL2:

#### macOS (Homebrew):
```bash
brew install sdl2
```

### Installing Lua:

#### macOS (Homebrew):
```bash
brew install lua
```

## Building the Engine

### Clone the repository:
```bash
git clone https://github.com/yourusername/2d-game-engine.git
cd 2d-game-engine
```

### Run make to compile the engine:
```bash
make
```

### Once compiled, run the engine with:
```bash
./engine
```

#### Contributing

Feel free to fork the repository and submit pull requests. If you encounter any issues or have suggestions for improvements, please open an issue on GitHub.