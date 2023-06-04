#include <iostream>
#include <string.h>

using namespace std;

class Chlen
{

protected:
    string ime, prezime;
    int maticen;
    char institut[7];
    int osnovnaPlata;
    string *predmeti;
    int brpredmeti;

public:
    Chlen(string i, string p, int m, char ins[], int os, string *pred, int br)
    {

        ime = i;
        prezime = p;
        maticen = m > 0 ? m : 0;

        for (int i = 0; i < strlen(ins) + 1; i++)
            institut[i] = ins[i];

        osnovnaPlata = os > 0 ? os : 0;
        brpredmeti = br > 0 ? br : 0;

        predmeti = new string[brpredmeti];
        for (int i = 0; i < brpredmeti; i++)
            predmeti[i] = pred[i];
    }

    virtual void presmetajPlata() {}

    int getBrPredmeti() { return brpredmeti; }

    char *getInstitut() { return institut; }

    int getPlata() { return osnovnaPlata; }

    string getPredmet(int i) { return predmeti[i]; }

    virtual void pechati()
    {

        cout << ime << prezime << maticen << osnovnaPlata;
        for (int i = 0; i < strlen(institut); i++)
            cout << institut[i];

        for (int i = 0; i < brpredmeti; i++)
            cout << predmeti[i] << '\t';
    }
};

class Profesor : public Chlen
{

private:
    int staz, trudovi;

public:
    Profesor(string i, string p, int m, char ins[], int os, string *pred, int br, int s, int t) : Chlen(i, p, m, ins, os, pred, br)
    {

        staz = s > 0 ? s : 0;
        trudovi = t > 0 ? t : 0;

        presmetajPlata();
    }

    void presmetajPlata()
    {

        osnovnaPlata *= 1.0 + (float)(staz * 5.0 / 100.0);
        osnovnaPlata *= 1.0 + (float)(trudovi * 2.0 / 100.0);
    }

    void pechati()
    {

        Chlen::pechati();
        cout << staz << trudovi;
    }
};

class Asistent : public Chlen
{
private:
    bool doktorski;

public:
    Asistent(string i, string p, int m, char ins[], int os, string *pred, int br, bool d) : Chlen(i, p, m, ins, os, pred, br)
    {

        doktorski = d;
        presmetajPlata();
    }

    void presmetajPlata()
    {

        if (doktorski)
            osnovnaPlata += 1000;
    }

    void pechati()
    {

        Chlen::pechati();
        cout << doktorski;
    }
};

void odgovoren(string pred, Chlen list[], int br)
{

    for (int i = 0; i < br; i++)
    {
        for (int j = 0; j < list[i].getBrPredmeti(); j++)
        {
            if (pred == list[i].getPredmet(j))
                list[i].pechati();
        }
    }
}

void najplatenInstitut(Chlen list[], int br, char ins[])
{

    int poz = 0;

    for (int i = 0; i < br; i++)
    {

        if (strcmp(list[i].getInstitut(), ins) == 0)
            if (list[i].getPlata() > list[poz].getPlata())
                poz = i;
    }

    list[poz].pechati();
}

int main()
{

    return 0;
}