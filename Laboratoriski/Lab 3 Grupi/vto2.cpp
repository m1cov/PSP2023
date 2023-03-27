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
        {

            cout << "STACKOVERFLOW";
            exit(-1);
        }

        list[++top] = e;
    }

    int peek()
    {

        if (isEmpty())
        {

            cout << "STACKUNDERFLOW";
            exit(-1);
        }

        return list[top];
    }

    int pop()
    {

        if (isEmpty())
        {

            cout << "STACKUNDERFLOW";
            exit(-1);
        }

        return list[top--];
    }
};

void func(stack &m)
{

    stack temp, pom;
    temp.init();
    pom.init();

    int a, b;

    while (!m.isEmpty())
    {
        a = m.pop();
        b = m.pop();

        temp.push(b);
        temp.push(a);
    }

    while (!temp.isEmpty())
        pom.push(temp.pop());

    while (!pom.isEmpty())
        m.push(pom.pop());
}
int main()
{
    stack s;
    int count, element;
    s.init();
    cout << "Vnesete kolku elementi da ima magacinot:";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s.push(element);
    }

    func(s);
    while (!s.isEmpty())
        cout << s.pop() << endl;
}