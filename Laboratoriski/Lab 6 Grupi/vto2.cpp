#include <iostream>

using namespace std;

struct node
{

    int info;
    node *next, *prev;
};

struct DPKLista
{

    node *head, *tail;

    inline void init() { head = tail = NULL; }

    void createList(int x)
    {
    }

    void
    dodadiPrv(int x)
    {
    }

    void brisiPrv() {}

    void dodadiPos(int x)
    {
    }

    void brisiPos()
    {
    }

    void brisiLista()
    {
    }

    void pechati()
    {
    }
};

int generiraj(DPKLista l)
{
}

int main()
{
    DPKLista L1;

    L1.init();
    L1.dodadiPrv(-1);
    L1.dodadiPos(6);
    L1.dodadiPos(-4);
    L1.dodadiPos(-3);
    L1.dodadiPos(10);
    L1.dodadiPos(-4);
    L1.dodadiPos(5);
    int izlez = generiraj(L1);
    cout << "Sluchajno generiraniot broj e: " << izlez << endl;
    L1.pechati();
    L1.brisiLista();
    return 0;
}
