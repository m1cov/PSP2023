#include <iostream>
#include <string.h>
using namespace std;

class Ucenik
{

private:
    char *ime;
    float prosek;
    int godina;

public:
    Ucenik(char *i = "", float p = 1.0, int g = 1)
    {

        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
        prosek = p >= 1.0 && p <= 5.0 ? p : 0;
        godina = g >= 1 && g <= 4 ? g : 0;
    }

    ~Ucenik() { delete[] ime; }

    Ucenik(const Ucenik &u)
    {

        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);

        godina = u.godina;
        prosek = u.prosek;
    }

    Ucenik &operator=(const Ucenik &u)
    {

        if (this == &u)
            return *this;

        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);

        godina = u.godina;
        prosek = u.prosek;

        return *this;
    }

    char *getIme() { return ime; }
    float getProsek() { return prosek; }
    int getGodina() { return godina; }

    void setIme(char *i)
    {

        delete[] ime;
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
    }

    inline void setProsek(float p) { prosek = p >= 1.0 && p <= 5.0 ? p : 0; }
    inline void setGodina(int g) { godina = g >= 1 && g <= 4 ? g : 0; }

    Ucenik &operator++()
    {

        godina++;

        if (godina > 4)
            godina = 4;
    }

    Ucenik &operator++(int)
    {

        Ucenik pom(*this);
        godina++;

        if (godina > 4)
            godina = 4;

        return pom;
    }

    friend ostream &operator<<(ostream &o, const Ucenik &u)
    {

        o << "Ime na ucenik: " << u.ime << "\nGodina: " << u.godina << "\nProksek: " << u.prosek;

        return o;
    }
};

class Paralelka
{

private:
    Ucenik *list;
    int n;

public:
    Paralelka(Ucenik *l = NULL, int d = 0)
    {

        n = d > 0 ? d : 0;
        list = new Ucenik[n];
        for (int i = 0; i < n; i++)
            list[i] = l[i];
    }

    Paralelka(const Paralelka &p)
    {

        n = p.n;
        list = new Ucenik[n];
        for (int i = 0; i < n; i++)
            list[i] = p.list[i];
    }

    Paralelka &operator=(const Paralelka &p)
    {

        if (this == &p)
            return *this;

        delete[] list;

        n = p.n;
        list = new Ucenik[n];
        for (int i = 0; i < n; i++)
            list[i] = p.list[i];

        return *this;
    }

    Paralelka &operator++()
    {

        for (int i = 0; i < n; i++)
            ++list[i];
    }

    Paralelka &operator+=(Ucenik &u)
    {

        Ucenik *pom = new Ucenik[n + 1];

        for (int i = 0; i < n; i++)
        {
            pom[i] = list[i];
        }

        pom[n++] = u;

        delete[] list;
        list = new Ucenik[n];

        for (int i = 0; i < n; i++)
            list[i] = pom[i];

        delete[] pom;
    }

    friend ostream &operator<<(ostream &o, Paralelka &p)
    {

        for (int i = 0; i < p.n; i++)
            o << p.list[i] << endl;
    }
};

int main()
{

    return 0;
}