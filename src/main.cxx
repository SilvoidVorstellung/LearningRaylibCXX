#include "raylib.h"
#include <cmath>

int main(void) {

  constexpr int screenWidth{800};
  constexpr int screenHeight{450};
  constexpr int MAX_BUILDINGS{100};

  InitWindow(screenWidth, screenHeight, "test project.");

  Rectangle buildings[MAX_BUILDINGS] = {0};
  Color buildColors[MAX_BUILDINGS] = {0};

  Rectangle player = {400, 280, 40, 40};

  int spacing = 0;

  for (int i; i < MAX_BUILDINGS; i++) {
    buildings[i].width = (float)GetRandomValue(50, 200);
    buildings[i].height = (float)GetRandomValue(100, 800);
    buildings[i].y = screenHeight - 130.0f - buildings[i].height;
    buildings[i].x = -6000.0f + spacing;

    spacing += (int)buildings[i].width;

    buildColors[i] = (Color){(unsigned char)GetRandomValue(200, 240),
                             (unsigned char)GetRandomValue(200, 240),
                             (unsigned char)GetRandomValue(200, 250), 255};
  }

  Vector2 ball2Position = {-100.0f, 100.0f};

  Color ball2Color = DARKBLUE;

  int boxPositionY = screenHeight / 2 - 40;
  int boxPositionX = screenWidth / 2;
  int scrollSpeed = 50;
  int offset = 40;

  Camera2D camera = {0};
  camera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};
  camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
  camera.zoom = 1.0f;

  SetTargetFPS(30);

  while (!WindowShouldClose()) {

    if (IsKeyDown(KEY_D))
      player.x += 10;
    if (IsKeyDown(KEY_A))
      player.x -= 10;
    if (IsKeyDown(KEY_S))
      player.y += 10;
    if (IsKeyDown(KEY_W))
      player.y -= 10;

    if (IsKeyPressed(KEY_H)) {
      if (IsCursorHidden()) {
        ShowCursor();
      } else {
        HideCursor();
      }
    }

    camera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};

    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));

    if (camera.zoom > 3.0f)
      camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f)
      camera.zoom = 0.1f;

    if (IsKeyPressed(KEY_R)) {
      camera.zoom = 1.0f;
    }

    ball2Position = GetMousePosition();

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

    BeginMode2D(camera);

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

    for (int i = 0; i < MAX_BUILDINGS; i++)
      DrawRectangleRec(buildings[i], buildColors[i]);

    DrawRectangleRec(player, RED);

    DrawLine((int)camera.target.x, -screenHeight * 10, (int)camera.target.x,
             screenHeight * 10, GREEN);
    DrawLine(-screenWidth * 10, (int)camera.target.y, screenWidth * 10,
             (int)camera.target.y, GREEN);

    EndMode2D();

    DrawText("Press WASD to move the player.", 10, 10, 20, WHITE);
    DrawText("Move the mouse the move the blue ball.", 10, 30, 20, WHITE);

    DrawCircleV(ball2Position, 10, ball2Color);

    DrawText("Use scroll wheel to zoom.", 10, 50, 20, WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
