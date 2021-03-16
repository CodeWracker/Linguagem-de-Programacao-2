#ifndef SHAPES_HPP
#define SHAPES_HPP

#define NDEBUG 1
class Point2d
{
public:
    float m_x, m_y;
    Point2d(float x, float y) : m_x(x), m_y(y){};
};
class Point3d
{
public:
    float m_x, m_y, m_z;
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z){};
};

class Circle
{
private:
    size_t m_ratio;

public:
    Circle(){};
    Circle(size_t r) : m_ratio(r){};
    size_t CalcArea();
};
class Square
{
private:
    size_t m_edge;

public:
    Square(){};
    Square(size_t e) : m_edge(e){};
    size_t CalcArea();
};
class Triangle
{
private:
    Point2d m_p1, m_p2, m_p3;
    size_t m_e1, m_e2, m_e3;

public:
    Triangle(){};
    Triangle(Point2d p1, Point2d p2, Point2d p3) : m_p1(p1), m_p2(p1), m_p3(p3){};
    Triangle(size_t e1, size_t e2, size_t e3) : m_e1(e1), m_e2(e1), m_e3(e3){};
    size_t CalcArea();
};
class Sphere
{
private:
    size_t m_ratio;

public:
    Sphere(){};
    Sphere(size_t r) : m_ratio(r){};
    size_t CalcArea();
};

class Tetrahedron
{
private:
    Point3d m_p1, m_p2, m_p3, m_p4;

public:
    Tetrahedron(){};
    Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4) : m_p1(p1), m_p2(p2), m_p3(p3), m_p4(p4){};
    size_t CalcArea();
};
class Cube
{
private:
    size_t m_edge;

public:
    Cube(){};
    Cube(size_t r) : m_edge(r){};
    size_t CalcArea();
};

#endif