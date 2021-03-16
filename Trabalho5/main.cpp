#include "Shapes.hpp"
#include "Generic.hpp"
#include <vector>
#include <fstream>
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

    Point3d p4(-1, -1, -1), p5(5, 0, 3), p6(2.55, 4.1, 1.1), p7(3, 4.45, 1.4142);
    Tetrahedron tt1(p4, p5, p6, p7);
    myEls.push_back(tt1);

    Cube cb1(3);
    myEls.push_back(cb1);
    for (size_t i = 0; i < myEls.size(); i++)
    {
        cout << "Object #" << i << " is " << myEls.at(i).ShowInfo() << endl;
    }
    if (NDEBUG)
        cout << "NOME DO ARQUIVO PORRA: " << endl;
    string path;
    cin >> path;
    ifstream arq(path);
    string aux;
    myEls.clear();
    if (!arq.is_open())
    {
        cout << "Erro ao abrir" << endl;
        return 1;
    }
    while (arq >> aux)
    {
        if (aux == "circle")
        {
            arq >> aux;
            Circle circ(atof(aux.c_str()));
            myEls.push_back(circ);
            continue;
        }
        if (aux == "triagle")
        {
            continue;
        }
        if (aux == "sphere")
        {
            arq >> aux;
            Sphere sph(atof(aux.c_str()));
            myEls.push_back(sph);
            continue;
        }
        if (aux == "square")
        {
            arq >> aux;
            Square qua(atof(aux.c_str()));
            myEls.push_back(qua);
            continue;
        }
        if (aux == "tetrahedron")
        {
            continue;
        }
        if (aux == "cube")
        {
            arq >> aux;
            Cube cub(atof(aux.c_str()));
            myEls.push_back(cub);
        }
    }
    for (size_t i = 0; i < myEls.size(); i++)
    {
        cout << "Object #" << i << " is " << myEls.at(i).ShowInfo() << endl;
    }
    return 0;
}