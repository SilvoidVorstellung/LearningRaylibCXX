#include "raylib.h"

int main(void) {

  constexpr int screenWidth{800};
  constexpr int screenHeight{450};

  InitWindow(screenWidth, screenHeight, "Keyboard and mouse input test.");

  Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  Vector2 ball2Position = {-100.0f, 100.0f};

  Color ballColor = RED;
  Color ball2Color = DARKBLUE;

  int boxPositionY = screenHeight / 2 - 40;
  int boxPositionX = screenWidth / 2;
  int scrollSpeed = 50;
  int offset = 40;

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

    ball2Position = GetMousePosition();

    boxPositionY -= (int)(GetMouseWheelMove() * scrollSpeed);
    boxPositionX = GetMouseX() - offset;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      ball2Color = MAROON;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
      ball2Color = LIME;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
      ball2Color = DARKBLUE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE))
      ball2Color = PURPLE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA))
      ball2Color = YELLOW;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD))
      ball2Color = ORANGE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK))
      ball2Color = BEIGE;

    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("Press WASD to move the ball.", 10, 10, 20, WHITE);
    DrawText("Move the mouse the move the blue ball.", 10, 30, 20, WHITE);

    DrawCircleV(ballPosition, 50, ballColor);
    DrawRectangle(boxPositionX, boxPositionY, 80, 80, MAGENTA);
    DrawCircleV(ball2Position, 30, ball2Color);

    DrawText("Use scroll wheel to move the box up and down.", 10, 50, 20,
             WHITE);

    DrawText(TextFormat("boxPositionY: %03i", boxPositionY), 10, 400, 20,
             WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
