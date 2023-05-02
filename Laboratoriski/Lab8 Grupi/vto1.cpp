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

    Fakultet(const Fakultet &from){

        ime = from.ime;
        predmeti = from.predmeti;
        krediti = from.krediti;

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

        cout << ime << " " << predmeti << endl;
        for (int i = 0; i < predmeti; i++)
            cout << krediti[i];
    }
};

class Univerzitet
{

private:
    string ime;
    Fakultet *list = new Fakultet[0];
    int br;

public:
    Univerzitet(string i = "", int n = 0, Fakultet *f = NULL)
    {

        ime = i;
        br = n >= 0 ? n : 0;

        for (int i = 0; i < br; i++)
            list[i] = f[i];

    }

    Univerzitet(const Univerzitet &from){

        ime = from.ime;
        br = from.br;
        list = from.list;

    }

    Fakultet najmnoguSo6Krediti()
    {
        int najmnogu = 0, poz = 0;


        for (int i = 0; i < br; i++)
        {
            if(list[i].brojStandardniPredmeti() > najmnogu){
                poz = i;
                najmnogu = list[i].brojStandardniPredmeti();
            }
        }
        
        return list[poz];

    }
};

int main()
{

    Fakultet list[2];
    Univerzitet uni;

    string imeu, imef;
    int *x = new int[0], predmeti;

    cout << "Vnesi ime na univerzitetot" << endl;
    cin >> imeu;

    for (int i = 0; i < 2; i++)
    {
        cout << "Vnesi ime na fakultetot" << endl;
        cin >> imef;
        cout << "Vnesi kolku predmeti ima na fakultetot" << endl;
        cin >> predmeti;
        
        x = new int[predmeti];

        for (int i = 0; i < predmeti; i++)
        {
                cout << "Vnesi kolku krediti nosi predmetot" << endl;
                cin >> x[i];
        }
        list[i] = Fakultet(predmeti, x, imef);
    }
    
    uni = Univerzitet(imeu, 2, list);

    uni.najmnoguSo6Krediti().pechati();
}