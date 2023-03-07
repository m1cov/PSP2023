#include <iostream>

using namespace std;

const int stacksize = 10;
typedef char info_t;

struct magacin
{
    info_t elem[stacksize];
    int top;

    void Init()
    {

        top = -1;
    }

    void Push(int e)
    {

        if (top >= stacksize - 1)
            Stackoverflow();

        top++;
        elem[top] = e;
    }
    info_t Pop()
    {

        if (top < 0)
            Stackunderflow();

        int temp = top;
        top--;
        return elem[temp];
    }
    info_t Peek()
    {

        if (top < 0)
            Stackunderflow();

        return elem[top];
    }
    void Stackoverflow()
    {
        cout << "ERROR: Stackoverflow" << endl;

        exit(-1);
    }
    void Stackunderflow()
    {

        cout << "ERROR: Stackunderflow" << endl;

        exit(-1);
    }

    bool isEmpty()
    {

        return top < 0;
    }
};

bool proverka(magacin m, char *s)
{
    info_t elem;
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {

            elem = *s;
            m.Push(elem);
        }

        if (*s == ')' && m.Peek() == '(')
            m.Pop();
        else if (*s == ']' && m.Peek() == '[')
            m.Pop();
        else if (*s == '}' && m.Peek() == '{')
            m.Pop();
        else
        {

            cout << "Greska";
            return false;
        }
    }

    if (!m.isEmpty())
    {

        cout << "Greska";
        return false;
    }

    return true;
}

int main()
{
}