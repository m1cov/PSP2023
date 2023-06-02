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
        mat = m == 1 ? m : 0;
        trosok = t > 0 ? t : 0;
        meseci = s > 0 ? s : 0;

        presmetajCena();
    }

    ~Kujnski()
    {

        delete this;
    }

    int getCena() { return cena; }

    virtual void presmetajCena()
    {

        if (mat == 0)
            cena = 4000 + trosok * meseci;
        else
            cena = 2000 + trosok * meseci;
    }

    virtual void pechati()
    {

        cout << ime << endl;
        mat == 1 ? cout << "Iverka" << endl : cout << "Medijapan" << endl;
        cout << trosok << meseci << cena;
    }
};

class Masi : Kujnski
{

private:
    int povrsina, fioki;
    int zafatnina[10];

public:
    Masi(string i = "", int m = 0, int t = 0, int s = 0, int p = 0, int f = 0, int z[10] = NULL) : Kujnski(i, m, t, s)
    {

        povrsina = p > 0 ? p : 0;
        fioki = f > 0 && f <= 10 ? f : 0;

        for (int i = 0; i < fioki; i++)
            zafatnina[i] = z[i];
    }

    ~Masi()
    {

        delete this;
    }

    void pechati()
    {

        Kujnski::pechati();

        cout << povrsina << fioki << endl;
        for (int i = 0; i < fioki; i++)
            cout << zafatnina[i] << '\t';
    }

    void presmetajCena()
    {

        Kujnski::presmetajCena();

        cena *= 1.0 + ((float)povrsina * 25 / 100); // Pokacuvanje na cena poradi povrsina

        int vkz = 0; // Naogja vkupna zafatnina na fiokite
        for (int i = 0; i < fioki; i++)
            vkz += zafatnina[i];

        cena *= 1.0 + ((float)vkz * 20 / 100); // Presmetuva pokacuvanje na cena poradi fioki
    }
};

class Visecki : Kujnski
{

private:
    int vraticki, polici;

public:
    Visecki(string i = "", int m = 0, int t = 0, int s = 0, int v = 0, int p = 0) : Kujnski(i, m, t, s)
    {

        vraticki = v > 0 ? v : 0;
        polici = p > 0 ? p : 0;
    }

    ~Visecki()
    {

        delete this;
    }

    void pechati()
    {

        Kujnski::pechati();

        cout << vraticki << polici << endl;
    }

    void presmetajCena()
    {

        Kujnski::presmetajCena();

        cena += 500 * vraticki + 2000 * polici;
    }
};

void najevtin(Kujnski **list, int n)
{

    Kujnski *l = list[0];

    for (int i = 0; i < n; i++)
    {
        if (list[i]->getCena() < l->getCena())
            l = list[i];
    }

    l->pechati();
}

int vkcena(Kujnski **list, int n)
{

    int vk = 0;

    for (int i = 0; i < n; i++)
    {
        vk += list[i]->getCena();
    }

    return vk;
}

int main()
{
    return 0;
}