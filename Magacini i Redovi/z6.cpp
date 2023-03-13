#include <iostream>
using namespace std;

const int QueueMax = 10;
typedef int info_t;

struct Queue
{

    info_t lista[QueueMax];
    int f, r;

    void Init();
    bool isFull();
    bool isEmpty();
    void enqueue(info_t e);
    info_t dequeue();
    info_t peek();
};

struct Stack
{
    info_t elem[QueueMax];
    int top;

    void Push(info_t e);
    info_t Pop();
    info_t Peek();
    void Stackoverflow();
    void Stackunderflow();
    void Init();
    bool isEmpty();
};

int main()
{

    Queue red;
    red.Init();
    char c;

    while (true)
    {
        cin >> c;
        red.enqueue(c);

        if (c == '.')
            break;
    }

    Queue izlez;
    izlez.Init();

    Stack pom;
    pom.Init();

    while (!red.isEmpty())
    {
        c = red.dequeue();

        if (c == 'X')
        {
            izlez.enqueue(c);
        }
        else
        {
            izlez.enqueue(c);
            pom.Push(c);

            do
            {

                c = red.dequeue();
                izlez.enqueue(c);
                pom.Push(c);

            } while (c != 'X');
        }
    }

    while (!pom.isEmpty())
    {
        c = pom.Pop();
        izlez.enqueue(c);
    }

    while (!izlez.isEmpty())
    {
        c = izlez.dequeue();
        cout << c;
    }

    return 0;
}