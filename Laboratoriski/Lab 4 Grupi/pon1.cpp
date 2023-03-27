#include <iostream>
#define MAX 50

using namespace std;

struct student
{

    string ime;
    int indeks, poeni;

    inline void pechati() { cout << ime << " " << indeks << " " << poeni; }
};

struct queue
{

    student list[MAX];
    int f, r;

    inline void init() { f = r = -1; }
    inline bool isFull() { return r >= MAX - 1; }
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

    void enqueue(student s)
    {

        if (isFull)
            queueOverflow();

        if (f == -1)
            f = 0;

        list[++r] = s;
    }

    student dequeue(){

        if(isEmpty())
            queueUnderflow();



    }

    student peek(){

        if(isEmpty())
            queueUnderflow();

        return list[f];

    }

};

void sort()
{
}

int main()
{

    return 0;
}