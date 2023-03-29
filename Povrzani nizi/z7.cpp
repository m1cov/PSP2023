#include <iostream>
#define MAX 20

using namespace std;

struct klient
{

    string ime, prezime;
};

struct Queue
{

    klient klienti[MAX];
    int f, r;

    inline bool isEmpty() { return f == -1; }
    inline bool isFull() { return r >= MAX - 1; /*return back == front*/ }

    void init()
    {

        f = r = -1;
    }

    int size()
    {
        if (f == -1)
            return 0;

        return r - f + 1;
    }

    void enqueue(klient k)
    {

        if (isFull())
            exit(-1);

        klienti[++r] = k;
    }

    klient dequeue()
    {

        if (isEmpty())
            exit(-1);

        return klienti[f++];

        for (int i = f; i < r; i++)
        {
            klienti[i] = klienti[i + 1];
        }

        r--;
    }

    void print()
    {

        for (int i = f; i < r; i++)
            cout << klienti[i].ime << " " << klienti[i].prezime << endl;
    }
};

struct kasa_t
{

    Queue redica;
    string imeKasier;
    int rbr;
    bool otvorena;
};

struct kasaNode
{
    kasa_t kasa;
    kasaNode *link;
};

struct Market
{

    kasaNode *head;

    void init()
    {

        head = NULL;
    }

    void dodadiKasa(kasa_t k)
    {

        kasaNode *p = head;

        while (p != NULL && p->kasa.rbr != k.rbr)
            p = p->link;

        if (p != NULL)
            p->kasa = k;
        else
        {

            kasaNode *nov = new kasaNode, *prev;
            nov->kasa = k;
            p = prev = head;

            while (p->kasa.rbr < k.rbr && p != NULL)
            {
                prev = p;
                p = p->link;
            }

            prev->link = nov;
            nov->link = p;
        }
    }

    void brishiKasa(int br)
    {

        kasaNode *pom = head;
        kasaNode *prev = head;

        while (pom != NULL && pom->kasa.rbr != br)
        {
            prev = pom;
            pom = pom->link;
        }

        if (pom != NULL)
        {

            prev->link = pom->link;
            delete pom;
        }
    }

    kasaNode *vratiKasa(int br)
    {

        kasaNode *pom = head;
        kasaNode *prev = head;

        while (pom != NULL && pom->kasa.rbr != br)
        {
            prev = pom;
            pom = pom->link;
        }

        return pom;
    }

    void brisiLista()
    {

        kasaNode *pom = head;

        while (pom != NULL)
        {
            head = pom->link;
            delete pom;
            pom = head;
        }
    }

    void print()
    {

        kasaNode *pom = head;

        while (pom != NULL)
        {

            cout << pom->kasa.imeKasier << " " << pom->kasa.otvorena << pom->kasa.rbr;
            pom->kasa.redica.print();

            pom = pom->link;
        }
    }

    void zatvoriKasa(int br)
    {

        kasaNode *pom = head;

        while (pom != NULL && pom->kasa.rbr != br)
        {
            pom = pom->link;
        }

        if (pom != NULL)
            pom->kasa.otvorena = false;
    }

    void opsluziKlient(int br)
    {

        kasaNode *p = vratiKasa(br);

        if (p != NULL)
        {

            p->kasa.redica.dequeue();
        }

        if (p->kasa.otvorena == false && p->kasa.redica.isEmpty())
            brishiKasa(br);
    }

    void dodadiKlient(klient x)
    {

        kasaNode *pom = head;

        while (pom != NULL && !pom->kasa.otvorena)
            pom = pom->link;

        kasaNode *min = pom;

        while (pom != NULL)
        {
            if (pom->kasa.otvorena && pom->kasa.redica.size() < min->kasa.redica.size())
                min = pom;
        }

        if (min != NULL)
            min->kasa.redica.enqueue(x);
    }
};

int main()
{
}