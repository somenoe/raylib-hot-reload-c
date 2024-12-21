#include "library/raylib.h"

typedef struct GameState
{
	int framesCounter;

	Vector2 ballPosition;
	Vector2 ballSpeed;
	float ballRadius;

} GameState;
