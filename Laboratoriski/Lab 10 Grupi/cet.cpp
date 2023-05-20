#include <iostream>

using namespace std;

class Kujnski
{

protected:
    string ime;
    int mat, trosok, meseci;
    int cena;

public:
    Kujnski(string i = "", int m = 0, int t = 0, int s = 0)
    {

        ime = i;
        mat = m > 0 && m <= 1 ? m : 0;
        trosok = t > 0 ? t : 0;
        meseci = s > 0 ? s : 0;

        presmetajCena();
    }

    virtual void presmetajCena()
    {

        if (mat == 0)
            cena = 4000 + trosok * meseci;
        else
            cena = 2000 + trosok * meseci;
    }
};

class Masi : Kujnski
{
};

class Visecki : Kujnski
{
};

void najevtin()
{
}

int vkcena()
{
}

int main()
{
    return 0;
}