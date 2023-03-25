#include <iostream>

using namespace std;

enum disciplina
{
    skiSkokac,
    skijac,
    bijatlonec
};

char *disciplinas[3] = {"Ski Skokac", "Skijac", "Bijatlonec"};

struct reprezentativec
{

    string imer;
    disciplina disc;
    int brmedali;

    void init(string ir = "Mirko", disciplina d = skiSkokac, int br = 0)
    {
        imer = ir;
        disc = d;
        brmedali = br;
    }

    void pechati()
    {
        cout << imer << " " << disciplinas[disc] << " " << brmedali << endl;
    }
};

reprezentativec defaultRep[] = {{"Mirko", skiSkokac, 0}};

struct reprezentacija
{

    string ime;
    int br;
    reprezentativec rp[10];

    void init(string rep = "MK", int b = 1, reprezentativec *reptivec = defaultRep)
    {

        ime = rep;
        br = b;
        for (int i = 0; i < br; i++)
            rp[i] = reptivec[i];
    }

    void pechati()
    {
        cout << ime << " " << br << endl;
        for (int i = 0; i < br; i++)
        {
            rp[i].pechati();
        }
    }

    void pechati(string im)
    {
        cout << ime << " " << br << endl;
        for (int i = 0; i < br; i++)
        {

            if (im == rp[i].imer)
                rp[i].pechati();
        }
    }

    void pechati(disciplina d)
    {
        cout << ime << " " << br << endl;
        for (int i = 0; i < br; i++)
        {

            if (d == rp[i].disc)
                rp[i].pechati();
        }
    }
};

void najTroffen(reprezentacija rep)
{

    int najmnogu = 0;
    int poz;

    for (int i = 0; i < rep.br; i++)
    {
        if (rep.rp[i].brmedali > najmnogu)
        {
            najmnogu = rep.rp[i].brmedali;
            poz = i;
        }
    }

    rep.rp[poz].pechati();
}

int main()
{

    reprezentacija reprezentacii[3];
    reprezentativec reprezentativci[9];

    string imer, imec;
    int br = 3, medali;
    int tip;

    for (int i = 0; i < 3; i++)
    {
        cout << "Vnesi ime na reprezentacijata" << endl;
        cin >> imer;

        for (int j = 0; j < 3; j++)
        {
            cout << "Vnesi ime na reprezentativecot" << endl;
            cin >> imec;

            cout << "Vnesi broj na osvoeni medali" << endl;
            cin >> medali;

            cout << "Vnesi tip disciplina" << endl;
            cin >> tip;

            reprezentativci[i].init(imec, disciplina(tip), medali);
        }

        reprezentacii[i].init(imer, br, reprezentativci);
    }

    reprezentacii[0].pechati();
    reprezentacii[1].pechati(reprezentacii[1].rp[2].imer);
    reprezentacii[2].pechati(skiSkokac);

    najTroffen(reprezentacii[0]);
    najTroffen(reprezentacii[1]);
    najTroffen(reprezentacii[2]);

    return 0;
}