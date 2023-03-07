#include <iostream>

using namespace std;

const int stackSize = 10;
typedef int info_t;

struct magacin
{
    info_t elem[stackSize];
    int top;

    void Push(int e);
    info_t Pop();
    info_t Peek();
    void Stackoverflow();
    void Stackunderflow();
    void Init();
    bool isEmpty();
};

int izbrisi(magacin &m, int x)
{

    magacin d;
    bool f = false;
    int poz = 0, c = 0;

    d.Init();

    while (!m.isEmpty())
    {
        d.Push(m.Pop());
    }

    while (!d.isEmpty())
    {
        c++;
        if (f == false && d.Peek() == x)
        {
            f = true;
            poz = d.top + 1;
        }
        else
        {

            m.Push(d.Pop());
        }

        return poz;
    }
    return c;
}

int main()
{

    int broj;

    cin >> broj;

    return 0;
}