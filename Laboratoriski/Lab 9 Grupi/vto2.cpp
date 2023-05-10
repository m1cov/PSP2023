#include <iostream>

using namespace std;

struct Restoran
{

    string ime;
    int vraboteni;

    void pechati()
    {

        cout << ime << vraboteni << endl;
    }
};

class Lanec
{

private:
    string ime;
    int br;
    Restoran *list;

public:
    Lanec(string i = "", int n, Restoran *l = NULL)
    {

        ime = i;
        br = n > 0 ? n : 0;

        for (int i = 0; i < br; i++)
            list[i] = l[i];
    }

    ~Lanec()
    {
        delete[] list;
    }

    Lanec &operator+=(const Restoran &r)
    {

        Restoran *t = new Restoran[br + 1];

        for (int i = 0; i < br; i++)
            t[i] = list[i];

        t[br] = r;

        delete[] list;
        list = new Restoran[++br];

        for (int i = 0; i < br; i++)
            list[i] = t[i];

        delete[] t;
    }

    Lanec &operator-=(const Restoran &r)
    {

        Restoran *t = new Restoran[br + 1];
        t[0] = r;

        for (int i = 0; i < br; i++)
            t[i + 1] = list[i];

        delete[] list;
        list = new Restoran[++br];

        for (int i = 0; i < br; i++)
            list[i] = t[i];
    }

    Lanec &operator++()
    {

        Restoran *t = new Restoran[br - 1];

        for (int i = 0; i < br - 1; i++)
        {
            t[i] = list[i + 1];
        }

        delete[] list;
        list = new Restoran[--br];

        for (int i = 0; i < br; i++)
        {
            list[i] = t[i];
        }

        delete[] t;
    }

    Lanec &operator--()
    {

        Restoran *t = new Restoran[--br];

        for (int i = 0; i < br; i++)
        {
            t[i] = list[i];
        }

        delete[] list;
        list = new Restoran[br];

        for (int i = 0; i < br; i++)
        {
            list[i] = t[i];
        }
        delete[] t;
    }

    friend ostream &operator<<(ostream &o, const Lanec &l)
    {

        o << l.ime << l.br << endl;
        for (int i = 0; i < l.br; i++)
        {
            l.list[i].pechati();
        }
    }
};

int main()
{

    Lanec l = Lanec();

    --l;
    --l;

    l += Restoran();
    l -= Restoran();

    cout << l;

    return 0;
}