#include <iostream>

using namespace std;

struct queue
{

    int list[100];
    int f, r;

    inline void init() { f = r = -1; }
    inline bool isFull() { return r >= 99; }
    inline bool isEmpty() { return r - f < 0; }

    int peek()
    {
    }

    int pop()
    {
    }

    void push(int x)
    {
    }
};

bool proverka(queue r, queue r1, queue r2)
{

    while (!r.isEmpty() && r1.isEmpty() && r2.isEmpty())
    {

        if (r1.pop() != r.pop() || r2.pop() != r.pop())
            return false;
    }

    if (r.isEmpty() && r1.isEmpty() && r2.isEmpty())
        return true;

    return false;
}

int main()
{

    queue r, r1, r2;
    int e, n = 0;
    char c;

    r1.init();
    r2.init();
    r.init();

    cout << "Vnesuvaj elementi" << endl;
    while (true)
    {

        cin >> e;
        r.push(e);
        n++;

        cout << "Tocka za kraj" << endl;
        cin >> c;
        if (c == '.')
            break;
    }

    if (n % 2 == 1)
    {
        cout << "GRESKA" << endl;
        return 0;
    }

    queue temp = r;

    while (!r.isEmpty())
    {
        r1.push(temp.pop());
        r2.push(temp.pop());
    }

    if (proverka(r, r1, r2))
        cout << "Ekvivalentni se";
    else
        cout << "Ne se ekvivalentni";

    return 0;
}