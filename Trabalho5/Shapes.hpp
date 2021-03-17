#ifndef SHAPES_HPP
#define SHAPES_HPP

#define NDEBUG 0

#include <iostream>
#include <string>

using namespace std;

class Point2d
{
public:
    float m_x, m_y;
    Point2d(){};
    Point2d(float x, float y) : m_x(x), m_y(y){};
};
class Point3d
{
public:
    float m_x, m_y, m_z;
    Point3d(){};
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z){};
};

class Circle
{
private:
    float m_ratio;

public:
    Circle(){};
    Circle(float r) : m_ratio(r){};
    float CalcArea();
};
class Square
{
private:
    float m_edge;

public:
    Square(){};
    Square(float e) : m_edge(e){};
    float CalcArea();
};
class Triangle
{
private:
    Point2d m_p1, m_p2, m_p3;
    float m_e1, m_e2, m_e3;

public:
    Triangle(){};
    Triangle(Point2d p1, Point2d p2, Point2d p3);
    Triangle(float e1, float e2, float e3) : m_e1(e1), m_e2(e2), m_e3(e3){};
    float CalcArea();
};
class Sphere
{
private:
    float m_ratio;

public:
    Sphere(){};
    Sphere(float r) : m_ratio(r){};
    float CalcArea();
};

class Tetrahedron
{
private:
    Point3d m_p1, m_p2, m_p3, m_p4;
    float m_a, m_b, m_c, m_d, m_e, m_f;

public:
    Tetrahedron(){};
    Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4);
    float CalcArea();
};
class Cube
{
private:
    float m_edge;

public:
    Cube(){};
    Cube(float r) : m_edge(r){};
    float CalcArea();
};

#endif