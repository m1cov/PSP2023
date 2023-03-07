#include <iostream>

using namespace std;

const int stacksize = 10;
typedef char info_t;

struct magacin
{
    info_t elem[stacksize];
    int top;

    void Push(int e);
    info_t Pop();
    info_t Peek();
    void Stackoverflow();
    void Stackunderflow();

    bool isEmpty();
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