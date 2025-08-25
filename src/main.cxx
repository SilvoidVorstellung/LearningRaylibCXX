#include <raylib.h>

int main(void) {
  int screenWidth = 800;
  int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "basic window");

  SetTargetFPS(30);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("Random Text Messages.", 190, 200, 20, WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
