#include <iostream>

using namespace std;

enum pozicija
{
    farmaceft,
    tehnicar,
    pomosenPersonal

};

char *pozicijas[3] = {"Farmaceft", "Tehnicar", "Pomosen Personal"};

struct vraboten
{

    string imevraboten;
    pozicija poz;
    int plata;

    void init(string v = "Petko", pozicija p = farmaceft, int pl = 18000)
    {

        imevraboten = v;
        poz = p;
        plata = pl;
    }

    void pechati()
    {

        cout << imevraboten << " na pozicija " << pozicijas[poz] << " so plata " << plata << endl;
    }
};

vraboten defaultVraboten[] = {{"Petko", farmaceft, 18000}};

struct apteka
{

    string aptekaime;
    int br;
    vraboten v[8];

    void init(string ai = "Apteka 1", int b = 1, vraboten *vp = defaultVraboten)
    {

        aptekaime = ai;
        br = b;

        for (int i = 0; i < br; i++)
        {
            v[i] = vp[i];
        }
    }

    void pechati()
    {

        cout << aptekaime << " ima " << br << " vraboteni i tie se" << endl;
        for (int i = 0; i < br; i++)
        {
            v[i].pechati();
        }
    }

    void pechati(pozicija p)
    {

        cout << aptekaime << " ima " << br << " vraboteni i tie se" << endl;
        for (int i = 0; i < br; i++)
        {

            if (v[i].poz == p)
                v[i].pechati();
        }
    }
};

void najZahtevnaApteka(apteka apteki[], int dolzina)
{

    int najmongu = 0;
    int pozapteka;

    for (int i = 0; i < dolzina; i++)
    {
        int sum = 0;

        for (int j = 0; j < apteki[i].br; j++)
        {
            sum += apteki[i].v[j].plata;
        }

        if (sum >= najmongu)
        {
            pozapteka = i;
            najmongu = sum;
        }
    }

    apteki[pozapteka].pechati();
}

int main()
{

    apteka apteki[3];
    vraboten vraboteni[25];
    string imea, imev;
    int plata, br;
    int poz;

    for (int i = 0; i < 3; i++)
    {
        cout << "Vnesi ime na aptekata" << endl;
        cin >> imea;

        cout << "Vnesi broj na vraboteni vo aptekata" << endl;
        cin >> br;

        for (int j = 0; j < br; j++)
        {
            cout << "Vnesi ime na vraboten" << endl;
            cin >> imev;

            cout << "Vnesi ja rabotnata pozicija" << endl;
            cin >> poz;

            cout << "Vnesi ja platata negova" << endl;
            cin >> plata;

            vraboteni[j].init(imev, pozicija(poz), plata);
        }

        apteki[i].init(imea, br, vraboteni);
    }

    apteki[0].pechati();
    apteki[1].pechati(farmaceft);

    najZahtevnaApteka(apteki, 3);

    return 0;
}
