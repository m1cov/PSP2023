#include <iostream>

using namespace std;

class Medium
{

private:
    string ime;
    int brv, brl;

public:
    Medium(string i = "", int bv = 0, int bl = 0)
    {

        brv = bv >= 0 ? bv : 0;
        brl = bl >= 0 ? bl : 0;
        ime = i;
    }

    virtual int index()
    {

        return brv * 5 - brl;
    }

    virtual void pechati()
    {

        cout << ime << brv << brl << endl;
    }
};

class TV : public Medium
{
private:
    bool profil;

public:
    TV(string i = "", int bv = 0, int bl = 0, bool p = false) : Medium(i, bv, bl), profil(p){};

    int index()
    {

        if (profil)
            return Medium::index() + 20;

        return Medium::index();
    }

    void pechati()
    {

        Medium::pechati();
        cout << profil << endl;
    }
};

class Portal : public Medium
{

public:
    Portal(string i = "", int brv = 0, int brl = 0, int bp = 0) : Medium(i, brv, brl)
    {
        brpost = bp > 0 ? bp : 0;
    }

    int index()
    {

        float procent = (brpost / 20) * 5;

        return Medium::index() * (1 + procent / 100);
    }

    void pechati()
    {

        Medium::pechati();
        cout << brpost << endl;
    }

private:
    int brpost;
};

int pomalIndex(Medium *m1, Medium *m2)
{

    if (m1->index() < m2->index())
        return 1;

    return 0;
}

int najmalIndex(Medium **list, int n)
{

    int min = 0;

    for (int i = 1; i < n; i++)
    {
        if (pomalIndex(list[i], list[min]) == 1)
            min = i;
    }

    return min;
}

int main(){

    

}
