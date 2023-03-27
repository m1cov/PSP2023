#include <iostream>

using namespace std;

const int queueSize = 100;
typedef int info_t;

struct queue
{

    info_t list[queueSize];
    int f, r;

    inline void init() { f = r = -1; }
    inline bool isFull() { return r >= queueSize - 1; }
    inline bool isEmpty() { return r - f < 0; }

    void queueOverflow()
    {

        cout << "QUEUEOVERFLOW" << endl;
        exit(-1);
    }

    void queueUnderflow()
    {

        cout << "QUEUEUNDERFLOW" << endl;
        exit(-1);
    }

    void enqueue(info_t s)
    {

        if (isFull())
            queueOverflow();

        if (f == -1)
            f = 0;

        list[++r] = s;
    }

    info_t dequeue()
    {

        if (isEmpty())
            queueUnderflow();

        return list[f++];
    }

    info_t peek()
    {
        info_t c;

        if (isEmpty())
            queueUnderflow();
        else
        {
            c = list[f];
            if (f == r)
                f = r = -1;
            else
                f++;
        }
    }
};