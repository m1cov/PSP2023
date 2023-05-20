#include <iostream>

using namespace std;

class polica
{
protected:
    string kod;
    int starost, cena;

public:
    polica(string k = "", int s = 0)
    {

        kod = k;
        starost = s > 0 ? s : 0;

        cena = vrednost();
    }

    virtual int vrednost()
    {

        return 6000 - (float)6000 * starost * 7 / 100;
    }

    virtual void pechati()
    {

        cout << kod << starost << endl;
    }
};

class kPolica : public polica
{

private:
    int brKnigi, tip;
    string *naslovi;

public:
    kPolica(string k = "", int s = 0, int br = 0, int t = 0, string *n = NULL) : polica(k, s)
    {

        brKnigi = br > 0 && br < 20 ? br : 0;
        tip = t == 0 || t == 1 ? t : 0;

        naslovi = new string[brKnigi];
        for (int i = 0; i < brKnigi; i++)
            naslovi[i] = n[i];
    }

    int vrednost()
    {

        int c = polica::vrednost();

        if (tip == 1)
            c *= 1.2;

        for (int i = 0; i < brKnigi; i++)
        {
            if (naslovi[i][1] == 'A' || naslovi[i][1] == 'U' || naslovi[i][1] == 'O' || naslovi[i][1] == 'I' || naslovi[i][1] == 'E')
                c += 200;
            else
                c += 300;
        }

        return c;
    }
    void pechati()
    {
        polica::pechati();

        cout << brKnigi << endl;
        for (int i = 0; i < brKnigi; i++)
        {
            cout << naslovi[i] << endl;
        }
    }
};

class aPolica : public polica
{
private:
    int brAlati;
    int *aCeni;

public:
    aPolica(string k = "", int s = 0, int br = 0, int *a = NULL) : polica(k, s)
    {

        brAlati = br > 0 && br < 10 ? br : 0;
        aCeni = new int[brAlati];

        for (int i = 0; i < brAlati; i++)
            aCeni[i] = a[i];
    }

    int vrednost()
    {

        int c = polica::vrednost();

        for (int i = 0; i < brAlati; i++)
            c += aCeni[i];

        return c;
    }

    void pechati()
    {
        polica::pechati();

        cout << brAlati << endl;
        for (int i = 0; i < brAlati; i++)
        {
            cout << aCeni[i] << endl;
        }
    }
};

// Von klasite func najvredna prima niza od pokazuvaci kon polici i niven broj, pecati podatoci za najvrednata i nejzinata vrednost
void najvredna(polica *list, int n)
{

    polica t = list[0];

    for (int i = 0; i < n; i++)
    {
        if (list[i].vrednost() > t.vrednost())
            t = list[i];
    }

    t.pechati();
    cout << t.vrednost();
}

// Globalna func vkvrednost prima niza pokazuvaci od tip polica i niven broj, vrakja vkupna vrednost na site polici
int vkvrednost(polica *list, int n)
{

    int vk = 0;

    for (int i = 0; i < n; i++)
    {
        vk += list[i].vrednost();
    }

    return vk;
}

int main()
{
}