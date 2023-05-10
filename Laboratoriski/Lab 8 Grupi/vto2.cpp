#include <iostream>
#include <cstring>

using namespace std;

class Recenica
{

private:
    string *list = new string[0];
    int br;

public:
    Recenica()
    {
        br = 2;
        list = new string[2];

        list[0] = "Zdravo";
        list[1] = "!";
    }

    ~Recenica()
    {

        delete[] list;
    }

    Recenica(string *l, int n)
    {

        br = n > 0 ? n : 0;

        list = new string[br];

        for (int i = 0; i < br; i++)
            list[i] = l[i];
    }

    Recenica(Recenica &r)
    {

        br = r.br;
        list = new string[br];

        for (int i = 0; i < br; i++)
            list[i] = r.list[i];
    }

    void pechati()
    {

        for (int i = 0; i < br; i++)
            cout << list[i] << " ";
    }

    void dodadiElement(string m)
    {

        string *t = new string[br + 1];

        for (int i = 0; i < br; i++)
            t[i] = list[i];

        br++;

        cout << br;

        t[br] = m;
        br++;
        delete[] list;

        list = new string[br];

        for (int i = 0; i < br; i++)
            list[i] = t[i];

        delete[] t;
    }

    void brisiElement(int poz)
    {
        int n = 0;
        string *t = new string[br];

        for (int i = 0; i < br; i++)
        {
            if (i != poz)
                t[n++] = list[i];
        }

        br = n;
        delete[] list;
        list = new string[br];

        for (int i = 0; i < n; i++)
            list[i] = t[i];

        delete[] t;
    }
};

int main()
{

    string list[] = {"Mnogu", "sakam", "da", "ucam", "PSP", "!"};
    string podrecenia[] = {"za", "copy", "konstruktor"};
    Recenica r;

    r = Recenica(list, 6);

    r.pechati();

    for (int i = 0; i < 3; i++)
        r.dodadiElement(podrecenia[i]);

    // r.brisiElement(5);

    r.pechati();

    return 0;
}