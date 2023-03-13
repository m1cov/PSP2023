#include <iostream>

using namespace std;

struct student
{
};

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

Queue podredi(Queue &PSP, Queue &BiP, student p)
{

    Queue izlez, pomPSP, pomBiP;

    izlez.init();
    pomPSP.init();
    pomBiP.init();

    while (!PSP.isEmpty())
    {
        p = PSP.dequeue();

        if (p.poeni > 40)
            izlez.enqueue(p);
        else
            pomPSP.enqueue(p);

        while (!BiP.isEmpty())
        {

            p = BiP.dequeue();

            if (p.poeni > 50)
                izlez.enqueue(p);
            else
                pomBiP.enqueue(p);
        }

        while (!pomPSP.isEmpty())
        {
            p = pomPSP.dequeue();

            if (p.poeni > 30)
                izlez.enqueue(p);
        }

        while (!pomBiP.isEmpty())
        {
            p = pomBiP.dequeue();

            if (p.poeni > 30)
                izlez.enqueue(p);
        }

        return izlez;
    }
}
