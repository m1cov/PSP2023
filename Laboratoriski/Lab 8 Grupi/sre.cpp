#include <iostream>

using namespace std;

struct Sostojka
{
    string ime;
    int gramovi;
};

class Proizvod
{

private:
    string ime;
    int cena, sostojka;
    Sostojka *list = new Sostojka[0];

public:
    Proizvod()
    {

        ime = "Becutan krema za soncanje";
        cena = 318;
        sostojka = 4;
        list = new Sostojka[sostojka];

        list[0].ime = "Maslinovo maslo";
        list[0].gramovi = 20;

        list[1].gramovi = 10;
        list[1].ime = "Ekstrakt od kamilica";

        list[2].gramovi = 1;
        list[2].ime = "Vitamin E";

        list[3].gramovi = 20;
        list[3].ime = "De-pantenol";
    }

    ~Proizvod()
    {
        delete[] list;
    }

    Proizvod(Proizvod &p)
    {

        ime = p.ime;
        cena = p.cena;
        sostojka = p.sostojka;
        list = p.list;
    }

    Proizvod(string i, int c, int s, Sostojka *l)
    {

        ime = i;
        cena = c > 0 ? c : 0;
        sostojka = s > 0 ? s : 0;

        for (int i = 0; i < sostojka; i++)
            list[i] = l[i];
    }

    void pechati()
    {

        cout << ime << " " << cena << " " << sostojka << endl;

        for (int i = 0; i < sostojka; i++)
            cout << list[i].ime << " " << list[i].gramovi;
    }

    void dodadiSostojka(Sostojka &m)
    {
        Sostojka *temp = new Sostojka[sostojka + 1];
        temp[0] = m;

        for (int i = 0; i < sostojka; i++)
            temp[i + 1] = list[i];

        delete[] list;
        sostojka++;

        list = new Sostojka[sostojka];

        for (int i = 0; i < sostojka; i++)
            list[i] = temp[i];

        delete[] temp;
    }

    void brisiSostojka(Sostojka &m)
    {

        Sostojka *temp = new Sostojka[sostojka];
        bool najden = false;
        int j = 0;

        for (int i = 0; i < sostojka; i++)
        {
            if (list[i].gramovi == m.gramovi && list[i].ime == m.ime)
            {

                najden = true;
                continue;
            }

            temp[j++] = list[i];
        }

        delete[] list;
        list = najden ? new Sostojka[--sostojka] : new Sostojka[sostojka];

        for (int i = 0; i < sostojka; i++)
            list[i] = temp[i];

        delete[] temp;
    }
};

int main()
{
}