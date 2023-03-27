#include <iostream>
#include <string>

#define MAX 50

using namespace std;

struct covek
{

    string ime;
    string prezime;
    int embr;
    bool rezultat;
    bool testiranjeSer;
    bool testiranjePCR;

    void pechati()
    {

        cout << ime << " " << prezime << " so  maticen broj" << embr;

        if (rezultat)
            cout << " zema rezultati" << endl;
        else if (testiranjeSer)
            cout << " pravi serolosko testiranje" << endl;
        else if (testiranjePCR)
            cout << " pravi PCR testiranje" << endl;
    }
};

struct Queue
{

    covek list[MAX];
    int f, r;

    void init()
    {

        f = r = -1;
    }

    void vnesi(covek c)
    {

        if (isFull())
            QueueOverflow();
        else
        {
            if (f == -1)
                f = 0;

            list[++r] = c;
        }
    }

    covek pull()
    {

        covek c;

        if (isEmpty())
            QueueUnderflow();
        else
        {
            c = list[f];
            if (f == r)
                f = r = -1;
            else
                f++;
        }

        return c;
    }

    void QueueOverflow()
    {

        cout << "QUEUEOVERFLOW";
        exit(-1);
    }
    void QueueUnderflow()
    {

        cout << "QUEUEUNDERFLOW";
        exit(-1);
    }

    inline bool isFull() { return r >= MAX - 1; }
    inline bool isEmpty() { return f < 0; }
};

void raspredeli_usluzi(Queue lugje, Queue rez, Queue ser, Queue pcr)
{

    covek c;

    while (!lugje.isEmpty())
    {

        c = lugje.pull();

        if (c.rezultat)
            rez.vnesi(c);
        else if (c.testiranjeSer)
            ser.vnesi(c);
        else if (c.testiranjePCR)
            ser.vnesi(c);
    }

    while (!rez.isEmpty())
    {

        c = rez.pull();
        c.pechati();
        c.rezultat = false;

        if (c.testiranjeSer)
            ser.vnesi(c);
        else if (c.testiranjePCR)
            pcr.vnesi(c);
    }

    while (!ser.isEmpty())
    {

        c = ser.pull();
        c.pechati();
        c.testiranjeSer = false;

        if (c.testiranjePCR)
            pcr.vnesi(c);
    }

    while (!pcr.isEmpty())
    {

        c = pcr.pull();
        c.pechati();
        c.testiranjePCR = false;
    }
}

int main()
{

    Queue lugje, za_testiranjeSer, za_testiranjePCR, za_rezultati;
    covek pomosen;
    char c;
    int i = 1;

    za_rezultati.init();
    za_testiranjeSer.init();
    za_testiranjePCR.init();

    while (1)
    {

        cout << "Vnesete podatoci za covek" << i << endl;
        cin >> pomosen.ime >> pomosen.prezime >> pomosen.embr >> pomosen.rezultat >> pomosen.testiranjeSer >> pomosen.testiranjePCR;

        lugje.vnesi(pomosen);
        cout << endl;
        cout << "Vnesete . za kraj na vnesuvanjeto" << endl;
        cin >> c;

        if (c == '.')
            break;

        i++;
    }

    raspredeli_usluzi(lugje, za_rezultati, za_testiranjeSer, za_testiranjePCR);
    cout << endl;

    return 0;
}