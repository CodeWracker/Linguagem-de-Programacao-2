#include "Box.hpp"

void Box::SetDimensions(size_t width, size_t height, size_t depth)
{
    m_width = width;
    m_height = height;
    m_depth = depth;
}

Box::Box(size_t width, size_t height, size_t depth)
{
    this->SetDimensions(width, height, depth);
}