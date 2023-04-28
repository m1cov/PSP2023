#include <iostream>

using namespace std;

class Izvidnik
{

private:
    string ime, prezime;
    int god;

public:
    Izvidnik(string i = "", string p = "", int g = 0)
    {

        ime = i;
        prezime = p;
        god = g >= 0 ? g : 0;
    }

    inline int getGodini() { return god; }

    inline void pechati() { cout << ime << " " << prezime << " " << god; }
};

class Drustvo
{

private:
    string ime;
    string oblast;
    int br;
    Izvidnik *izvidnici;

public:
    Drustvo(string i = "", string o = "", int n = 0, Izvidnik *iz = NULL)
    {

        ime = i;
        oblast = o;
        br = n >= 0 ? n : 0;

        for (int i = 0; i < br; i++)
            izvidnici[i] = iz[i];
    }

    int max_godini_iskustvo()
    {

        int najgolem = 0;
        for (int i = 0; i < br; i++)
        {
            if (izvidnici[i].getGodini() > najgolem)
                najgolem = izvidnici[i].getGodini();
        }

        return najgolem;
    }

    void pechati()
    {

        cout << ime << " " << oblast << " " << br << endl;
        for (int i = 0; i < br; i++)
            izvidnici[i].pechati();
    }
};

int main()
{

    Izvidnik *list;
    Drustvo d;
    int br, god;
    string imed, imei, prezime, oblast;

    cout << "Vnesi ime na drustvoto, oblast i broj na izvidnici" << endl;
    cin >> imed >> oblast >> br;

    for (int i = 0; i < br; i++)
    {
        cout << "Vnesi ime, prezime i iskustvo na izvidnikot" << endl;
        cin >> imei >> prezime >> god;

        list[i] = Izvidnik(imei, prezime, god);
    }

    cout << 2;
    d = Drustvo(imed, oblast, br, list);

    cout << 3;

    d.pechati();

    cout << "Najiskusniot izvidnik ima " << d.max_godini_iskustvo() << " godini iskustvo" << endl;

    return 0;
}