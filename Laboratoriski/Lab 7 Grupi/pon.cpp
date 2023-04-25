#include <iostream>

using namespace std;

class Student
{

private:
    int id;
    Kurs kurs;
    int cena;

public:
    Student(int i = 0, Kurs k = Kurs(), int c = 0)
    {

        id = i >= 0 ? i : 0;
        kurs = k;
        cena = c >= 0 ? c : 0;
    }

    void setSifra(int x)
    {

        id = x >= 0 ? x : 0;
    }
    void setKurs(Kurs x)
    {

        kurs = x;
    }
    void pechati()
    {

        cout << id << " " << cena << endl;
    }

    int getCena()
    {
        return cena;
    }

    void setCena(int x)
    {

        cena = x >= 0 ? x : 0;
    }
};

class Kurs
{

private:
    int brzapisani;
    Student list[20];
    int participacija;

public:
    Kurs(int n = 0, int p = 0, Student *s = NULL)
    {

        brzapisani = n >= 0 && n <= 20 ? n : 0;
        participacija = p >= 0 && p <= 500 ? p : 0;

        for (int i = 0; i < brzapisani; i++)
            list[i] = s[i];
    }

    void pechati()
    {

        cout << brzapisani << " " << participacija;

        for (int i = 0; i < brzapisani; i++)
            list[i].pechati();
    }

    float func(int x)
    {

        return participacija - list[x].getCena();
    }
};

int main()
{

    Kurs k;
    Student *s;

    int n;

    int sifra, cena;

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cin >> sifra >> cena;
        s[i].setCena(cena);
        s[i].setKurs(k);
        s[i].setSifra(sifra);
    }

    

    return 0;
}