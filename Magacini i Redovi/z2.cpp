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

void decToBin(int x)
{

    info_t c;
    magacin n;
    n.Init();

    while (x)
    {
        c = x / 2;
        n.Push(c);
        x /= 2;
    }

    while (!n.isEmpty())
    {

        cout << n.Pop();
    }
}

int main()
{

    int broj;

    cin >> broj;

    decToBin(broj);

    return 0;
}