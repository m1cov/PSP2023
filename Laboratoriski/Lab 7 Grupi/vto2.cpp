#include <iostream>

using namespace std;

class Muzicar
{
private:
    string ime;
    int instrumenti, plata;

public:
    Muzicar(string i = "", int ins = 0, int p = 0)
    {

        ime = i;
        instrumenti = ins >= 0 ? ins : 0;
        plata = p >= 0 ? p : 0;
    }

    int get_plata() { return plata; }
    int get_ins() { return instrumenti; }

    void set_plata(int x) { plata = x >= 0 ? x : 0; }

    void pechati()
    {

        cout << ime << " " << instrumenti << " " << endl;
    }
};

class Orkestar
{

private:
    string ime;
    int br, kompozicii;
    Muzicar muzicari[10];

public:
    Orkestar(string i = "", int n = 0, int k = 0, Muzicar *m = NULL)
    {
        ime = i;
        br = n >= 0 ? n : 0;
        kompozicii = k >= 0 ? k : 0;

        for (int i = 0; i < br; i++)
            muzicari[i] = m[i];
    }

    int get_plata(int x)
    {

        muzicari->get_plata() + 100 * x + 200 * muzicari->get_ins();
    }

    void pechati()
    {

        cout << ime << " " << br << " " << kompozicii << endl;

        for (int i = 0; i < br; i++)
            muzicari[i].pechati();
    }
};

int main()
{
}
