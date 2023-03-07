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