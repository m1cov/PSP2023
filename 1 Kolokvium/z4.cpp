#include <iostream>

using namespace std;

struct mag
{

    int list[100];
    int t;

    void init();
    bool isFull();
    void push(int x);
    int pop();
    bool isEmpty();
};

mag func(int x)
{

    mag r;
    r.init(); // Do ovde 1 poen od 50 :) LETSSS GOOO IDEMO NIS BRE\

    while (x > 0)
    {
        int cifra = x % 10;
        x /= 10;
        r.push(cifra);
    }

    return r;
}

mag postoi(mag r1, mag r2)
{

    mag r;
    r.init();

    int p = 0;

    while (!r2.isEmpty())
    {
        int e1 = r1.pop() - p;
        int e2 = r2.pop();

        int e3 = e1 - e2;

        if (e3 < 0)
        {

            e3 = 10 + e3;
            p = 1;
        }
        else
            p = 0;

        r.push(e3);
    }

    while (!r1.isEmpty())
    {

        if (p)
        {
            r.push(r1.pop() - p);
            p = 0;
        }
        else
            r.push(r1.pop());
    }

    

}

int main()
{
}
