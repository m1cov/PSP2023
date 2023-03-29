#include <iostream>

using namespace std;

const int size = 100;

struct Queue
{

    int list[size];
    int f, r;

    inline void init() { f = r = -1; }
    inline bool isEmpty() { return r - f < 0; }
    inline bool isFull() { return r >= size - 1; }

    void push(int x)
    {
        if (isFull())
            exit(-1);

        if (f == -1)
            f = 0;

        list[++r] = x;
    }

    int pull()
    {

        if (isEmpty())
            exit(-1);

        return list[f++];
    }

    int peek()
    {
        if (isEmpty())
            exit(-1);

        return list[f];
    }
};

void modify(Queue s, Queue &m)
{

    int x, y;

    while (!s.isEmpty())
    {

        if (s.r - s.f < 1)
            break;

        x = s.pull();
        y = s.peek();

        if (x + y > 9)
            m.push(x);
        else
            m.push(x + y);
    }
}

int main()
{

    Queue red, mod;
    int n, br;

    cout << "Vnesi dolzina na brojot" << endl;
    cin >> n;

    red.init();
    mod.init();

    for (int i = 0; i < n; i++)
    {

        cin >> br;
        red.push(br);
    }

    modify(red, mod);

    while (!mod.isEmpty())
        cout << mod.pull();

    return 0;
}