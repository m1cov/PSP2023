#include <iostream>

using namespace std;

class Student
{

private:
    int id;
    string kurs;
    int cena;

public:
    Student(int i = 0, string k = "", int c = 0)
    {

        id = i >= 0 ? i : 0;
        kurs = k;
        cena = c >= 0 ? c : 0;
    }

    void pechati()
    {

        cout << id << " " << cena << endl;
    }

    int getCena()
    {
        return cena;
    }
};

class Kurs
{

private:
    int brzapisani;
    Student list[20];
    int participacija;
    string ime;

public:
    Kurs(int n = 0, int p = 0, Student *s = NULL, string i = "")
    {

        brzapisani = n >= 0 && n <= 20 ? n : 0;
        participacija = p >= 0 && p <= 500 ? p : 0;
        ime = i;

        for (int i = 0; i < brzapisani; i++)
            list[i] = s[i];
    }

    void pechati()
    {

        cout << ime << " " << brzapisani << " " << participacija;

        for (int i = 0; i < brzapisani; i++)
            list[i].pechati();
    }

    void func(int x)
    {

        participacija -= participacija * brzapisani / 100;

        cout << participacija - list[x].getCena() << endl;
    }
};

int main()
{

    Kurs k;
    Student *s;

    int n;

    int sifra, cena, participacija;
    string ime;

    cin >> n;
    cin >> ime;

    for (int i = 0; i < n; i++)
    {

        cin >> sifra >> cena;
        s[i] = Student(sifra, ime, cena);
    }

    k = Kurs(n, participacija, s, ime);

    k.pechati();

    k.func(2);

    return 0;
}