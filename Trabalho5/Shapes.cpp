#include "Shapes.hpp"
#include <math.h>
size_t getDistance(Point2d a, Point2d b)
{
    int dif1 = pow(a.m_x - b.m_x, 2);
    int dif2 = pow(a.m_y - b.m_y, 2);
    return sqrt(dif1 + dif2);
}
size_t getDistance(Point3d a, Point3d b)
{
    int dif1 = pow(a.m_x - b.m_x, 2);
    int dif2 = pow(a.m_y - b.m_y, 2);
    int dif3 = pow(a.m_z - b.m_z, 2);
    return sqrt(dif1 + dif2);
}