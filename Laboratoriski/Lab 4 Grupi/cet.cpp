#include <iostream>

using namespace std;

const int size = 100;

struct queue
{
    char list[size];
    int f, r;

    void init()
    {
        f = 0;
        r = -1;
    }

    void push(char c)
    {

        if (isFull())
            exit(-1);

        list[++r] = c;
    }

    char pull()
    {
        if (isEmpty())
            exit(-1);

        return list[f++];
    }

    char peek()
    {

        if (isEmpty())
            exit(-1);

        return list[f];
    }

    inline bool isFull() { return r >= size - 1; }
    inline bool isEmpty() { return r - f < 0; }
};

void func(queue s, queue &m)
{
}

int main()
{

    queue s, m;
    string recenica;

    int i = 0;

    s.init();
    m.init();

    getline(cin, recenica);

    while (recenica[i] != '\0')
    {

        s.push(recenica[i++]);
    }

    func(s, m);

    while (!m.isEmpty())
        cout << m.pull();

    return 0;
}