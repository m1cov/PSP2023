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

int getElemByIndex(Queue red, int i)
{

    while (i)
    {
        red.dequeue();
        i--;
    }

    return red.peek();
}

Queue funk(Queue r1, Queue r2){

    Queue r3;
    r3.Init();

    int elem, i;

    while (!r2.isEmpty())
    {
        
        i = r2.dequeue();
        elem = getElemByIndex(r1, i);
        r3.enqueue(elem);
    }
    

    return r3;

}

int main()
{
}