#include <iostream>

using namespace std;

struct Destinacii
{

    string grad;
    int vreme;
};

class Turi
{
private:
    string ime;
    int cena, br;
    Destinacii *list;

public:
    Turi(string i = "", int c = 0, int n = 0, Destinacii *l = NULL)
    {

        ime = i;
        cena = c > 0 ? c : 0;
        br = n > 0 ? n : 0;

        list = new Destinacii[br];
        for (int i = 0; i < br; i++)
            list[i] = l[i];
    }

    ~Turi()
    {
        delete[] list;
    }

    Turi &operator+=(const Destinacii &d)
    {

        Destinacii *t = new Destinacii[br + 1];
        t[0] = d;

        for (int i = 0; i < br; i++)
            t[i + 1] = list[i];

        delete[] list;
        list = new Destinacii[++br];

        for (int i = 0; i < br; i++)
            list[i] = t[i];

        delete[] t;
    }

    Turi &operator-=(const Destinacii &d)
    {

        Destinacii *t = new Destinacii[br + 1];
        for (int i = 0; i < br; i++)
            t[i] = list[i];

        t[br] = d;

        delete[] list;
        list = new Destinacii[++br];

        for (int i = 0; i < br; i++)
            list[i] = t[i];

        delete[] t;
    }

    Turi &operator++()
    {

        Destinacii *t = new Destinacii[br - 1];

        for (int i = 0; i < br - 1; i++)
        {
            t[i] = list[i + 1];
        }

        delete[] list;
        list = new Destinacii[--br];

        for (int i = 0; i < br; i++)
        {
            list[i] = t[i];
        }

        delete[] t;
    }

    Turi &operator--()
    {

        Destinacii *t = new Destinacii[--br];

        for (int i = 0; i < br; i++)
        {
            t[i] = list[i];
        }

        delete[] list;
        list = new Destinacii[br];

        for (int i = 0; i < br; i++)
            list[i] = t[i];

        delete[] t;
    }

    friend ostream &operator<<(ostream &o, const Turi &t)
    {

        o << t.ime << t.cena << t.br << endl;
        for (int i = 0; i < t.br; i++)
            o << t.list[i].grad << t.list[i].vreme << endl;
    }
};

int main()
{

    Turi t = Turi();

    t += Destinacii();
    t -= Destinacii();

    --t;
    ++t;
    cout << t;

    return 0;
}