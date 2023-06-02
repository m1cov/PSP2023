#include <iostream>
#include <string.h>

using namespace std;

// Vo teorija raboti ama c++ nejke da konvertira string vo char * iako e istoto
// C++ ednostavno praynuva na nasiot downfall

class Sadnica
{

protected:
    char *ime;
    float cena;

public:
    Sadnica(char *i = "", float c = 0.0)
    {

        ime = new char[strlen(i) + 1];

        for (int j = 0; j < strlen(ime) + 1; j++)
            ime[j] = i[j];

        cena = c > 0 ? c : 0;
    }

    Sadnica(const Sadnica &s)
    {

        ime = new char[strlen(s.ime) + 1];

        for (int i = 0; i < strlen(ime) + 1; i++)
            ime[i] = s.ime[i];

        cena = s.cena;
    }

    Sadnica &operator=(const Sadnica &s)
    {

        if (this == &s)
            return *this;

        delete[] ime;

        ime = new char[strlen(s.ime) + 1];
        for (int i = 0; i < strlen(ime) + 1; i++)
            ime[i] = s.ime[i];

        cena = s.cena;

        return *this;
    }

    float getCena() { return cena; }

    virtual void pechati()
    {

        for (int i = 0; i < strlen(ime); i++)
        {
            cout << ime[i];
        }

        cout << cena << endl;
    };

    virtual void presmetaj_cena();
};

class Drvo : public Sadnica
{

private:
    int starost;

public:
    Drvo(char *i = "", float c = 0.0, int s = 0) : Sadnica(i, c)
    {

        starost = s > 0 ? s : 0;

        presmetaj_cena();
    }

    Drvo(const Drvo &s)
    {
        ime = new char[strlen(s.ime) + 1];

        for (int i = 0; i < strlen(ime) + 1; i++)
            ime[i] = s.ime[i];

        cena = s.cena;
        starost = s.starost;
    }

    Drvo &operator=(const Drvo &s)
    {

        if (this == &s)
            return *this;

        ime = new char[strlen(s.ime) + 1];

        for (int i = 0; i < strlen(ime) + 1; i++)
            ime[i] = s.ime[i];

        cena = s.cena;
        starost = s.starost;

        return *this;
    }

    void presmetaj_cena()
    {

        cena *= 1.0 + (float)(starost / 20);
    }

    void pechati()
    {

        Sadnica::pechati();
        cout << starost << endl;
    }
};

class Cvet : public Sadnica
{

private:
    int denovi;

public:
    Cvet(char *i = "", float c = 0.0, int d = 0) : Sadnica(i, c)
    {

        denovi = d > 0 ? d : 0;
    }

    Cvet(const Cvet &s)
    {

        ime = new char[strlen(s.ime) + 1];

        for (int i = 0; i < strlen(ime) + 1; i++)
            ime[i] = s.ime[i];

        cena = s.cena;
        denovi = s.denovi;
    }

    Cvet &operator=(const Cvet &s)
    {

        if (this == &s)
            return *this;

        ime = new char[strlen(s.ime) + 1];

        for (int i = 0; i < strlen(ime) + 1; i++)
            ime[i] = s.ime[i];

        cena = s.cena;
        denovi = s.denovi;

        return *this;
    }

    void presmetaj_cena()
    {

        if (denovi < 14)
            cena /= 2;
    }

    void pechati()
    {

        Sadnica::pechati();
        cout << denovi << endl;
    }
};

void fja(Sadnica **l, int n)
{

    Sadnica *najgolem = l[0];

    for (int i = 0; i < n; i++)
    {

        if (l[i]->getCena() > najgolem->getCena())
            najgolem = l[i];
    }

    najgolem->pechati();
}

int main()
{
    Sadnica *niza[20];
    Drvo m("Lipa", 400, 12);
    Cvet sl1("Lubicica", 300, 20), sl2("Krin", 400, 10);
    niza[0] = &m;
    niza[1] = &sl1;
    niza[2] = &sl2;
    fja(niza, 3);
    sl2 = sl1;
    sl2.pechati();

    return 0;
}