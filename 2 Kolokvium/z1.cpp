#include <iostream>
#include <string>

using namespace std;

struct Sostojka
{

    string ime;
    int masa;
};

class Proizvodi
{
private:
    string ime;
    int cena, broj;
    Sostojka *list;

public:
    Proizvodi(string i = "", int c = 0, int b = 0, Sostojka *l = NULL)
    {

        ime = i;
        cena = c > 0 ? c : 0;
        broj = b > 0 ? b : 0;

        list = new Sostojka[broj];     // Pravi nova niza od sostojki so dolzina od brojot na sostojki
        for (int i = 0; i < broj; i++) // Mesti sostojki
        {
            list[i] = l[i];
        }
    }

    ~Proizvodi()
    {

        delete[] list;
    }

    // Dodadi sostojka na kraj na lista
    Proizvodi &operator+=(Sostojka &s)
    {
    }

    // Dodadi sostojka na pocetok na lista
    Proizvodi &operator-=(Sostojka &s)
    {
    }

    // Brisi posledna sostojka
    Proizvodi &operator++()
    {
    }

    // Brisi prva sostojka
    Proizvodi &operator--() {}

    // Pecati
    friend ostream &operator<<(const ostream o, const Proizvodi &p) // Friend bidejki sakame ostream da ima pristap do private na proizvodi
    {
    }
};

int main()
{

    return 0;
}
