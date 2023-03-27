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
