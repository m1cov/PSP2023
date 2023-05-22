#include <iostream>
#include <string.h>
using namespace std;

class Registracija
{

private:
    string ime;
    int brSasija, volume, brZemji;
    float cena;
    char **list;

public:
    Registracija(string i = "", int s = 0, int v = 0, float c = 0, int z = 0, char **l = NULL)
    {

        ime = i;
        brSasija = s;
        volume = v > 0 ? v : 0;
        cena = c > 0 ? c : 0;
        brZemji = z > 0 ? z : 0;

        list = new char *[brZemji];
        for (int i = 0; i < brZemji; i++)
        {
            list[i] = new char[strlen(l[i]) + 1];
            strcpy(list[i], l[i]);
        }
    }

    Registracija(const Registracija &r)
    {

        ime = r.ime;
        brSasija = r.brSasija;
        volume = r.volume;
        cena = r.cena;
        brZemji = r.brZemji;

        list = new char *[brZemji];
        for (int i = 0; i < brZemji; i++)
        {
            list[i] = new char[strlen(r.list[i]) + 1];
            strcpy(list[i], r.list[i]);
        }
    }

    ~Registracija()
    {

        for (int i = 0; i < brZemji; i++)
        {
            delete[] list[i];
        }

        delete[] list;
    }

    Registracija &operator=(const Registracija &r)
    {

        if (this == &r)
            return *this;

        for (int i = 0; i < brZemji; i++)
        {
            delete[] list[i];
        }

        delete[] list;

        ime = r.ime;
        brSasija = r.brSasija;
        volume = r.volume;
        cena = r.cena;
        brZemji = r.brZemji;

        list = new char *[brZemji];
        for (int i = 0; i < brZemji; i++)
        {
            list[i] = new char[strlen(r.list[i]) + 1];
            strcpy(list[i], r.list[i]);
        }

        return *this;
    }

    virtual float Iznos() { return cena; }
    int getMotor() { return volume; }

    void pechati()
    {
        cout << ime << brSasija << volume << cena << endl;

        for (int i = 0; i < brZemji; i++)
        {
            for (int j = 0; j < strlen(list[i]); j++)
            {

                // cout << list[i] << endl
                cout << list[i][j] << endl;
            }
        }
    }
};

class Reg_avto : public Registracija
{
private:
    bool nezgoda;

public:
    Reg_avto(string i = "", int s = 0, int v = 0, float c = 0.0, int z, char **l, bool n = false) : Registracija(i, s, v, c, z, l)
    {

        nezgoda = n;
    }

    float Iznos()
    {
        float c = Registracija::Iznos();

        if (getMotor() > 2000)
            c = c * 1.1;

        if (!nezgoda)
            c = c * 0.95;

        return c;
    }
};

class Reg_kamion : public Registracija
{

private:
    int starost;

public:
    Reg_kamion(string i = "", int s = 0, int v = 0, float c = 0.0, int z, char **l, int star = 0) : Registracija(i, s, v, c, z, l)
    {
        starost = star > 0 ? s : 0;
    }

    float Iznos()
    {

        float c = Registracija::Iznos();
        int godini = starost / 12;
        float procenti = (godini / 6) * 4;

        c = c * (1 + (float)procenti / 100);
        return c;
    }
};

float vkupno(Registracija **list, int n)
{

    float c = 0.0;

    for (int i = 0; i < n; i++)
    {
        c += list[i]->Iznos();
    }

    return c;
}

Registracija *sporedi_min(Registracija *r1, Registracija *r2)
{

    if (r1->Iznos() < r2->Iznos())
        return r1;

    return r2;
}

void najmalku(Registracija **list, int n)
{

    Registracija *min = list[0];

    for (int i = 0; i < n; i++)
    {
        if (list[i]->Iznos() < min->Iznos())
            min = list[i];
    }

    min->pechati();
}

int main()
{
}