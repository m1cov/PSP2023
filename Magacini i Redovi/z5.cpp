#include <iostream>

using namespace std;

const int QueueMax = 10;

struct covek
{

    string ime, prezime;
    bool l, p, v;
};

struct Queue
{

    covek lista[QueueMax];
    int f, r;

    void Init();
    bool isFull();
    bool isEmpty();
    void enqueue(covek e);
    covek dequeue();
    covek peek();
};

void opsluzi(Queue &r1, Queue &r2, Queue &r3)
{

    covek k;

    while (!r1.isEmpty())
    {

        k = r1.dequeue();
        cout << "Opsluzen za licni karti " << k.ime << " " << k.prezime << endl;
        k.l = false;

        if (k.p)
        {
            r2.enqueue(k);
        }
        if (k.v)
        {
            r3.enqueue(k);
        }
    }

    while (!r2.isEmpty())
    {

        k = r2.dequeue();
        cout << "Opsluzen za pasos " << k.ime << " " << k.prezime << endl;
        k.p = false;

        if (k.v)
        {
            r3.enqueue(k);
        }
    }

    while (!r3.isEmpty())
    {

        k = r3.dequeue();
        cout << "Opsluzen za vozacka dozvola " << k.ime << " " << k.prezime << endl;
        k.v = false;
    }
}

int main()
{

    Queue r1, r2, r3;
    char d = ' ';

    r1.Init();
    r2.Init();
    r3.Init();

    while (d != '.')
    {

        covek c;

        cout << "Vnesi ime i prezime" << endl;
        cin >> c.ime >> c.prezime;

        cout << "Licna karta, pasos, vozacka dozvola" << endl;
        cin >> c.l >> c.p >> c.v;

        if (c.l == true)
            r1.enqueue(c);
        else if (c.p == true)
            r2.enqueue(c);
        else if (c.v == true)
            r3.enqueue(c);

        cout << "Vnesi tocka za izlez";
        cin >> d;
    }
}