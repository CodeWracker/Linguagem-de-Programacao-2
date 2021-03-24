#ifndef BOX_HPP
#define BOX_HPP
#include <iostream>
#include <string>
using namespace std;

class Box
{
protected:
    size_t m_width, m_height, m_depth;

public:
    Box() : m_width(0), m_height(0), m_depth(0)
    {
        cout << "Hello, Box Constructor" << endl;
    };
    ~Box()
    {
        cout << "Bye, Box Destructor" << endl;
    };
};

class CandyBox : public Box
{
private:
    string m_content;

public:
    CandyBox() : m_content("chocolates")
    {
        cout << "Hello, CandyBox Constructor" << endl;
    };
    ~CandyBox()
    {
        cout << "Bye, CandyBox Destructor" << endl;
    };
};
#endif