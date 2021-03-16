#include "Shapes.hpp"
#include <math.h>
const long double pi = acos(-1.L);
float getDistance(Point2d a, Point2d b)
{
    int dif1 = pow(a.m_x - b.m_x, 2);
    int dif2 = pow(a.m_y - b.m_y, 2);
    return sqrt(dif1 + dif2);
}
float getDistance(Point3d a, Point3d b)
{
    int dif1 = pow(a.m_x - b.m_x, 2);
    int dif2 = pow(a.m_y - b.m_y, 2);
    int dif3 = pow(a.m_z - b.m_z, 2);
    return sqrt(dif1 + dif2);
}
Triangle::Triangle(Point2d p1, Point2d p2, Point2d p3)
{
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
    m_e1 = getDistance(p1, p2);
    m_e2 = getDistance(p1, p3);
    m_e3 = getDistance(p2, p3);
}
float Circle::CalcArea() { return pi * pow(m_ratio, 2); }
float Square::CalcArea() { return pow(m_edge, 2); }
float Triangle::CalcArea() { return m_e1; }
float Sphere::CalcArea() { return 4 * pi * pow(m_ratio, 2); }
float Tetrahedron::CalcArea() { return 1; }
float Cube::CalcArea() { return 6 * pow(m_edge, 2); }