#include <iostream>

using namespace std;

class PrevoznoSredstvo
{
protected:
    int tezina;
    float kgpot, potrosuvacka;

public:
    PrevoznoSredstvo(int t = 0, int p = 0)
    {

        tezina = t > 0 ? t : 0;
        kgpot = p > 0 ? p : 0;
    }

    float getPotrosuvacka()
    {
        return potrosuvacka;
    }

    ~PrevoznoSredstvo()
    {
        delete this;
    }

    virtual void presmetajPotrosuvacka()
    {

        potrosuvacka = kgpot * tezina;
    }
};

class Avion : public PrevoznoSredstvo
{

private:
    int tip;

public:
    Avion(int t = 0, int p = 0, int ti = 0) : PrevoznoSredstvo(t, p)
    {

        tip = ti >= 0 && ti <= 1 ? ti : 0;
        presmetajPotrosuvacka();
    }

    ~Avion()
    {

        delete this;
    }

    void presmetajPotrosuvacka()
    {

        if (tip == 0)
            kgpot *= 1.3;

        PrevoznoSredstvo::presmetajPotrosuvacka();
    }
};

class Voz : public PrevoznoSredstvo
{

private:
    int *vagoni;
    int dolzina;

public:
    Voz(int t = 0, int p = 0, int *v = NULL, int d) : PrevoznoSredstvo(t, p)
    {
        dolzina = d > 0 && d <= 10 ? d : 0;
        vagoni = new int[dolzina];

        for (int i = 0; i < dolzina; i++)
        {
            tezina += vagoni[i];
        }

        presmetajPotrosuvacka();
    }

    ~Voz()
    {
        delete this;
    }

    void presmetajPotrosuvacka()
    {

        potrosuvacka = kgpot * tezina;
    }
};

int pomalaPotrosuvacka(PrevoznoSredstvo *l1, PrevoznoSredstvo *l2)
{

    if (l1->getPotrosuvacka() < l2->getPotrosuvacka())
        return 1;

    return 0;
}

int najmalaPotrosuvacka(PrevoznoSredstvo *l)
{

    int poz = 0;
    float najmalo = l[0].getPotrosuvacka();
    PrevoznoSredstvo *temp;

    while (temp != NULL)
    {

        if (temp->getPotrosuvacka() < najmalo)
        {

            poz++;
            najmalo = temp->getPotrosuvacka();
        }

        temp = l++;
    }

    return poz;
}

int main()
{

    return 0;
}