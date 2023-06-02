#include <iostream>

using namespace std;

class Sportist
{

private:
    string ime;
    string *tituli;
    int n;

public:
    Sportist(string i = "", string *t = NULL, int n = 0)
    {

        // Kod za konstruktor
    }

    Sportist(const Sportist &s)
    {
        // Da
    }

    ~Sportist()
    {
        delete[] tituli;
    }

    Sportist &operator=(const Sportist &s)
    {

        if (this == &s)
            return *this;

        // Isto ko copy constructor

        return *this;
    }

    virtual float potencijal() { return n / 2.0; }

    virtual void pechati()
    {

        cout << ime;
        for (int i = 0; i < n; i++)
            cout << tituli[i] << endl;
    }

    Sportist &operator+=(string s)
    {

        string *t = new string[n + 1];
        t[0] = s;

        for (int i = 0; i < n; i++)
        {
            t[i + 1] = tituli[i];
        }

        delete[] tituli;
        tituli = new string[++n];

        for (int i = 0; i < n; i++)
        {
            tituli[i] = t[i];
        }

        delete[] t;
    }
};

class Teniser : public Sportist
{
private:
    int atp;

public:
    Teniser(string i = "", string *t = NULL, int nt = 0, int a = 0) : Sportist(i, t, nt)
    {

        atp = a > 0 ? a : 0;
    }

    float potencijal()
    {

        float p = Sportist::potencijal();
        if (atp >= 1 && atp <= 60)
            p += 60 - atp + 1;

        return p;
    }

    void pechati()
    {

        Sportist::pechati();
        cout << atp << endl;
    }
};

class Fudbaler : public Sportist
{
private:
    string poz;
    bool rep;

public:
    Fudbaler(string i = "", string *t = NULL, int nt = 0, string p = "", bool r = false) : Sportist(i, t, nt)
    {

        rep = r;
        
    }
};

int main()
{

    return 0;
}
