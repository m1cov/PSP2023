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
};