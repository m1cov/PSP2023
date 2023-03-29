#include <iostream>

using namespace std;

const int size = 100;

struct queue
{

    int list[size];
    int f, r;

    inline void init() { f = r = -1; }
    inline bool isEmpty() { return r - f < 0; }
    inline bool isFull() { return r >= size - 1; }

    void put(int x)
    {
    }

    int pull()
    {
    }

    int peek()
    {
    }
};

void func(int br1, int br2, queue &m)
{
}

int main()
{

    queue s;
    int count, no1, no2, element;

    s.init();

    cout << "Vnesete kolku elementi da ima redot:";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s.put(element);
    }

    cout << "Vnesete vrednosti:";
    cin >> no1 >> no2;

    func(no1, no2, s);

    while (!s.isEmpty())
        cout << s.pull() << endl;

    return 0;
}