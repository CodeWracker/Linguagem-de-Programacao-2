#include "Shapes.hpp"
#include "Generic.hpp"
#include <vector>
#include <fstream>

vector<string> splitString(string s, char it)
{
    string str;
    vector<string> ret;
    for (char c : s)
    {
        if (c == it)
        {
            ret.emplace_back(str);
            str.clear();
        }
        else
        {
            if (c != ' ')
                str = str + c;
        }
    }
    ret.emplace_back(str);
    return ret;
}

int main()
{

    
    vector<GenericElement *> myEls;

    if (NDEBUG)
        cout << "“Enter with a shape configuration file to load: " << endl;
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
    while (getline(arq, aux))
    {
        if (aux == "circle")
        {
            getline(arq, aux);
            Circle circ(atof(aux.c_str()));
            myEls.emplace_back(new GenericElement(circ));
            continue;
        }
        if (aux == "triangle")
        {
            getline(arq, aux);
            vector<string> dt = splitString(aux, ',');
            if (dt.size() == 3)
            {
                Triangle tri(atof(dt[0].c_str()), atof(dt[1].c_str()), atof(dt[2].c_str()));
                myEls.emplace_back(new GenericElement(tri));
                continue;
            }
            if (dt.size() == 2)
            {
                Point2d pt1(atof(dt[0].c_str()), atof(dt[1].c_str()));
                getline(arq, aux);
                dt = splitString(aux, ',');
                Point2d pt2(atof(dt[0].c_str()), atof(dt[1].c_str()));
                getline(arq, aux);
                dt = splitString(aux, ',');
                Point2d pt3(atof(dt[0].c_str()), atof(dt[1].c_str()));
                Triangle tri(pt1, pt2, pt3);
                myEls.emplace_back(new GenericElement(tri));
                continue;
            }
            if (dt.size() == 1)
            {
                float e1 = atof(aux.c_str());
                getline(arq, aux);
                float e2 = atof(aux.c_str());
                getline(arq, aux);
                float e3 = atof(aux.c_str());
                Triangle tri(e1, e2, e3);
                myEls.emplace_back(new GenericElement(tri));
                continue;
            }
        }
        if (aux == "sphere")
        {
            getline(arq, aux);
            Sphere sph(atof(aux.c_str()));
            myEls.emplace_back(new GenericElement(sph));
            continue;
        }
        if (aux == "square")
        {
            getline(arq, aux);
            Square qua(atof(aux.c_str()));
            myEls.emplace_back(new GenericElement(qua));
            continue;
        }
        if (aux == "tetrahedron")
        {
            getline(arq, aux);
            vector<string> dt = splitString(aux, ',');
            Point3d pt1(atof(dt[0].c_str()), atof(dt[1].c_str()), atof(dt[2].c_str()));

            getline(arq, aux);
            dt = splitString(aux, ',');
            Point3d pt2(atof(dt[0].c_str()), atof(dt[1].c_str()), atof(dt[2].c_str()));

            getline(arq, aux);
            dt = splitString(aux, ',');
            Point3d pt3(atof(dt[0].c_str()), atof(dt[1].c_str()), atof(dt[2].c_str()));

            getline(arq, aux);
            dt = splitString(aux, ',');
            Point3d pt4(atof(dt[0].c_str()), atof(dt[1].c_str()), atof(dt[2].c_str()));

            Tetrahedron tet(pt1, pt2, pt3, pt4);
            myEls.emplace_back(new GenericElement(tet));
            continue;
        }
        if (aux == "cube")
        {
            getline(arq, aux);
            Cube cub(atof(aux.c_str()));
            myEls.emplace_back(new GenericElement(cub));
        }
    }
    for (size_t i = 0; i < myEls.size(); i++)
    {
        cout << "Object #" << i << " is " << myEls.at(i)->ShowInfo() << endl;
        delete (myEls.at(i));
    }
    return 0;
}