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

void func(stack &m)
{

    stack rez, obr;

    rez.init();
    obr.init();

    while (!m.isEmpty())
    {

        obr.push(m.peek());
        rez.push(m.pop());
    }

    while (!rez.isEmpty())
    {
        m.push(rez.pop());
    }

    while (!m.isEmpty())
    {
        rez.push(m.pop() + obr.pop());
    }

    while (!rez.isEmpty())
    {
        cout << rez.pop();
    }
}
int main()
{
    stack s;
    int no, element, c;

    s.init();

    cout << "Vnesete koj broj da se proveri:";
    cin >> no;

    while (no != 0)
    {
        element = no % 10;
        no /= 10;
        s.push(element);
    }

    func(s);
}