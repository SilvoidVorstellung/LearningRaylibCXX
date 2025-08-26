#include "raylib.h"

int main(void) {

  constexpr int screenWidth{800};
  constexpr int screenHeight{450};

  InitWindow(screenWidth, screenHeight, "Keyboard and mouse input test.");

  Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  Vector2 ball2Position = {-100.0f, 100.0f};

  Color ballColor = RED;
  Color ball2Color = DARKBLUE;

  SetTargetFPS(30);

  while (!WindowShouldClose()) {

    if (IsKeyDown(KEY_D))
      ballPosition.x += 6.0f;
    if (IsKeyDown(KEY_A))
      ballPosition.x -= 6.0f;
    if (IsKeyDown(KEY_W))
      ballPosition.y -= 6.0f;
    if (IsKeyDown(KEY_S))
      ballPosition.y += 6.0f;

    if (IsKeyPressed(KEY_H)) {
      if (IsCursorHidden()) {
        ShowCursor();
      } else {
        HideCursor();
      }
    }

    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("Press WASD to move the ball.", 10, 10, 20, WHITE);
    DrawText("Move the mouse the move the blue ball.", 10, 30, 20, WHITE);

    DrawCircleV(ballPosition, 50, ballColor);
    DrawCircleV(GetMousePosition(), 30, ball2Color);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
