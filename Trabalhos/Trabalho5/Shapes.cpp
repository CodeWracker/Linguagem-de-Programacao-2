#include "Shapes.hpp"
#include <math.h>
const long double pi = acos(-1.L);
float getDistance(Point2d a, Point2d b)
{
    float dif1 = pow(a.m_x - b.m_x, 2);
    float dif2 = pow(a.m_y - b.m_y, 2);
    return sqrt(dif1 + dif2);
}
float getDistance(Point3d a, Point3d b)
{
    float dif1 = pow(a.m_x - b.m_x, 2);
    float dif2 = pow(a.m_y - b.m_y, 2);
    float dif3 = pow(a.m_z - b.m_z, 2);
    return sqrt(dif1 + dif2 + dif3);
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
Tetrahedron::Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4)
{
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
    m_p4 = p4;
    m_a = getDistance(p1, p4);
    m_b = getDistance(p1, p2);
    m_c = getDistance(p4, p2);
    m_d = getDistance(p3, p2);
    m_e = getDistance(p1, p3);
    m_f = getDistance(p3, p4);
}
float triangleArea(float e1, float e2, float e3)
{
    float p = (e1 + e2 + e3) / 2;
    return sqrt(p * (p - e1) * (p - e2) * (p - e3));
}
float Circle::CalcArea() { return pi * pow(m_ratio, 2); }
float Square::CalcArea() { return pow(m_edge, 2); }
float Triangle::CalcArea()
{
    return triangleArea(m_e1, m_e2, m_e3);
}
float Sphere::CalcArea() { return 4 * pi * pow(m_ratio, 2); }
float Tetrahedron::CalcArea()
{
    float area1 = triangleArea(m_a, m_f, m_e);
    float area2 = triangleArea(m_e, m_d, m_b);
    float area3 = triangleArea(m_f, m_d, m_c);
    float area4 = triangleArea(m_a, m_c, m_b);
    //cout << area1 << " " << area2 << " " << area3 << " " << area4 << endl;
    return area1 + area2 + area3 + area4;
}
float Cube::CalcArea() { return 6 * pow(m_edge, 2); }