#include <iostream>

#include "ui.hh"

#include "raylib.h"
#include "raymath.h"


int main() {

    Canvas canvas;
    Button btn_default(900, 900);
    canvas.add_component(&btn_default);

    while (canvas.window_is_active()) {
        canvas.draw();

        if (btn_default.is_pressed())
            std::cout << "is pressed\n";

    }

    return EXIT_SUCCESS;

}
