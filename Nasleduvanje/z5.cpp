#include <iostream>

using namespace std;

class izvidnik
{

private:
    string ime, prezime;
    int god;

public:
    izvidnik(string i = "", string p = "", int g = 0)
    {

        ime = i;
        prezime = p;
        god = g;
    }

    int get_god() { return god; }
    string getIme() { return ime; }
    string getPrezime() { return prezime; }
};

class drustvo
{

private:
    string ime, oblast;
    int n;
    izvidnik *list;

public:
    drustvo(string i = "", string o = "", int br = 0, izvidnik *l = NULL)
    {

        ime = i;
        oblast = o;
        n = br;

        list = new izvidnik[n];
        for (int i = 0; i < n; i++)
        {
            list[i] = l[i];
        }
    }

    drustvo(const drustvo &d)
    {

        ime = d.ime;
        oblast = d.oblast;
        n = d.n;
        list = new izvidnik[n];

        for (int i = 0; i < n; i++)
        {
            list[i] = d.list[i];
        }
    }

    int max_god_iskustvo()
    {

        int g = list[0].get_god();

        for (int i = 0; i < n; i++)
        {
            if (list[i].get_god() > g)
                g = list[i].get_god();
        }

        return g;
    }

    drustvo &operator+=(izvidnik &t)
    {

        izvidnik *pom = new izvidnik[n + 1];

        for (int i = 0; i < n; i++)
        {
            pom[i] = list[i];
        }

        pom[n++] = t;

        delete[] list;
        list = new izvidnik[n];

        for (int i = 0; i < n; i++)
        {
            list[i] = pom[i];
        }

        delete[] pom;
    }

    friend drustvo &operator+(const drustvo &a, const drustvo &b)
    {

        drustvo d;

        for (int i = 0; i < a.n; i++)
        {
            d += a.list[i];
        }

        for (int i = 0; i < b.n; i++)
        {
            d += b.list[i];
        }

        return d;
    }

    drustvo &operator--()
    {
        int mini = 0;

        for (int i = 0; i < n; i++)
        {
            if (list[i].get_god() < list[mini].get_god())
            {

                mini = i;
            }
        }

        izvidnik *pom = new izvidnik[n - 1];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != mini)
                pom[j++] = list[i];
        }

        delete[] list;
        list = new izvidnik[--n];

        for (int i = 0; i < n; i++)
        {
            list[i] = pom[i];
        }

        delete[] pom;

        return *this;
    }

    friend ostream &operator<<(ostream &o, const drustvo &p)
    {

        o << p.ime << p.n << p.oblast << endl;

        for (int i = 0; i < p.n; i++)
        {
            o << p.list[i].get_god() << p.list[i].getIme() << p.list[i].getPrezime() << endl;
        }
    }
};
