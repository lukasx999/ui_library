#include <iostream>

#include "ui.hh"

#include "raylib.h"
#include "raymath.h"



namespace Canvas {
    int width  = 1920,
        height = 1080,
        fps    = 60;
    Color bg = BLACK;
    const char *title = "ui";
}




int main() {

    Button btn_default(900, 900);



    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(Canvas::width, Canvas::height, Canvas::title);

    SetTargetFPS(Canvas::fps);
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(Canvas::bg);


            btn_default.update();

            if (btn_default.is_pressed())
                std::cout << "btn is pressed!" << std::endl;

        }
        EndDrawing();
    }
    CloseWindow();
    return EXIT_SUCCESS;
}
