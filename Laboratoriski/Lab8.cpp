#include <iostream>

using namespace std;

class Fakultet
{

private:
    int predmeti;
    int *krediti = new int[0];
    string ime;

public:
    Fakultet(int br = 0, int *k = NULL, string i = "")
    {

        ime = i;
        predmeti = br >= 0 ? br : 0;

        krediti = new int[predmeti];
        for (int i = 0; i < predmeti; i++)
        {
            krediti[i] = k[i];
        }
    }

    int brojStandardniPredmeti()
    {

        int t = 0;

        for (int i = 0; i < predmeti; i++)
        {
            if (krediti[i] == 6)
                t++;
        }

        return t;
    }

    void pechati()
    {
    }
};

class Univerzitet
{

private:
    string ime;
    Fakultet *list = new Fakultet[0];
    int br;

public:
    Univerzitet()
    {
    }

    Fakultet najmnoguSo6Krediti()
    {
    }
};

// TODO: za dvete dodadi Copy Constructor

int main()
{

    Fakultet list[2];
    Univerzitet uni;

    // TODO: Dodadi za vnes na faks

    uni.najmnoguSo6Krediti().pechati();
}