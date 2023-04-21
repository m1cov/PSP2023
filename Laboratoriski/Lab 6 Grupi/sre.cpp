#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node
{

    char info;
    node *next, *prev;
};

struct DPLista
{

    node *head, *tail;

    inline void init() { head = tail = NULL; }

    void createList(int x)
    {

        node *t = new node;

        t->info = x;

        t->prev = t->next = NULL;
        head = tail = t;
    }

    void dodadiPrv(int x)
    {

        if (head == NULL)
            createList(x);
        else
        {

            node *t = new node;

            t->info = x;
            t->next = head;
            t->prev = NULL;

            head->prev = t;
            head = t;
        }
    }

    void dodadiPos(int x)
    {

        if (head == NULL)
            createList(x);
        else
        {

            node *t = new node;

            t->info = x;
            t->next = NULL;
            t->prev = tail;

            tail->next = t;

            tail = t;
        }
    }

    void delFirst()
    {

        if (head != NULL)
        {

            if (head->next == NULL)
                delete head;
            else
            {

                node *t = head;

                head = head->next;
                head->prev = NULL;

                delete t;
            }
        }
    }

    void delLast()
    {

        if (head != NULL)
        {

            if (head->next == NULL)
                delete head;
            else
            {

                node *t = tail;

                tail = tail->prev;
                tail->next = NULL;

                delete t;
            }
        }
    }

    void brishiLista()
    {

        while (head != NULL)
            delLast();
    }

    void pechati()
    {
        node *t = head;
        while (t != NULL)
        {

            cout << t->info << "\t";
            t = t->next;
        }

        cout << endl;
    }

    void dodadiPosle(node *p, char c)
    {

        node *t = new node;

        t->info = c;
        t->next = p->next;
        t->prev = p;

        p->next = t;
    }
};

void konvertiraj(DPLista &l1, DPLista &l2, char c)
{
    node *poz = NULL, *pom = l1.head;
    bool najden = false;

    while (pom != NULL)
    {

        if (pom->info = c)
        {
            poz = pom;
            najden = true;
        }

        pom = pom->next;
    }

    if (najden)
    {

        l2.head = l1.head;

        l1.head = l1.head->next;

        l2.head->next = NULL;
    }

    pom = l2.head;

    while (pom != poz && pom != NULL)
    {

        

    }
}

int main()
{
    DPLista L1, L2;

    L1.init();
    L1.dodadiPrv('m');
    L1.dodadiPos('n');
    L1.dodadiPos('o');
    L1.dodadiPos('g');
    L1.dodadiPos('u');
    L1.dodadiPos(' ');
    L1.dodadiPos('s');
    L1.dodadiPos('a');
    L1.dodadiPos('k');
    L1.dodadiPos('a');
    L1.dodadiPos('m');
    L1.dodadiPos(' ');
    L1.dodadiPos('p');
    L1.dodadiPos('s');
    L1.dodadiPos('p');

    konvertiraj(L1, L2, ' ');

    L1.pechati();
    L2.pechati();

    L1.brishiLista();
    L2.brishiLista();
    return 0;
}