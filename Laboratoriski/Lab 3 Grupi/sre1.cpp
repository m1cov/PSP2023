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

void func(stack &m1, stack &m2)
{

    stack temp1, temp2, pom;
    temp1.init();
    temp2.init();
    pom.init();

    while (!m1.isEmpty())
        temp1.push(m1.pop());

    while (!m2.isEmpty())
        temp2.push(m2.pop());

    while (!temp1.isEmpty() && !temp2.isEmpty())
    {

        if (temp1.peek() == temp2.peek())
        {
            pom.push(temp1.pop());
            temp2.pop();
        }
        else
            temp1.pop();
    }

    while (!pom.isEmpty())
        m1.push(pom.pop());

    pom.init();

    while (!temp2.isEmpty())
        pom.push(temp2.pop());

    while (!pom.isEmpty())
        m2.push(pom.pop());
}
int main()
{
    stack s1, s2;
    int count, element;

    s1.init();
    s2.init();

    cout << "Vnesete kolku elementi da magacin 1:";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s1.push(element);
    }

    cout << "Vnesete kolku elementi da magacin 2:";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s2.push(element);
    }

    func(s1, s2);

    while (!s1.isEmpty())
        cout << s1.pop() << " ";

    cout << endl;

    while (!s2.isEmpty())
        cout << s2.pop() << " ";
}