#include <iostream>

using namespace std;

class Tip
{
private:
    string ime1, ime2;
    int tip;
    float koeficient;

public:
    friend Livce;

    Tip(string i1 = "", string i2 = "", int t, float k)
    {

        ime1 = i1;
        ime2 = i2;

        tip = t >= 0 && tip <= 2 ? tip : 0;
        koeficient = k > 0 ? k : 0;
    }

    void pechati()
    {

        cout << ime1 << ime2 << tip << koeficient << endl;
    }
};

class Livce
{
private:
    int br;
    Tip *list;

public:
    Livce(int n = 0, Tip *l = NULL)
    {

        br = n > 0 ? n : 0;
        list = new Tip[br];

        for (int i = 0; i < br; i++)
            list[i] = l[i];
    }

    ~Livce()
    {

        delete[] list;
    }

    friend ostream &operator>>(ostream &o, const Livce &l)
    {

        for (int i = 0; i < l.br; i++)
        {
            l.list[i].pechati();
        }
    }

    Livce &operator=(const Livce &l)
    {

        br = l.br;
        for (int i = 0; i < br; i++)
            list[i] = l.list[i];
    }

    bool &operator>(const Livce &l)
    {

        bool pogolem = true;
        float koef1 = 1, koef2 = 1;

        for (int i = 0; i < br; i++)
        {
            koef1 *= list[i].koeficient;
        }

        for (int i = 0; i < l.br; i++)
        {
            koef2 *= l.list[i].koeficient;
        }

        if (koef2 > koef1)
            pogolem = false;

        return pogolem;
    }

    Livce &operator+=(const Tip &t)
    {

        Tip *pom = new Tip[br + 1];

        for (int i = 0; i < br; i++)
            pom[i] = list[i];

        pom[++br] = t;

        delete[] list;
        list = new Tip[br];

        for (int i = 0; i < br; i++)
        {
            list[i] = pom[i];
        }

        delete[] pom;
    }

    Livce &operator--()
    {

        Tip *pom = new Tip[--br];

        for (int i = 0; i < br; i++)
        {
            pom[i] = list[i];
        }

        delete[] list;
        list = new Tip[br];

        for (int i = 0; i < br; i++)
            list[i] = pom[i];

        delete[] pom;
    }
};

int main()
{
}