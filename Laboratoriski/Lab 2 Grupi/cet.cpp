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

struct lanec
{

    string lanecime;
    int brapteki;
    apteka apteki[10];

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
}

int main()
{

    return 0;
}