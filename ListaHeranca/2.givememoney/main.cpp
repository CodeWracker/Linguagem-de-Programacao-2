#include "Employee.hpp"
#include <vector>
int main()
{
    vector<Empregado> emps;
    Empregado e1;
    emps.push_back(e1);
    Empregado e2(2);
    emps.push_back(e2);
    Empregado e3("Rodrigo");

    emps.push_back(e3);
    Empregado e4("Rodrigo", 200);
    emps.push_back(e4);

    vector<Gerente> gns;
    Gerente g1;
    Gerente g2(2);
    Gerente g3("Carlos");
    Gerente g4("Carlos", 2);
    Gerente g5("Carlos", 2, "Administração");
    Gerente g6;
    g6.setNome("Antonio");
    g6.setSalario(234);
    gns.push_back(g1);
    gns.push_back(g2);
    gns.push_back(g3);
    gns.push_back(g4);
    gns.push_back(g5);
    gns.push_back(g6);
    for (Gerente g : gns)
        cout << g.toString(3) << endl;

    vector<Vendedor> vns;
    Vendedor v1;
    Vendedor v2(2);
    Vendedor v3("Yabe");
    Vendedor v4("Yabe", 2);
    Vendedor v5("Yabe", 2, 35.2);
    Vendedor v6;
    vns.push_back(v1);
    vns.push_back(v2);
    vns.push_back(v3);
    vns.push_back(v4);
    vns.push_back(v5);
    v6.setComissao(12);
    vns.push_back(v6);
    emps.push_back(v3);

    for (Vendedor v : vns)
        cout << v.toString(4) << endl;

    for (Empregado e : emps)
        cout << e.toString() << endl;
    return 0;
}