/**
 * @ref https://www.raylib.com/examples.html
 */

#include "shared.h"

void Initialize(GameState *gameState)
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - window flags");

	SetWindowState(FLAG_VSYNC_HINT);

	gameState->ballPosition = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	gameState->ballSpeed = (Vector2){7.0f, 5.0f};
	gameState->ballRadius = 20;

	gameState->framesCounter = 0;
}

void SetKeyboardShortcuts(GameState *gameState)
{
	if (IsKeyPressed(KEY_F))
		ToggleFullscreen(); // modifies window size when scaling!

	if (IsKeyPressed(KEY_R))
	{
		if (IsWindowState(FLAG_WINDOW_RESIZABLE))
			ClearWindowState(FLAG_WINDOW_RESIZABLE);
		else
			SetWindowState(FLAG_WINDOW_RESIZABLE);
	}

	if (IsKeyPressed(KEY_D))
	{
		if (IsWindowState(FLAG_WINDOW_UNDECORATED))
			ClearWindowState(FLAG_WINDOW_UNDECORATED);
		else
			SetWindowState(FLAG_WINDOW_UNDECORATED);
	}

	if (IsKeyPressed(KEY_H))
	{
		if (!IsWindowState(FLAG_WINDOW_HIDDEN))
			SetWindowState(FLAG_WINDOW_HIDDEN);

		gameState->framesCounter = 0;
	}

	if (IsWindowState(FLAG_WINDOW_HIDDEN))
	{
		gameState->framesCounter++;
		if (gameState->framesCounter >= 240)
			ClearWindowState(FLAG_WINDOW_HIDDEN); // Show window after 3 seconds
	}

	if (IsKeyPressed(KEY_N))
	{
		if (!IsWindowState(FLAG_WINDOW_MINIMIZED))
			MinimizeWindow();

		gameState->framesCounter = 0;
	}

	if (IsWindowState(FLAG_WINDOW_MINIMIZED))
	{
		gameState->framesCounter++;
		if (gameState->framesCounter >= 240)
			RestoreWindow(); // Restore window after 3 seconds
	}

	if (IsKeyPressed(KEY_M))
	{
		// NOTE: Requires FLAG_WINDOW_RESIZABLE enabled!
		if (IsWindowState(FLAG_WINDOW_MAXIMIZED))
			RestoreWindow();
		else
			MaximizeWindow();
	}

	if (IsKeyPressed(KEY_U))
	{
		if (IsWindowState(FLAG_WINDOW_UNFOCUSED))
			ClearWindowState(FLAG_WINDOW_UNFOCUSED);
		else
			SetWindowState(FLAG_WINDOW_UNFOCUSED);
	}

	if (IsKeyPressed(KEY_T))
	{
		if (IsWindowState(FLAG_WINDOW_TOPMOST))
			ClearWindowState(FLAG_WINDOW_TOPMOST);
		else
			SetWindowState(FLAG_WINDOW_TOPMOST);
	}

	if (IsKeyPressed(KEY_A))
	{
		if (IsWindowState(FLAG_WINDOW_ALWAYS_RUN))
			ClearWindowState(FLAG_WINDOW_ALWAYS_RUN);
		else
			SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
	}

	if (IsKeyPressed(KEY_V))
	{
		if (IsWindowState(FLAG_VSYNC_HINT))
			ClearWindowState(FLAG_VSYNC_HINT);
		else
			SetWindowState(FLAG_VSYNC_HINT);
	}
}

void Update(GameState *gameState)
{
	SetKeyboardShortcuts(gameState);

	// Bouncing ball logic
	gameState->ballPosition.x += gameState->ballSpeed.x;
	gameState->ballPosition.y += gameState->ballSpeed.y;
	if ((gameState->ballPosition.x >= (GetScreenWidth() - gameState->ballRadius)) || (gameState->ballPosition.x <= gameState->ballRadius))
		gameState->ballSpeed.x *= -1.0f;
	if ((gameState->ballPosition.y >= (GetScreenHeight() - gameState->ballRadius)) || (gameState->ballPosition.y <= gameState->ballRadius))
		gameState->ballSpeed.y *= -1.0f;

	BeginDrawing();
	{

		if (IsWindowState(FLAG_WINDOW_TRANSPARENT))
			ClearBackground(BLANK);
		else
			ClearBackground(RAYWHITE);

		DrawCircleV(gameState->ballPosition, gameState->ballRadius, MAROON);
		DrawRectangleLinesEx((Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, 4, RAYWHITE);

		DrawCircleV(GetMousePosition(), 10, DARKBLUE);

		DrawFPS(10, 10);

		DrawText(TextFormat("Screen Size: [%i, %i]", GetScreenWidth(), GetScreenHeight()), 10, 40, 10, GREEN);

		// Draw window state info
		DrawText("Following flags can be set after window creation:", 10, 60, 10, GRAY);
		if (IsWindowState(FLAG_FULLSCREEN_MODE))
			DrawText("[F] FLAG_FULLSCREEN_MODE: on", 10, 80, 10, LIME);
		else
			DrawText("[F] FLAG_FULLSCREEN_MODE: off", 10, 80, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_RESIZABLE))
			DrawText("[R] FLAG_WINDOW_RESIZABLE: on", 10, 100, 10, LIME);
		else
			DrawText("[R] FLAG_WINDOW_RESIZABLE: off", 10, 100, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_UNDECORATED))
			DrawText("[D] FLAG_WINDOW_UNDECORATED: on", 10, 120, 10, LIME);
		else
			DrawText("[D] FLAG_WINDOW_UNDECORATED: off", 10, 120, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_HIDDEN))
			DrawText("[H] FLAG_WINDOW_HIDDEN: on", 10, 140, 10, LIME);
		else
			DrawText("[H] FLAG_WINDOW_HIDDEN: off", 10, 140, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_MINIMIZED))
			DrawText("[N] FLAG_WINDOW_MINIMIZED: on", 10, 160, 10, LIME);
		else
			DrawText("[N] FLAG_WINDOW_MINIMIZED: off", 10, 160, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_MAXIMIZED))
			DrawText("[M] FLAG_WINDOW_MAXIMIZED: on", 10, 180, 10, LIME);
		else
			DrawText("[M] FLAG_WINDOW_MAXIMIZED: off", 10, 180, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_UNFOCUSED))
			DrawText("[G] FLAG_WINDOW_UNFOCUSED: on", 10, 200, 10, LIME);
		else
			DrawText("[U] FLAG_WINDOW_UNFOCUSED: off", 10, 200, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_TOPMOST))
			DrawText("[T] FLAG_WINDOW_TOPMOST: on", 10, 220, 10, LIME);
		else
			DrawText("[T] FLAG_WINDOW_TOPMOST: off", 10, 220, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_ALWAYS_RUN))
			DrawText("[A] FLAG_WINDOW_ALWAYS_RUN: on", 10, 240, 10, LIME);
		else
			DrawText("[A] FLAG_WINDOW_ALWAYS_RUN: off", 10, 240, 10, MAROON);
		if (IsWindowState(FLAG_VSYNC_HINT))
			DrawText("[V] FLAG_VSYNC_HINT: on", 10, 260, 10, LIME);
		else
			DrawText("[V] FLAG_VSYNC_HINT: off", 10, 260, 10, MAROON);

		DrawText("Following flags can only be set before window creation:", 10, 300, 10, GRAY);
		if (IsWindowState(FLAG_WINDOW_HIGHDPI))
			DrawText("FLAG_WINDOW_HIGHDPI: on", 10, 320, 10, LIME);
		else
			DrawText("FLAG_WINDOW_HIGHDPI: off", 10, 320, 10, MAROON);
		if (IsWindowState(FLAG_WINDOW_TRANSPARENT))
			DrawText("FLAG_WINDOW_TRANSPARENT: on", 10, 340, 10, LIME);
		else
			DrawText("FLAG_WINDOW_TRANSPARENT: off", 10, 340, 10, MAROON);
		if (IsWindowState(FLAG_MSAA_4X_HINT))
			DrawText("FLAG_MSAA_4X_HINT: on", 10, 360, 10, LIME);
		else
			DrawText("FLAG_MSAA_4X_HINT: off", 10, 360, 10, MAROON);
	}
	EndDrawing();
}

void HotReload(GameState *gameState)
{
	TraceLog(LOG_INFO, "RELOADED");
}

void HotUnload(GameState *gameState)
{
	TraceLog(LOG_INFO, "UNLOADED");
}
