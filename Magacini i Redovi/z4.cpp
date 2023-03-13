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

void promeni(magacin &m)
{

    magacin h;
    h.Init();

    int p, t;
    bool prv = true;

    while (!m.isEmpty())
    {
        t = m.Pop();

        if (!prv && t % p == 0)
        {

            h.Push(t / p);
        }

        p = t;
        prv = false;
    }

    if (!m.isEmpty() && t % m.Peek() == 0)
    {

        h.Push(t / m.Peek());
    }

    while (!h.isEmpty())
    {
        m.Push(h.Pop());
    }
}

int main()
{

    return 0;
}