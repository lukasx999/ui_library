#pragma once

#include <iostream>


#include "raylib.h"
#include "raymath.h"




using std::string;




class Component {
public:

    float m_x, m_y; // center

    Component(float x, float y);
    virtual ~Component();

    virtual void update() = 0;

protected:
};





class DefaultColors {
public:
    static constexpr Color
    normal       = { 60,  60,  60,  255 },
    hover        = { 100, 100, 100, 255 },
    press        = { 200, 200, 200, 255 },
    text         = { 200, 200, 200, 255 },
    text_pressed = { 0,   0,   0,   255 };
};



class Button : public Component {
public:

    float  m_width;
    float  m_height;

    string m_text_string;
    float  m_text_fontsize;
    Color  m_text_color;
    Color  m_text_pressed_color;

    Color  m_bg_color;
    Color  m_hover_color;
    Color  m_pressed_color;

    bool   m_is_pressed;
    bool   m_is_hovered;

    // button config object?
    Button(float x, float y,
           float  width              = 200.0f,
           float  height             = 100.0f,
           string text               = "button",
           float  text_fontsize      = 30.0f,
           Color  text_color         = DefaultColors::text,
           Color  text_pressed_color = DefaultColors::text_pressed,
           Color  bg_color           = DefaultColors::normal,
           Color  hover_color        = DefaultColors::hover,
           Color  pressed_color      = DefaultColors::press);

    virtual void update() override;
    bool is_pressed();
    bool is_released();

protected:
    bool m_was_pressed_;
    Color m_current_bg_color_;
    Color m_current_text_color_;

    void update_color();
    void check_collision(Rectangle rec);
    void render(Rectangle rec);


};




// pushbutton vs togglebutton
// class ToggleButton : public Button {};
// class RadioButton : public Button {};
