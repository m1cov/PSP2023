#include <iostream>

using namespace std;

const int stacksize = 100;

struct stack
{
    int list[stacksize];
    int top;

    inline void init() { top = -1; }
    inline bool isEmpty() { return top < 0; }
    inline bool isFull() { return top >= stacksize - 1; }

    void push(int e)
    {

        if (isFull())
            exit(-1);

        list[++top] = e;
    }

    int pop()
    {

        if (isEmpty())
            exit(-1);

        return list[top--];
    }

    int peek()
    {

        if (isEmpty())
            exit(-1);

        return list[top];
    }
};

void func(int br1, int br2, stack &m)
{

    stack temp, pom;
    temp.init();
    pom.init();

    int x;

    if (br1 > br2)
    {

        while (!m.isEmpty())
        {
            x = m.pop();

            if (x <= br1 && x >= br2)
                temp.push(x);
        }
    }
    else
    {

        while (!m.isEmpty())
        {
            x = m.pop();

            if (x >= br1 && x <= br2)
                temp.push(x);
        }
    }

    while (!temp.isEmpty())
        pom.push(temp.pop());

    while (!pom.isEmpty())
        m.push(pom.pop());
}

int main()
{

    stack s;
    int count, no1, no2, element;
    s.init();
    cout << "Vnesete kolku elementi da ima magacinot:";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s.push(element);
    }
    cout << "Vnesete vrednosti:";
    cin >> no1 >> no2;
    func(no1, no2, s);
    while (!s.isEmpty())
        cout << s.pop() << endl;
}