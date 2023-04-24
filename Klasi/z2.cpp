#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Let
{

private:
    int sifra;
    char poletuvanje[30];
    char sletuvanje[30];
    int pilot;

public:
    Let(int s = 0, char *g1 = "", char *g2 = "", int p = 0)
    {

        strncpy(poletuvanje, g1, 29);
        strncpy(sletuvanje, g2, 29);

        poletuvanje[29] = '\0';
        sletuvanje[29] = '\0';
        sifra = s > 0 ? s : 0;
        pilot = p > 0 ? p : 0;
    }

    void pechati()
    {

        cout << sifra << ": " << poletuvanje << sletuvanje << endl;
    }

    int getPilot()
    {
        return pilot;
    }
};

class Pilot
{

private:
    int sifra;
    char ime[30];
    float plata;

public:
    Pilot(char *i = "", int s = 0, float p = 0.0)
    {

        strncpy(ime, i, 29);
        ime[29] = '\0';

        sifra = s > 0 ? s : 0;
        plata = p > 0 ? p : 0;
    }

    int getSifra()
    {
        return sifra;
    }

    float getPlata()
    {
        return plata;
    }

    char *getIme()
    {
        return ime;
    }
};

class AvioKompanija
{

private:
    Let letovi[15];
    int br;
    char ime[30];

public:
    AvioKompanija(Let *l = NULL, int n = 0, char *i = "")
    {

        if (n >= 0)
            br = n;

        for (int i = 0; i < n; i++)
            letovi[i] = l[i];
    }

    int proveri(int sifra)
    {

        for (int i = 0; i < br; i++)
        {
            if (letovi[i].getPilot() == sifra)
                return i;
        }

        return -1;
    }

    void plata(Pilot *piloti, int n)
    {

        for (int i = 0; i < n; i++)
        {
            float plata = 0;

            for (int j = 0; j < n; j++)
            {
                if (letovi[j].getPilot() == piloti[i].getSifra())
                {

                    plata += piloti[i].getPlata();
                }
            }
        }
    }
};
