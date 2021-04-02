#include "choices.hpp"
#include "Utils.hpp"
void showData(Pessoa &mercador, Pessoa &heroi, vector<vector<vector<string>>> &monsterList)
{
    if (NDEBUG)
        system("clear");
    while (1)
    {

        if (NDEBUG)
            cout << heroi.str() << endl;

        if (NDEBUG)
            cout << "Deseja equipar algum item? (S/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "n" || choice == "N")
            break;
        if (choice == "s" || choice == "S")
        {

            if (NDEBUG)
                cout << "Que item quer Equipar ou usar?" << endl;
            cin >> choice;
            int c = atoi(choice.c_str());
            if (NDEBUG)
                system("clear");
            heroi >> (c);
        }
    }
}
void upgradeStatus(Pessoa &mercador, Pessoa &heroi, vector<vector<vector<string>>> &monsterList)
{
    if (NDEBUG)
        system("clear");
    while (1)
    {

        if (NDEBUG)
            cout << "Seus Atributos: " << heroi.showStats() << endl;
        if (heroi.getPontos() > 0)
        {

            if (NDEBUG)
                cout << "Pontos Disponiveis: " << heroi.getPontos() << endl;
            string choice1;
            string choice2;
            string atr;

            if (NDEBUG)
                cout << "Adicionar Pontos em:" << endl;

            if (NDEBUG)
                cout << "1 - FOR" << endl;

            if (NDEBUG)
                cout << "2 - CON" << endl;

            if (NDEBUG)
                cout << "3 - DEX" << endl;

            if (NDEBUG)
                cout << "4 - Voltar para o Menu" << endl;
            cin >> choice1;
            if (choice1 == "4")
                break;

            if (NDEBUG)
                cout << "Quantos pontos deseja adicionar? " << endl;
            cin >> choice2;
            if (choice1 == "1")
                atr = "for";
            if (choice1 == "2")
                atr = "con";
            if (choice1 == "3")
                atr = "dex";

            if (!heroi.upar(atr, atoi(choice2.c_str())))

                if (NDEBUG)
                    cout << "QUANTIDADE DE PONTOS INVALIDA" << endl;
        }
        else
        {

            if (NDEBUG)
                cout << "Você não possui pontos disponiveis, vá caçar!" << endl;
            break;
        }
    }
}
bool storeTransaction(Pessoa &comprador, Pessoa &vendedor)
{
    string choice;

    if (NDEBUG)
        cout << vendedor.bagToStr() << endl;

    if (NDEBUG)
        cout << "Escolha o item (PARA VOLTAR DIGITE B)" << endl;
    cin >> choice;
    if (NDEBUG)
        system("clear");
    if (choice == "b" || choice == "B")
        return false;
    GenericItem *i = vendedor.pop_bag(atoi(choice.c_str()));
    if (i == nullptr)
    {
        if (NDEBUG)
            cout << "Item invalido!" << endl;
    }
    else
    {
        if (comprador.gastar(i->getValue()))
        {
            comprador.push_bag(i);
            vendedor.depositar(i->getValue());
            *i << (1);
        }
        else
        {

            if (NDEBUG)
                cout << "Sem Dinheiro, sem item! Devolve isso ai *****!!" << endl;
            vendedor.push_bag(i);
        }
    }
    return true;
}
void openStore(Pessoa &mercador, Pessoa &heroi, vector<vector<vector<string>>> &monsterList)
{
    if (NDEBUG)
        system("clear");
    while (1)
    {

        if (NDEBUG)
            cout << "Você possui " << heroi.getDinheiro() << "PP" << endl;
        string choice;

        if (NDEBUG)
            cout << "Quer (C)omprar ou (V)ender? (PARA SAIR DIGITE S)" << endl;
        cin >> choice;
        if (NDEBUG)
            system("clear");
        if (choice == "s" || choice == "S")
            break;

        if (choice == "c" || choice == "C")
        {
            while (1)
            {
                if (!storeTransaction(heroi, mercador))
                    break;
            }
        }
        if (choice == "v" || choice == "V")
        {
            while (1)
            {
                if (!storeTransaction(mercador, heroi))
                    break;
            }
        }
    }
}
void hunt(Pessoa &mercador, Pessoa &heroi, vector<vector<vector<string>>> &monsterList)
{

    int num = rand() % (monsterList.size());
    Monstro *m = createMonster(monsterList.at(num), heroi.getNivel());

    if (NDEBUG)
        cout << "Não se esqueça que cansaço mata" << endl;
    while (m->isAlive() && heroi.isAlive())
    {
        if (NDEBUG && heroi.isAlive())
            cout << heroi.resumo() << endl;
        if (NDEBUG)
            cout << m->str() << endl;

        if (NDEBUG)
            cout << "0 - Atacar" << endl;

        if (NDEBUG)
            cout << "1 - Fugir" << endl;

        if (NDEBUG)
            cout << "Escolha" << endl;
        bool aux = true;
        string c;
        cin >> c;
        if (c == "0")
        {
            if (heroi.atacar(m))

            {
                if (NDEBUG)
                    cout << "Voce acertou o Golpe!" << endl;
            }
            else
            {
                if (NDEBUG)
                    cout << "Voce errou o Golpe!" << endl;
            }
        }
        if (c == "1")
        {
            if (heroi.fugir(m))
            {

                if (NDEBUG)
                    cout << "Voce conseguiu fugir!" << endl;
                break;
            }
            else
            {

                if (NDEBUG)
                    cout << "Voce nao conseguiu fugir e ele te atacou!" << endl;
                if (!m->atacar(&heroi))
                {

                    if (NDEBUG)
                        cout << "ele errou o ataque" << endl;
                    aux = false;
                }
            }
        }
        if (aux && m->isAlive())
        {

            if (NDEBUG)
                cout << "Vez do bixo!!" << endl;
            if (m->atacar(&heroi))

            {
                if (NDEBUG)
                    cout << "ele acertou o ataque" << endl;
            }
            else
            {
                if (NDEBUG)
                    cout << "ele errou o ataque" << endl;
            }
        }
    }
    if (NDEBUG)
        system("clear");
    if (!m->isAlive())
    {

        if (NDEBUG)
            cout << "Voce matou ele!" << endl;
        heroi.push_bag(new GenericItem(m->getDrop()));
        heroi + m->getXp();
    }
    delete m;
}