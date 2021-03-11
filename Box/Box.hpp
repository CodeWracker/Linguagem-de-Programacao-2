#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

using namespace std;
class Box
{
private:
    size_t m_width, m_height, m_depth;

public:
    Box(){};
    Box(size_t width, size_t height, size_t depth);

public:
    void SetDimensions(size_t width, size_t height, size_t depth);
    size_t GetWidth() const { return m_width; };
    size_t GetHight() const { return m_height; };
    size_t GetDepth() const { return m_depth; };
};

#endif