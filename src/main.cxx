#include "raylib.h"

int main(void) {

  constexpr int screenWidth{800};
  constexpr int screenHeight{450};

  InitWindow(screenWidth, screenHeight, "Keyboard input test.");

  Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  SetTargetFPS(80);

  while (!WindowShouldClose()) {

    if (IsKeyDown(KEY_D))
      ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_A))
      ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_W))
      ballPosition.y -= 2.0f;
    if (IsKeyDown(KEY_S))
      ballPosition.y += 2.0f;

    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("Press WASD to move the ball.", 10, 10, 20, WHITE);

    DrawCircleV(ballPosition, 50, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
