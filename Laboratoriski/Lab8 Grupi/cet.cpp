#include <iostream>
#include <string.h>

using namespace std;

class Recenica
{

private:
    char *recenica = new char[0];

public:
    Recenica(char *r = "Zdravo")
    {

        for (int i = 0; i < strlen(r) + 1; i++)
            recenica[i] = r[i];
    }

    Recenica(Recenica &r)
    {

        for (int i = 0; i < strlen(r.recenica) + 1; i++)
            recenica[i] = r.recenica[i];
    }

    ~Recenica()
    {

        delete[] recenica;
    }

    void pechati()
    {

        for (int i = 0; i < strlen(recenica); i++)
            cout << recenica[i];
    }

    void dodadiZnak(char *niza, bool lok)
    {

        char *t = new char[strlen(recenica) + strlen(niza) + 1];

        if (lok)
        {

            for (int i = 0; i < strlen(recenica); i++)
                t[i] = recenica[i];

            for (int i = strlen(recenica); i < strlen(recenica) + strlen(niza); i++)
                t[i] = niza[i];

            t[strlen(recenica) + strlen(niza)] = '\0';

            delete[] recenica;

            recenica = new char[strlen(t) + 1];

            for (int i = 0; i < strlen(t) + 1; i++)
                recenica[i] = t[i];

            delete[] t;
        }
        else
        {

            for (int i = 0; i < strlen(niza); i++)
                t[i] = niza[i];

            for (int i = strlen(niza); i < strlen(recenica) + strlen(niza); i++)
                t[i] = recenica[i];

            t[strlen(recenica) + strlen(niza)] = '\0';

            delete[] recenica;

            recenica = new char[strlen(t) + 1];

            for (int i = 0; i < strlen(t) + 1; i++)
                recenica[i] = t[i];

            delete[] t;
        }
    }

    void brisiZnak(int poz)
    {

        int br = 0;
        bool najden = false;
        char *t = new char[strlen(recenica) + 1];

        for (int i = 0; i < strlen(recenica) + 1; i++)
        {
            if (i != poz)
                t[br++] = recenica[i];
            else
                najden = true;
        }

        delete[] recenica;

        recenica = najden ? new char[strlen(t)] : new char[strlen(t) + 1];

        for (int i = 0; i < strlen(recenica) + 1; i++)
            recenica[i] = t[i];

        delete[] t;
    }
};

int main()
{

    char *l1 = "Mnogu sakam da ucam PSP!";
    char *l2 = "za copy konstruktor";
    Recenica r(l1);

    r.pechati();

    r.dodadiZnak(l2, 1);
    r.brisiZnak(24);

    r.pechati();

    return 0;
}