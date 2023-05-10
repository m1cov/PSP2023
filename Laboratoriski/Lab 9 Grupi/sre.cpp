#include <iostream>

using namespace std;

class Livce
{

private:
    int broevi;
    int *list;

public:
    Livce(int br = 1, int *l = NULL)
    {

        broevi = br > 0 ? br : 0;

        list = new int[broevi];

        if (l != NULL)
            for (int i = 0; i < broevi; i++)
                list[i] = l[i];
        else
            list[0] = 1;
    }

    ~Livce()
    {
        delete[] list;
    }

    friend ostream &operator>>(ostream &o, Livce &l)
    {
    }

    friend ostream &operator<<(ostream &o, Livce &l)
    {

        for (int i = 0; i < l.broevi; i++)
            o << l.list[i];
    }

    Livce &operator=(const Livce &l)
    {

        broevi = l.broevi;

        for (int i = 0; i < broevi; i++)
            list[i] = l.list[i];
    }

    bool &operator==(const Livce &l)
    {

        bool isti = true;

        if (broevi != l.broevi)
        {
            isti = false;
            return isti;
        }

        for (int i = 0; i < broevi; i++)
        {

            if (list[i] != l.list[i])
            {
                isti = false;
                return isti;
            }
        }

        return isti;
    }

    Livce &operator++(int br)
    {

        int *t = new int[broevi + 1];

        for (int i = 0; i < broevi; i++)
            t[i] = list[i];

        t[broevi] = br;

        delete[] list;
        list = new int[++broevi];

        for (int i = 0; i < broevi; i++)
            list[i] = t[i];

        delete[] t;
    }
};

int main()
{

    // Allegedly e napisan

    return 0;
}