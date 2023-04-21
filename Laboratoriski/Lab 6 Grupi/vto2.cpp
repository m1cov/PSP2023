#include <iostream>

using namespace std;

struct node
{

    int info;
    node *next, *prev;
};

struct DPKLista
{

    node *head, *tail;

    inline void init() { head = tail = NULL; }

    void createList(int x)
    {

        node *t = new node;

        t->info = x;
        t->prev = head;
        t->next = tail;

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
            t->prev = tail;

            head->prev = t;

            head = t;

            tail->next = head;
        }
    }

    void brisiPrv()
    {

        if (head != NULL)
        {

            if (head->next == NULL)
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

    void dodadiPos(int x)
    {

        node *t = new node;

        t->info = x;
        t->next = head;
        t->prev = tail;

        tail->next = t;

        tail = t;

        head->prev = tail;
    }

    void brisiPos()
    {

        if (head != NULL)
        {

            if (head->next == NULL)
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

    void brisiLista()
    {

        while (head != NULL)
            brisiPos();
    }

    void pechati()
    {

        node *t = head;

        do
        {

            cout << t->info << "\t";
            t = t->next;

        } while (t != head);

        cout << endl;
    }

    void dodadiPosle(node *p, int x)
    {

        if (p == tail)
            dodadiPos(x);
        else
        {

            node *t = new node;

            t->info = x;
            t->next = p->next;
            t->prev = p;

            p->next = t;
        }
    }
};

int generiraj(DPKLista l)
{

    int br = 0, x, premini = 0;
    node *pom = l.head;

    cout << "Vnesi broj" << endl;
    cin >> x;

    while (premini < 4)
    {

        if (x > 0)
        {

            while (x > 0)
            {
                pom = pom->next;

                x--;

                if (pom == l.head)
                    premini++;
            }

            br += pom->info;
            x = pom->info;
        }
        else
        {

            x *= -1;

            while (x > 0)
            {

                pom = pom->prev;
                x--;

                if (pom == l.tail)
                    premini++;
            }

            br += pom->info;
            x = pom->info;
        }

    }

    return br;
}

int main()
{
    DPKLista L1;

    L1.init();
    L1.dodadiPrv(-1);
    L1.dodadiPos(6);
    L1.dodadiPos(-4);
    L1.dodadiPos(-3);
    L1.dodadiPos(10);
    L1.dodadiPos(-4);
    L1.dodadiPos(5);
    int izlez = generiraj(L1);
    cout << "Sluchajno generiraniot broj e: " << izlez << endl;
    L1.pechati();

    return 0;
}
