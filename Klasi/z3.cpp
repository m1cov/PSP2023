#include <iostream>
#include <string.h>

using namespace std;

class Proizvod
{

private:
    char ime[20];
    int sifra, zaliha, prodadeno;

public:
    Proizvod(char *i = "", int s = 0, int z = 0, int p = 0)
    {

        strncpy(ime, i, 19);
        ime[19] = '\0';

        if (s >= 0)
            sifra = s;

        zaliha = z >= 0 ? z : 0;
        prodadeno = p >= 0 ? p : 0;
    }

    char *getIme() { return ime; }
    int getSifra() { return sifra; }
    int getZaliha() { return zaliha; }
    int getProdadeno() { return prodadeno; }
};

class Magacin
{

private:
    Proizvod list[100];
    int n;

public:
    Magacin(Proizvod *l = NULL, int d = 0)
    {

        n = d >= 0 ? d : 0;

        for (int i = 0; i < n; i++)
        {
            list[i] = l[i];
        }
    }

    void sort(bool nasoka = false, int k = 1)
    {

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int v1, v2;

                if (k == 0)
                {

                    v1 = list[i].getSifra();
                    v2 = list[j].getSifra();
                }
                else if (k == 1)
                {
                    v1 = list[i].getZaliha();
                    v2 = list[j].getZaliha();
                }
                else if (k == 2)
                {
                    v1 = list[i].getProdadeno();
                    v2 = list[j].getProdadeno();
                }

                if ((nasoka && v2 < v1) || (!nasoka && v2 > v1))
                {

                    Proizvod pom = list[i];
                    list[i] = list[j];
                    list[j] = pom;
                }
            }
        }
    }
};