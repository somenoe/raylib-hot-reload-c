# Raylib Hot Reload in C

A proof of concept of using hot reload with the raylib library in C.

## Getting Started

1. **Clone the Repository:** Use the following command to download the project, including all necessary submodules:

    ```bash
    git clone --recurse-submodules https://github.com/somenoe/raylib-hot-reload-c.git
    ```

2. **Prepare Raylib:**  To set up the Raylib library, run:

    ```bash
    ./lib.bat
    ```

3. **Build the Project:** To compile the game code, run:

    ```bash
    ./build.bat
    ```

4. **Start the Game:** To launch the game, run:

    ```bash
    ./run.bat
    ```

5. **Update Game Code (Hot-Reload):** After making changes to your code, run the following to recompile and update the running game without needing to restart:

    ```bash
    ./update.bat
    ```

## How it Works

This system uses three key parts:

1. **Main Executable:** This is the main program that runs the game loop. It manages all game data.
2. **Game Code Library:** This is where you write your game logic. It's a special library that can be updated while the game is running.
3. **Raylib Library:** This is a library used to create the game. It is linked to the main program before the game starts.

The main program loads the Game Code Library while the game is running. It constantly checks if the Game Code Library has been updated. If an update is detected, the program loads the new library, allowing you to see your changes immediately without restarting. The Raylib Library remains connected to the main program, so it works seamlessly with the updated code.

## Learn More

* **Original Hot-Reload Template (Raylib 3.0):** [https://github.com/krzosa/raylib_hot_reload_template](https://github.com/krzosa/raylib_hot_reload_template)
* **Inspiration for Hot-Reload:** [https://hero.handmade.network/episode/code/day021/](https://hero.handmade.network/episode/code/day021/)
* **Git Submodules:** [https://gist.github.com/gitaarik/8735255](https://gist.github.com/gitaarik/8735255) (Explanation of Git submodules)
* **Raylib:** [https://github.com/raysan5/raylib](https://github.com/raysan5/raylib) (Official Raylib library)
