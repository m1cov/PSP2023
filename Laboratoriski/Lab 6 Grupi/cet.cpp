#include <iostream>
using namespace std;

struct node
{

    char info;
    node *prev, *next;
};

struct DPKLista
{
    node *head, *tail;

    void init() { head = tail = NULL; }

    void create(char x)
    {

        node *t = new node;

        t->info = x;
        t->next = t->prev = t;
        head = tail = t;
    }

    void dodadiPrv(char c)
    {

        if (head == NULL)
            create(c);
        else
        {

            node *t = new node;

            t->info = c;
            t->next = head;
            t->prev = tail;

            head->prev = t;
            tail->next = t;

            head = t;
        }
    }

    void dodadiPos(char c)
    {

        if (head == NULL)
            create(c);
        else
        {

            node *t = new node;

            t->info = c;
            t->next = head;
            t->prev = tail;

            tail->next = t;
            head->prev = t;

            tail = t;
        }
    }

    void brisiPrv()
    {

        if (head != NULL)
        {

            if (head->next = head)
                delete head;
            else
            {

                node *t = head;

                head = head->next;
                head->prev = tail;
                tail->next = head;

                delete t;
            }
        }
    }

    void brisiPos()
    {

        if (head != NULL)
        {

            if (head->next = head)
                delete head;
            else
            {

                node *t = tail;

                tail = tail->prev;
                tail->next = head;
                head->prev = tail;

                delete t;
            }
        }
    }

    void pechati()
    {

        node *t = head;

        do
        {
            cout << t->info;
            t = t->next;

        } while (t != head);

        cout << endl;
    }

    void brisiLista()
    {

        while (head != NULL)
            brisiPrv();
    }

    void brisiPoz(node *p)
    {

        node *t = p;

        if (p == head)
            brisiPrv();
        if (p == tail)
            brisiPos();
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;

            delete t;
        }
    }
};

void konvertiraj(DPKLista &l1, DPKLista &l2, char c)
{

    node *pom = l1.head, *poz;

    do
    {

        if (pom->info == c)
        {

            poz = pom;
        }

        pom = pom->next;

    } while (pom != l1.head);

    pom = poz->next;

    node *org = l2.tail;

    do
    {

        node *t = pom;

        pom = pom->next;

        t->prev->next = t->next;
        t->next->prev = t->prev;

        t->next = l2.head;
        t->prev = l2.tail;
        l2.tail->next = t;
        l2.head->prev = t;

        l2.tail = t;

    } while (pom != l1.head);

    pom = l2.head;

    do
    {

        node *t = l2.head;

        l2.head = l2.head->next;

        l2.head->prev = l2.tail;
        l2.tail->next = l2.head;

        t->next = l1.head;
        t->prev = l1.tail;

        l1.head->prev = t;
        l1.tail->next = t;

    } while (l2.head != org);

    cout << l2.head->info;
}

int main()
{
    DPKLista L1, L2;
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

    L2.init();

    L2.dodadiPrv('d');
    L2.dodadiPos('e');
    L2.dodadiPos('s');
    L2.dodadiPos('e');
    L2.dodadiPos('t');
    L2.dodadiPos('k');
    L2.dodadiPos('a');

    konvertiraj(L1, L2, ' ');

    //  L1.pechati();
    // L2.pechati();
    L1.brisiLista();
    L2.brisiLista();
    return 0;
}