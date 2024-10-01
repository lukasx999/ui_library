
#include "ui.hh"




Button::Button(float x, float y,
               float width, float height,
               std::string text, float text_fontsize, Color text_color, Color text_pressed_color,
               Color bg_color, Color hover_color, Color pressed_color)

    : Component            (x, y)
    , m_width              (width)
    , m_height             (height)
    , m_text_string        (text)
    , m_text_fontsize      (text_fontsize)
    , m_text_color         (text_color)
    , m_text_pressed_color (text_pressed_color)
    , m_bg_color           (bg_color)
    , m_hover_color        (hover_color)
    , m_pressed_color      (pressed_color)

    , m_is_pressed         (false)
    , m_is_hovered         (false)

    , m_was_pressed_       (false)
    , m_current_bg_color_  (m_bg_color)
    , m_current_text_color_(m_text_color)

{
}


void Button::update_color() {
    m_current_bg_color_ = m_is_hovered ? (m_is_pressed ? m_pressed_color : m_hover_color) : m_bg_color;
    m_current_text_color_ = m_is_pressed ? m_text_pressed_color : m_text_color;
}


void Button::check_collision(Rectangle rec) {

    Vector2 mouse_pos = GetMousePosition();
    m_is_hovered = CheckCollisionPointRec(mouse_pos, rec);
    m_is_pressed = m_is_hovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT);

}


void Button::render(Rectangle rec) {

    const char *str = m_text_string.c_str();

    int text_width = MeasureText(str, m_text_fontsize)/2;

    DrawRectangleRec(rec, m_current_bg_color_);
    DrawText(str, m_x - text_width, m_y-m_text_fontsize/2, m_text_fontsize, m_current_text_color_);

}


void Button::update() {

    float start_x = m_x - m_width/2;
    float start_y = m_y - m_height/2;
    Rectangle rec  { .x = start_x, .y = start_y, .width = m_width, .height = m_height };

    render(rec);
    check_collision(rec);
    update_color();

}



bool Button::is_pressed() {

    bool edge = m_is_pressed && !m_was_pressed_;
    m_was_pressed_ = m_is_pressed;
    return edge;

}

bool Button::is_released() {

    bool edge = !m_is_pressed && m_was_pressed_;
    m_was_pressed_ = m_is_pressed;
    return edge;

}




