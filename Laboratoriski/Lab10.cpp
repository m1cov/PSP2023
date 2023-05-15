#include <iostream>
#include <string.h>

using namespace std;

class Prostor
{

private:
    char *lokacija;
    int kvadratura, cena;

public:
    Prostor(char *p = NULL, int k = 0, int c = 0)
    {

        lokacija = new char[strlen(p) + 1];
        for (int i = 0; i < strlen(p) + 1; i++)
        {
            lokacija[i] = p[i];
        }

        kvadratura = k > 0 ? k : 0;
        cena = c > 0 ? c : 0;
    }

    Prostor(const Prostor &p)
    {

        lokacija = new char[strlen(p.lokacija) + 1];
        for (int i = 0; i < strlen(p.lokacija) + 1; i++)
        {
            lokacija[i] = p.lokacija[i];
        }

        kvadratura = p.kvadratura;
        cena = p.cena;
    }

    int osnovnaCena()
    {
        return kvadratura * cena;
    }

    char *getLok() { return lokacija; }
    int getKvadratura() { return kvadratura; }
    virtual float getCena() { return cena; }

    void setLok(char *p = NULL)
    {
        lokacija = new char[strlen(p) + 1];
        for (int i = 0; i < strlen(p) + 1; i++)
        {
            lokacija[i] = p[i];
        }
    }
    void setCena(int c)
    {
        cena = c > 0 ? c : 0;
    }

    void setKvadratura(int k)
    {
        kvadratura = k > 0 ? k : 0;
    }

    virtual void pechati()
    {

        for (int i = 0; i < strlen(lokacija); i++)
        {
            cout << lokacija[i];
        }

        cout << endl;
        cout << kvadratura << cena << endl;
    }
};

class MaloprodazenProstor : public Prostor
{

private:
    int brendovi;

public:
    MaloprodazenProstor(int b = 0, char *p = NULL, int k = 0, int c = 0) : Prostor(p, k, c)
    {

        brendovi = b > 0 ? b : 0;
    }

    MaloprodazenProstor(const MaloprodazenProstor &m, const Prostor &p) : Prostor(p)
    {
        brendovi = m.brendovi;
    }

    MaloprodazenProstor &operator=(MaloprodazenProstor &s)
    {

        brendovi = s.brendovi;
        setCena(s.getCena());
        setLok(s.getLok());
        setKvadratura(s.getKvadratura());

        return *this;
    }

    float getCena()
    {
        return osnovnaCena() - osnovnaCena() * brendovi / 100;
    }

    void maloprodazenPechati()
    {

        pechati();
        cout << brendovi << endl;
    }
};

class StanbenProstor : Prostor
{

private:
    int mesta;

public:
    StanbenProstor(int m = 0, char *p = NULL, int k = 0, int c = 0) : Prostor(p, k, c)
    {

        mesta = m > 0 ? m : 0;
    }

    StanbenProstor(const StanbenProstor &s, const Prostor &p) : Prostor(p)
    {
        mesta = s.mesta;
    }

    StanbenProstor &operator=(StanbenProstor &s)
    {

        mesta = s.mesta;
        setCena(s.getCena());
        setLok(s.getLok());
        setKvadratura(s.getKvadratura());

        return *this;
    }

    float getCena() { return osnovnaCena() + 5000 * mesta; }

    void stanbenPechati()
    {

        pechati();
        cout << mesta << endl;
    }
};

void najevtin(Prostor *p, int br)
{

    int najevtin = p[0].getCena();
    int poz = 0;

    for (int i = 0; i < br; i++)
    {
        if (p[i].getCena() < najevtin)
        {
            poz = i;
            najevtin = p[i].getCena();
        }
    }

    p[poz].pechati();
}

int main()
{

    StanbenProstor *s = new StanbenProstor[4];
    MaloprodazenProstor *m = new MaloprodazenProstor[4];

    Prostor *p = new Prostor[8];

    // Sto kur ste pravele ednas me nemase

    return 0;
}