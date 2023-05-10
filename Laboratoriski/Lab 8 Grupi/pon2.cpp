#include <iostream>
#include <string.h>
using namespace std;

class Korisnik
{

private:
    char *ime;
    float *kg;
    int merenja;

public:
    Korisnik()
    {

        ime = new char[1];
        ime[0] = ' ';

        kg = new float[1];
        kg[0] = 60;

        merenja = 1;
    }

    Korisnik(const Korisnik &k)
    {

        merenja = k.merenja;

        ime = new char[strlen(k.ime) + 1];
        strcpy(ime, k.ime);

        kg = new float[merenja];
        for (int i = 0; i < merenja; i++)
        {
            kg[i] = k.kg[i];
        }
    }

    void dodadiMerenje(float m)
    {

        float *t = new float[merenja + 1];

        for (int i = 0; i < merenja; i++)
        {
            t[i] = kg[i];
        }

        t[++merenja] = m;

        delete[] kg;
        kg = new float[merenja];

        for (int i = 0; i < merenja; i++)
        {
            kg[i] = t[i];
        }

        delete[] t;
    }

    void brisiMerenje()
    {

        float *t = new float[--merenja];

        for (int i = 0; i < merenja; i++)
            kg[i + 1] = t[i];

        delete[] kg;
        kg = new float[merenja];

        for (int i = 0; i < merenja; i++)
        {
            kg[i] = t[i];
        }

        delete[] t;
    }
};

int main()
{

    return 0;
}