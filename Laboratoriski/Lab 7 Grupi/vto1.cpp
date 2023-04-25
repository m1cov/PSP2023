#include <iostream>

using namespace std;

class Velosipedist
{

private:
    string ime, prezime;
    int godini, poeni;

public:
    Velosipedist(string i = "", string prez = "", int g = 0, int p = 0)
    {

        ime = i;
        prezime = prez;

        godini = g >= 0 ? g : 0;
        poeni = p >= 0 ? p : 0;
    }

    int get_poeni()
    {
        return poeni;
    }

    void pechati()
    {

        cout << ime << " " << prezime << " " << godini << " " << poeni << endl;
    }
};

class Tim
{

private:
    string ime, sponzor;
    Velosipedist list[10];

public:
    Tim(string i, string s, Velosipedist *l)
    {

        ime = i;
        sponzor = s;

        for (int i = 0; i < sizeof(l) / sizeof(Velosipedist); i++)
            list[i] = l[i];
    }

    ~Tim()
    {
        delete &ime;
        delete &sponzor;
        delete list;
    }

    int poeni_tim()
    {

        int sum = 0;

        for (int i = 0; i < sizeof(list) / sizeof(int); i++)
        {
            sum += list[i].get_poeni();
        }

        return sum;
    }

    void pechati()
    {

        cout << ime << " " << sponzor << endl;

        for (int i = 0; i < sizeof(list) / sizeof(int); i++)
        {
            list[i].pechati();
        }
    }
};

int main()
{


    

    return 0;
}