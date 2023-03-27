#include "stack.h"

int main()
{

    stack s;
    s.init();

    for (int i = 0; i < 3; i++)
    {
        s.push(i);
    }

    while (!s.isEmpty())
    {
        cout << s.pop();
    }


    return 0;
}