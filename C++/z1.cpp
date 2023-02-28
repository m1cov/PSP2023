#include <iostream>
#include <string.h>
using namespace std;

struct datum
{

    int den, mesec, godina;
};
struct prijatel
{
    char ime[30];
    datum ragjanje;
    char poraka[30];
};

struct profil
{
    int brPrijateli;

    char ime[30];
    char grad[30];
    datum rodenden;
    prijatel list[5000];
};

void smeniIme(profil &f, char *nIme)
{

    strncpy(f.ime, nIme, 29);
    f.ime[29] = '\0';
}

void smeniGrad(profil &f, char *nGrad)
{

    strncpy(f.grad, nGrad, 30);
    f.grad[29] = '\0';
}

void smeniDatum(profil &f, datum d)
{

    f.rodenden = d;
}

bool dodadiPrijatel(profil &f, prijatel p)
{

    int found = 0;

    if (f.brPrijateli < 5000)
    {

        for (int i = 0; i < f.brPrijateli; i++)
        {
            if (strcmp(f.list[i].ime, p.ime) == 0)
            {
                found++;
                break;
            }
        }

        if (found == 0)
        {

            f.list[f.brPrijateli] = p;
            f.brPrijateli++;
            return true;
        }
    }

    return false;
}

bool brisiPrijatel(profil &f, prijatel p)
{
    int poz = -1;

    for (int i = 0; i < f.brPrijateli; i++)
    {
        if (strcmp(f.list[i].ime, p.ime) == 0)
        {

            poz = i;
            break;
        }
    }

    if (poz == -1)
        return false;

    for (int i = poz; i < f.brPrijateli - 1; i++)
    {
        f.list[i] = f.list[i + 1];
    }

    f.brPrijateli--;
    return true;
}
bool brisiPrijatel(profil &f, char *fbime)
{
    int poz = -1;

    for (int i = 0; i < f.brPrijateli; i++)
    {
        if (strcmp(f.list[i].ime, fbime) == 0)
        {

            poz = i;
            break;
        }
    }

    if (poz == -1)
        return false;

    for (int i = poz; i < f.brPrijateli - 1; i++)
    {
        f.list[i] = f.list[i + 1];
    }

    f.brPrijateli--;
    return true;
}

void cestitajRodenden(profil &f, datum d = {1, 1, 2023})
{

    for (int i = 0; i < f.brPrijateli; i++)
    {
        if ((f.list[i].ragjanje.den == d.den) && (f.list[i].ragjanje.mesec == d.mesec))
        {

            strcpy(f.list[i].poraka, "Srekjen Rodenden");
        }
    }
}

main()
{

    profil f;

    cout << "Vnesi gi podatocite za profilot" << endl;
    cin >> f.ime >> f.grad >> f.rodenden.den >> f.rodenden.mesec >> f.rodenden.godina;

    cout << "Vnesi broj na prijateli" << endl;
    cin >> f.brPrijateli;

    cout << "Vnesi podatoci za prijatelite" << endl;
    for (int i = 0; i < f.brPrijateli; i++)
    {
        cin >> f.list[i].ime >> f.list[i].ragjanje.den >> f.list[i].ragjanje.mesec >> f.list[i].ragjanje.godina;
        strcpy(f.list[i].poraka, "");
    }

    smeniIme(f, "NovoIme");
    prijatel nov;
    cin >> nov.ime >> nov.ragjanje.den >> nov.ragjanje.mesec >> nov.ragjanje.godina;

    dodadiPrijatel(f, nov);
    brisiPrijatel(f, f.list[1]);
    brisiPrijatel(f, f.list[1].ime);

    return 0;
}