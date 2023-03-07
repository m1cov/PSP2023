#include <iostream>

using namespace std;

const int stackSize = 10;
typedef int info_t;

struct magacin
{
    info_t elem[stackSize];
    int top;

    void Init()
    {

        top = -1;
    }

    void Push(int e)
    {

        if (top >= stackSize - 1)
            Stackoverflow();

        top++;
        elem[top] = e;
    }
    info_t Pop()
    {

        if (top < 0)
            Stackunderflow();

        int temp = top;
        top--;
        return elem[temp];
    }
    info_t Peek()
    {

        if (top < 0)
            Stackunderflow();

        return elem[top];
    }
    void Stackoverflow()
    {
        cout << "ERROR: Stackoverflow" << endl;

        exit(-1);
    }
    void Stackunderflow()
    {

        cout << "ERROR: Stackunderflow" << endl;

        exit(-1);
    }

    bool isEmpty()
    {

        return top < 0;
    }
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