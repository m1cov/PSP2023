#include <iostream>

using namespace std;

enum tipSoba
{
    ednokrevetna,
    dvokrevetna,
    superior,
    delux,
    apartman
};

char *tipNiza[5] = {"Ednokrevetna", "Dvokrevetna", "Superior", "Delux", "Apartman"};

struct Soba
{
    int broj, cena;
    tipSoba tip;
    bool zafatena;

    void init(int br = 1, tipSoba t = ednokrevetna, bool z = false, int c = 1200)
    {
        broj = br;
        tip = t;
        cena = c;
        zafatena = z;
    }

    void pecati()
    {

        cout << tipNiza[tip] << " so broj " << broj;
        (zafatena == true) ? cout << "e" : cout << "ne e";
        cout << "zafatena, a nejzinata cena e " << cena << endl;
    }
};

Soba defaultSobi[2] = {{1, 1200, ednokrevetna, false}, {1, 1200, ednokrevetna, false}};

struct Hotel
{
    string ime, lokacija;
    int brSobi;
    Soba sobi[100];

    void init(string i = "Ime", string l = "Lokacija", int br = 2, Soba *s = defaultSobi)
    {

        ime = i;
        lokacija = l;
        brSobi = br;

        for (int i = 0; i < br; i++)
        {
            sobi[i] = s[i];
        }
    }

    void pecati()
    {

        cout << "Hotelot " << ime << " na adresa " << lokacija << " raspolaga so vkupno " << brSobi << endl;

        for (int i = 0; i < brSobi; i++)
        {
            sobi[i].pecati();
        }
    }
};

int main()
{

    Hotel hoteli[3];
    Soba sobi[100];
    int brojSobi;
    int tip;
    bool zafatena;
    int cena;
    string ime, adresa;

    hoteli[0].init();

    for (int i = 1; i <= 2; i++)
    {
        cout << "Inicijalizirajte gi sobite za " << i << "-ot hotel" << endl
             << endl;
        cout << "Kolku sobi ima hotelot?" << endl;
        cin >> brojSobi;
        for (int j = 0; j < brojSobi; j++)
        {
            cout << "Vnesete tip:" << endl;
            cin >> tip;
            cout << "Dali e zafatena (1 za da, 0 za ne)" << endl;
            cin >> zafatena;
            cout << "Vnesete cena:" << endl;
            cin >> cena;
            sobi[j].init(j + 1, tipSoba(tip), zafatena, cena);
        }
        cout << endl
             << "Inicijalizirajte go " << i << "-ot hotel" << endl;
        cout << "Vnesete ime:" << endl;
        cin >> ime;
        cout << "Vnesete adresa:" << endl;
        cin >> adresa;
        hoteli[i].init(ime, adresa, brojSobi, sobi);
        cin.clear();
    }
    cout << "Pechatenje na informaciite za hotelite" << endl;
    for (int i = 0; i <= 2; i++)
    {
        hoteli[i].pecati();
    }

    return 0;
}