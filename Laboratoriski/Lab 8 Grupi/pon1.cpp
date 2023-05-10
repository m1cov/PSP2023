#include <iostream>

using namespace std;

class Sostojka
{

private:
    string name;
    int tezina, cena;

public:
    Sostojka(string i = "", int t = 0, int c = 0)
    {

        name = i;
        tezina = t > 0 ? t : 0;
        cena = c > 0 ? c : 0;
    }

    inline int getCena() { return cena; }

    void pechati()
    {

        cout << name << " " << tezina << " " << cena << endl;
    }
};

class Pica
{
private:
    string ime;
    int br, cena;
    Sostojka *list = new Sostojka[0];

public:
    Pica()
    {

        ime = "Margarita";
        cena = 360;
        br = 4;

        list = new Sostojka[4];

        list[0] = Sostojka();
        list[1] = Sostojka();
        list[2] = Sostojka();
        list[3] = Sostojka();
    }

    Pica(string i, int n, Sostojka *l)
    {

        ime = i;

        br = n > 0 ? n : 0;

        list = new Sostojka[br];

        for (int i = 0; i < br; i++)
        {
            list[i] = l[i];
        }
    }

    Pica(const Pica &p)
    {

        ime = p.ime;
        cena = p.cena;
        br = p.br;

        list = new Sostojka[br];
        for (int i = 0; i < br; i++)
        {

            list[i] = p.list[i];
        }
    }

    ~Pica()
    {

        delete[] list;
    }

    void pechati()
    {

        cout << ime << " " << cena << " " << br << endl;
        for (int i = 0; i < br; i++)
        {
            list[i].pechati();
        }
    }

    void dodadiSostojka(Sostojka m)
    {

        Sostojka *t = new Sostojka[br + 1];

        for (int i = 0; i < br; i++)
        {
            t[i] = list[i];
        }

        t[++br] = m;
        delete[] list;
        list = new Sostojka[br];

        for (int i = 0; i < br; i++)
        {
            list[i] = t[i];
        }

        delete[] t;
    }

    void brisiSostojka(int poz)
    {

        Sostojka *t = new Sostojka[br];
        int j = 0;

        for (int i = 0; i < br; i++)
        {
            if (i != poz)
                t[j++] = list[i];
        }

        delete[] list;
        list = new Sostojka[--br];

        for (int i = 0; i < br; i++)
        {
            list[i] = t[i];
        }

        delete[] t;
    }
};

int main()
{

    Pica p = Pica();

    p.dodadiSostojka(Sostojka());
    p.pechati();

    p.brisiSostojka(2);
    p.pechati();

    return 0;
}