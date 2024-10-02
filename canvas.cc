#include "ui.hh"




Canvas::Canvas(int width, int height, int fps, Color bg_color, string title)
    : m_width   (width)
    , m_height  (height)
    , m_fps     (fps)
    , m_bg_color(bg_color)
    , m_title   (title)
{

    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(m_fps);
    InitWindow(m_width, m_height, m_title.c_str());

}

Canvas::~Canvas() {
    CloseWindow();
}

bool Canvas::window_is_active() {
    return !WindowShouldClose();
}


void Canvas::draw() {
    BeginDrawing();

    ClearBackground(m_bg_color);

    for (Component *component : m_components)
        component->update();

    EndDrawing();
}


void Canvas::add_component(Component *c) {
    m_components.push_back(c);
}
