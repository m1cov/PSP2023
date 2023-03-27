#include "stack.h"
#include "dll.h"
#include "sll.h"
#include "queue.h"

int main()
{

    stack s;
    queue q;
    sll slinkedlist;
    dll dlinkedlist;

    s.init();
    q.init();


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