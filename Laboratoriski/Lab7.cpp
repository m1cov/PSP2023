#include <iostream>

using namespace std;

class Kosarkar
{

private:
    string ime;
    int plata;

public:
    Kosarkar(string i = "", int p = 30000)
    {

        ime = i;
        plata = p;
    }

    void pechati()
    {

        cout << ime << " " << plata << endl;
    }

    void setIme(string i = "")
    {

        ime = i;
    }

    void presmetaj(float prosek)
    {

        while ((int)prosek > 0)
        {

            plata += 50;
            prosek -= 1;
        }
    }
};

class Ekipa
{

private:
    string ekipaime;
    int br;
    float prosek;
    Kosarkar list[8];

public:
    Ekipa(string ei = "", int n = 0, float p = 0, Kosarkar *k = NULL)
    {

        ekipaime = ei;
        br = n > 0 ? n : 0;
        prosek = p > 0.0 ? p : 0.0;

        for (int i = 0; i < br; i++)
        {
            list[i] = k[i];
        }
    }

    void pechati()
    {

        cout << ekipaime << " " << prosek << " " << br << endl;

        for (int i = 0; i < br; i++)
        {
            list[i].pechati();
        }
    }
};

int main()
{

    Kosarkar k[5];

    string ime;

    for (int i = 0; i < 5; i++)
    {

        cin >> ime;
        k[i].setIme(ime);
    }

    for (int i = 0; i < 5; i++)
    {
        k[i].presmetaj(85);
    }

    Ekipa e("Insert Kosarkarska Ekipa", 5, 85, k);

    e.pechati();
}
