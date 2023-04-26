#include <iostream>
#include <string.h>

using namespace std;

class Student
{

private:
    string ime;
    string prezime;
    char index[8]; // 5 poz od kraj da ima kosa crta i broj posle nea
    int polozeni;  // Ne smee da e negativen
    float procent;

public:
    // Default i parametarski konstruktor
    Student(string i = "", string p = "", char *ind = NULL, int pol = 0)
    {

        ime = i;
        prezime = p;
        pol = pol > 0 ? pol : 0;

        if (strlen(ind) + 1 == 8 && ind[4] == '/' && ind[5] >= '0' && ind[5] <= '9')
            for (int i = 0; i < 8; i++)
                index[i] == ind[i];

        setProcent();
    }

    void pechati()
    {

        cout << ime << " " << prezime << " ";
        for (int i = 0; i < 8; i++)
            cout << index[i];

        cout << " " << polozeni << " " << procent;
    }

    inline void setProcent() { procent = polozeni / 40 * 100; }
};

class Fakultet
{

private:
    string ime;
    int studenti;
    Student list[100];

public:
    Fakultet(string i = "", int s = 0, Student *l = NULL)
    {
        ime = i;
        studenti = s >= 0 ? s : 0;

        for (int i = 0; i < studenti; i++)
            list[i] = l[i];
    }

    void pechati()
    {

        cout << ime << " " << studenti << endl;
        for (int i = 0; i < studenti; i++)
            list[i].pechati();
    }
};

int main()
{

    Fakultet faks;
    Student list[5];

    string imef, ime, prezime;
    char index[8];
    int pol;

    cout << "Vnesi ime na fakultetot" << endl;
    cin >> imef;

    for (int i = 0; i < 5; i++)
    {

        cin >> ime >> prezime >> pol;

        for (int j = 0; j < 8; j++)
            cin >> index[j];

        list[i] = Student(ime, prezime, index, pol);
    }

    faks = Fakultet(imef, 5, list);

    faks.pechati();

    return 0;
}