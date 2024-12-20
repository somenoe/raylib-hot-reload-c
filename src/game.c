#include "helpers/shared.h"

// Called at the the start of the program
void Initialize(GameState *gameState)
{
	InitWindow(1280, 720, "PLACEHOLDER");
	SetTargetFPS(60);
}

// Called on every frame
void Update(GameState *gameState)
{
	BeginDrawing();
	{
		ClearBackground((Color){25, 25, 25, 255});
		// DrawRectangle(600, 100, 100, 100, RED);
		DrawRectangle(600, 100, 100, 100, GREEN);

		DrawFPS(10, 10);
	}
	EndDrawing();
}

// Called when you recompile the program while its running
void HotReload(GameState *gameState)
{
	TraceLog(LOG_INFO, "HOTRELOAD");
}

// Called before the dynamic libraries get swapped
void HotUnload(GameState *gameState)
{
	TraceLog(LOG_INFO, "HOTUNLOAD");
}
