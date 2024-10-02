#include <iostream>
#include <vector>

#include "ui.hh"



Component::Component(float x, float y)
: m_is_visible(true)
, m_x(x)
, m_y(y)
{
}

Component::~Component() {}

void Component::update() {
    if (m_is_visible)
        update_impl();
}
