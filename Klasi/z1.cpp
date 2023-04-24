#include <iostream>

using namespace std;

class Vraboten
{

private:
    string ime;
    float plata;
    int pozicija;

public:
    Vraboten(string i = "", float p = 0.0, int poz = 0)
    {
        if (i.length() < 30)
            ime = i;
        if (plata >= 0.0)
            plata = p;

        if (poz >= 0 && poz < 3)
            pozicija = poz;
    }

    void setIme(string i)
    {

        if (i.length() < 30)
            ime = i;
    }

    void setPlata(float p)
    {

        if (plata >= 0.0)
            plata = p;
    }

    void setPozicija(int poz)
    {

        if (poz >= 0 && poz < 3)
            pozicija = poz;
    }

    string getIme()
    {

        return ime;
    }

    float getPlata()
    {
        return plata;
    }

    int getPoz()
    {
        return pozicija;
    }

    void pechati()
    {

        cout << ime << " " << plata;

        switch (pozicija)
        {
        case 0:
            cout << " Vraboten" << endl;
            break;

        case 1:
            cout << " Rakovoditel" << endl;
            break;

        case 2:
            cout << " Direktor " << endl;
            break;
        default:
            break;
        }
    }
};

int main()
{

    int n;

    string ime;
    float plata;
    int poz;

    Vraboten list[100];

    cout << "Vnesi broj na vraboteni" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Vnesi podatoci za vraboten";

        cin >> ime >> plata >> poz;

        list[i].setIme(ime);
        list[i].setPlata(plata);
        list[i].setPozicija(poz);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (list[j].getPlata() > list[i].getPlata())
            {

                Vraboten temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        list[i].pechati();
    }
}
