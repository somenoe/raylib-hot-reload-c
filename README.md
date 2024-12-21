# Raylib Hot Reload in C

A proof of concept of using hot reload with the Raylib library in C.

## Getting Started

1. **Clone the Repository:**
   Clone the repository with submodules:

   ```bash
   git clone --recurse-submodules https://github.com/somenoe/raylib-hot-reload-c.git
   ```

2. **Prepare Raylib:**
   Run the library setup script:

   ```bash
   ./lib.bat
   ```

3. **Run the Development Script:**
   Build and run the game with hot reloading:

   ```bash
   ./dev.bat
   ```

## How Hot Reloading Works

This system uses three key parts:

1. **Main Executable:** This is the main program that runs the game loop. It manages all game data.
2. **Game Code Library:** This is where you write your game logic. It's a special library that can be updated while the game is running.
3. **Raylib Library:** This is a library used to create the game. It is linked to the main program before the game starts.

The main program loads the Game Code Library while the game is running. It constantly checks if the Game Code Library has been updated. If an update is detected, the program loads the new library, allowing you to see your changes immediately without restarting. The Raylib Library remains connected to the main program, so it works seamlessly with the updated code.

## Optional Scripts

- **Build:** Compile the game code:

  ```bash
  ./build.bat
  ```

- **Run:** Launch the game:

  ```bash
  ./run.bat
  ```

- **Update:** Recompile and update the running game (hot-reload):

  ```bash
  ./update.bat
  ```

- **Watch:** Automatically update the game when source files change:

  ```bash
  ./watch.bat
  ```

## Learn More

- **Original Hot-Reload Template:** [https://github.com/krzosa/raylib_hot_reload_template](https://github.com/krzosa/raylib_hot_reload_template)
- **Hot-Reloading Inspiration:** [https://hero.handmade.network/episode/code/day021/](https://hero.handmade.network/episode/code/day021/)
- **Git Submodules Explained:** [https://gist.github.com/gitaarik/8735255](https://gist.github.com/gitaarik/8735255)
- **Raylib Library:** [https://github.com/raysan5/raylib](https://github.com/raysan5/raylib)
