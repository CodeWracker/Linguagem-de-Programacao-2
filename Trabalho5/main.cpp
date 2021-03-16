#include "Shapes.hpp"
#include "Generic.hpp"
#include <vector>

int main()
{
    vector<GenericElement> myEls;
    Circle c1(2);
    myEls.push_back(c1);

    Square s1(2);
    myEls.push_back(s1);

    Triangle t1(3, 3, 3);
    myEls.push_back(t1);

    Point2d p1(0, 0), p2(1, 1), p3(2, 0);
    Triangle t2(p1, p2, p3);
    myEls.push_back(t2);

    Sphere sp1(5);
    myEls.push_back(sp1);

    Point3d p4(0, 0, 0), p5(0, 0, 1), p6(0, 1, 0), p7(1, 0, 0);
    Tetrahedron tt1(p4, p5, p6, p7);
    myEls.push_back(tt1);

    Cube cb1(3);
    myEls.push_back(cb1);
    for (size_t i = 0; i < myEls.size(); i++)
    {
        cout << "Object #" << i << " is " << myEls.at(i).ShowInfo() << endl;
    }
    return 0;
}