#include <iostream>

using namespace std;

const int STACKSIZE = 10;
typedef int info_t;

struct stack
{

    info_t broj[STACKSIZE];
    int top;

    inline void init() { top = -1; }

    void push(info_t elem)
    {

        if (top >= STACKSIZE - 1)
        {

            cout << "STACKOVERFLOW";
            exit(-1);
        }

        top++;
        broj[top] = elem;
    }

    info_t peek()
    {

        if (top < 0)
        {

            cout << "STACKUNDERFLOW";
            exit(-1);
        }

        return broj[top];
    }

    info_t pop()
    {

        if (top < 0)
        {

            cout << "STACKUNDERFLOW";
            exit(-1);
        }

        top--;
        return broj[top + 1];
    }

    inline bool isEmpty() { return top < 0; }

    inline bool isFull() { return top >= STACKSIZE - 1; }
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
    int n, element, c;
    s.init();
    cout << "Vnesete broj koj ke se proveri: " << endl;
    cin >> n;

    while (n != 0)
    {
        element = n % 10;
        n /= 10;
        s.push(element);
    }

    func(s);

    return 0;
}