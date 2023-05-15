#include <iostream>

using namespace std;

class TV
{
    
    public:
    int getCena();
    void pechati();
};

class HD : TV
{
    
    public:
    int getCena();
    void pechati();
};

class TV3D : TV
{

    public:
    int getCena();
    void pechati();
};

void dostapnost(TV *listTV, int nTV, HD *listHD, int nHD, TV3D *list3D, int n3D, float budget)
{

    for (int i = 0; i < nTV; i++)
    {
        if (listTV[i].getCena() <= budget)
        {
            listTV[i].pechati();
            cout << budget - listTV[i].getCena();
        }
    }

    for (int i = 0; i < nHD; i++)
    {
        if (listHD[i].getCena() <= budget)
        {
            listHD[i].pechati();
            cout << budget - listHD[i].getCena();
        }
    }

    for (int i = 0; i < n3D; i++)
    {
        if (list3D[i].getCena() <= budget)
        {
            list3D[i].pechati();
            cout << budget - list3D[i].getCena();
        }
    }
}

int main()
{
}