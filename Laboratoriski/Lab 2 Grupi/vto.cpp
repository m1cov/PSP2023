#include <iostream>

using namespace std;

struct student
{

    string imes;
    string prezimes;
    int indeks[2];
    string predmets;

    void init(string i = "Petko", string p = "Petkovski", int br = 1, int god = 2023, string pr = "PSP")
    {

        imes = i;
        prezimes = p;
        indeks[0] = br;
        indeks[1] = god;
        predmets = pr;
    }

    void pechati()
    {

        cout << "Studentot " << imes << " " << prezimes << " so broj na indeks " << indeks[0] << "/" << indeks[1]
             << " ke go polaga predmetot " << predmets << endl;
    }
};

struct prostorija
{

    string imep;
    int rabmesta;
    student s[10];

    void init(string i, int rm, student *st)
    {
        imep = i;
        rabmesta = rm;

        for (int i = 0; i < rm; i++)
        {
            s[i] = st[i];
        }
    }

    void pechati(int x = 1)
    {

        for (int i = 0; i < x; i++)
        {
            s[i].pechati();
        }
    }
};

void najOptovarenaProstorija(prostorija p[], int br)
{

    int najgolem = 0, poz;

    for (int i = 0; i < br; i++)
    {
        if (p[i].rabmesta > najgolem)
        {

            poz = i;
            najgolem = p[i].rabmesta;
        }
    }

    cout << "Najoptovarena e sobata " << p[poz].imep << " so " << p[poz].rabmesta << "studenti" << endl;
    p[poz].pechati();
}

int main()
{

    student s[10];
    prostorija p[2];

    string imes, prezimes, imep, predmets;
    int indeks[2], rabmesta;

    for (int i = 0; i < 2; i++)
    {

        cout << "Vnesete go imeto na prostorijata i brojot na mesta" << endl;
        cin >> imep >> rabmesta;

        for (int j = 0; j < rabmesta; j++)
        {
            cout << "Vnesi podatoci za " << i + 1 << " student" << endl;
            cin >> imes >> prezimes >> indeks[0] >> indeks[1] >> predmets;
            s[j].init(imes, prezimes, indeks[0], indeks[1], predmets);
        }

        p[i].init(imep, rabmesta, s);
    }

    cout << "Pecatenje na informacii za prvata prostorija" << endl;
    p[0].pechati();

    cout << "Pecatenje na informacii za vtorata prostorija" << endl;
    p[1].pechati(3);

    cout << "Pecatenje na informacii za najoptovarenata prostorija" << endl;
    najOptovarenaProstorija(p, 2);

    return 0;
}