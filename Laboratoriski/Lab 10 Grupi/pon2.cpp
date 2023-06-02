#include <iostream>
#include <string>

using namespace std;

class Film
{
protected:
    string naslov; // Sprored dadeniot kod treba da e char pretpostavuvam ama necu
    int gledaci, cena;
    float zarabotka;

public:
    Film(string i = "", int g = 0, int c = 0)
    {

        naslov = i;
        gledaci = g > 0 ? g : 0;
        cena = c > 0 ? c : 0;

        presmetajZarabotka();
    }

    // Samo go brise objektot cel
    ~Film()
    {

        delete this;
    }

    float getZarabotka() { return zarabotka; }

    // Virtual deka ke treba da se povika vo drugi klasi
    virtual void presmetajZarabotka()
    {

        zarabotka = cena * gledaci;
    }
};

class Komedija : public Film
{
private:
    bool dogovor;

public:
    Komedija(string i = "", int g = 0, int c = 0, bool d = false) : Film(i, g, c)
    {

        dogovor = d;
    }

    void presmetajZarabotka()
    {

        Film::presmetajZarabotka(); // Prvo ja presmetuva osnovnata zarabotka

        if (dogovor)
            zarabotka *= 0.85; // Ako ima  potpisano dogovor namaluva zarabotka za 15% (100% = 1 => 100% - 15% = 85% => .85)
    }
};

class Akcija : public Film
{

private:
    int opasni;

public:
    Akcija(string i = "", int g = 0, int c = 0, int o = 0) : Film(i, g, c)
    {

        opasni = o > 0 ? o : 0;
    }
    void presmetajZarabotka()
    {

        Film::presmetajZarabotka(); // Prvo ja presmetuva osnovnata zarabotka

        zarabotka *= 1.0 - (float)opasni / 100; // Za sekoja opasna scena namali zarabotka za 1%
    }
};

int najgolemaZarabotka(Film **l, int n)
{

    int poz = 0;

    for (int i = 0; i < n; i++)
    {

        if (l[i]->getZarabotka() > l[poz]->getZarabotka())
            poz = i;
    }

    return poz;
}

int vkupnaZarabotka(Film **l, int n)
{

    float vk = 0;

    for (int i = 0; i < n; i++)
        vk += l[i]->getZarabotka();

    return vk;
}

int main()
{
    Film *E[4];
    Komedija G1((char *)"Hangover", 100000, 5, false);
    Komedija G2((char *)"Borat", 90000, 5, true);
    Akcija K1((char *)"Mission impossible", 500000, 6, 20);
    Akcija K2((char *)"Avengers", 3500000, 4, 30);
    E[0] = &G1;
    E[1] = &G2;
    E[2] = &K1;
    E[3] = &K2;
    cout << "Najgolema zarabotka ima filmot so indeks " << najgolemaZarabotka(E, 4) << endl;
    cout << "Vkupnata zarabotka na studioto iznesuva " << vkupnaZarabotka(E, 4) << endl;
    return 0;
}