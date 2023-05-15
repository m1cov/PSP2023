#include <iostream>

using namespace std;

class Recenica
{
private:
    string *list = new string[0];
    int zborovi;

public:
    Recenica(string *l = NULL, int br = 1)
    {
        zborovi = br > 0 ? br : 0;
        list = new string[zborovi];

        if (l != NULL)
            for (int i = 0; i < zborovi; i++)
                list[i] = l[i];
        else
            list[0] = "default";
    }

    ~Recenica()
    {
        delete[] list;
    }

    friend ostream &operator<<(ostream &o, const Recenica &r)
    {
        for (int i = 0; i < r.zborovi; i++)
        {
            o << r.list[i] << " ";
        }

        cout << endl;

        return o;
    }

    Recenica &operator=(const Recenica &r)
    {
        zborovi = r.zborovi;

        list = new string[zborovi];

        for (int i = 0; i < zborovi; i++)
            list[i] = r.list[i];

        return *this;
    }

    // Vika a necu
    bool &operator>(const Recenica &r)
    {

        bool pogolem = true;

        pogolem = zborovi > r.zborovi ? true : false;

        return pogolem;
    }

    Recenica &operator-=(string zbor)
    {
        string *t = new string[++zborovi];

        t[0] = zbor;

        for (int i = 1; i < zborovi; i++)
            t[i] = list[i - 1];

        delete[] list;
        list = new string[zborovi];

        for (int i = 0; i < zborovi; i++)
            list[i] = t[i];

        delete[] t;

        return *this;
    }

    Recenica &operator--()
    {

        string *t = new string[zborovi - 1];

        for (int i = 1; i < zborovi; i++)
        {
            t[i - 1] = list[i];
        }

        delete[] list;
        list = new string[--zborovi];

        for (int i = 0; i < zborovi; i++)
            list[i] = t[i];

        delete[] t;

        return *this;
    }

    string operator[](const int poz)
    {

        return list[poz];
    }
};

int main()
{
    string zborovi[6] = {"sakam", "da", "polozam", "psp", "vo", "juni"};
    Recenica r1 = Recenica();
    Recenica r2 = Recenica(zborovi, 6);
    Recenica r3;
    r3 = r2;

    cout << r2;
    cout << r3;

    r2 -= "Jas";

    cout << r2;
    --r2;
    cout << r2;
    cout << (r2 > r1);
    r1[0] = "Nov";
    cout << r2[0];
    return 0;
}