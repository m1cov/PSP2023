#include <iostream>

using namespace std;

struct apteka
{

    string lokacija;
    int vraboteni;
    bool raboti;

    void init(string l = "Why", int v = 1, bool r = true)
    {

        lokacija = l;
        vraboteni = v;
        raboti = r;
    }

    void pechati()
    {

        cout << "Aptekata na lokacija " << lokacija << " ima " << vraboteni << " vraboteni i ";
        raboti ? cout << "raboti vo nedela" : cout << "ne raboti vo nedela";
    }
};

apteka defaultApteka[] = {{"Why", 1, true}};

struct lanec
{

    string lanecime;
    int brapteki;
    apteka apteki[10];

    void init(string ime = "Marce", int br = 1, apteka *ap = defaultApteka)
    {

        lanecime = ime;
        brapteki = br;

        for (int i = 0; i < br; i++)
        {
            apteki[i] = ap[i];
        }
    }

    void pechati()
    {

        cout << "Imeto na lanecot e " << lanecime << " i  ima " << brapteki << endl;

        for (int i = 0; i < brapteki; i++)
        {
            apteki[i].pechati();
        }
    }

    void pechati(bool r)
    {

        cout << "Imeto na lanecot e " << lanecime << " i  ima " << brapteki << endl;

        for (int i = 0; i < brapteki; i++)
        {
            if (apteki[i].raboti == true)
                apteki[i].pechati();
        }
    }
};

void najGolemaApteka(lanec niza[], int dolzina)
{
    int najgolema = 0, pozl, poza;
    int i, j;

    for (i = 0; i < dolzina; i++)
    {

        int sum = 0;

        for (j = 0; j < niza[i].brapteki; j++)
        {

            if (niza[i].apteki[j].raboti == true)
                sum += 5;
            else
                sum += niza[i].apteki[j].vraboteni;
        }

        if (sum > najgolema)
        {

            najgolema = sum;
            pozl = i;
            poza = j;
        }
    }

    niza[pozl].apteki[poza].pechati();
}

int main()
{

    lanec lanci[2];
    apteka apteki[10];
    int brapteki, vraboteni;
    bool raboti;
    string lok, ime;

    for (int i = 0; i < 2; i++)
    {
        cin >> ime >> brapteki;

        for (int i = 0; i < brapteki; i++)
        {
            cin >> lok >> vraboteni >> raboti;

            apteki[i].init(lok, vraboteni, raboti);
        }

        lanci[i].init(ime, brapteki, apteki);
    }

    for (int i = 0; i < 2; i++)
        lanci[i].pechati(true);

    najGolemaApteka(lanci, 2);

    return 0;
}