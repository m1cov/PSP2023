#include <iostream>

using namespace std;

struct node
{

    int info;
    node *prev, *next;
};

struct DPLista
{

    node *head, *tail;

    inline void init() { head = tail = NULL; }

    void create_list(int x)
    {

        node *t = new node;

        t->info = x;
        t->next = t->prev = NULL;

        head = tail = t;
    }

    void dodadiPrv(int x)
    {

        if (head == NULL)
            create_list(x);
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

    void del_first()
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

    void dodadiPosleden(int x)
    {

        if (head == NULL)
            create_list(x);
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

    void del_last()
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
            del_last();
    }

    void dodadiPred(node *p, int x)
    {

        if (p == head)
            dodadiPrv(x);
        else
        {

            node *pom = head;

            while (pom->next != p)
                pom = pom->next;

            node *t = new node;
            t->info = x;

            t->prev = pom;
            t->next = pom->next;

            pom->next->prev = t;
            pom->next = t;
        }
    }

    void brisiPoz(node *p)
    {

        node *pom = p;

        pom->prev->next = p->next;
        pom->next->prev = p->prev;

        delete pom;
    }

    void pechati()
    {

        node *t = head;

        while (t != NULL)
        {

            cout << t->info << '\t';
            t = t->next;
        }

        cout << endl;
    }
};

int igrica(DPLista l)
{

    int rez(0), n;
    node *pom = l.head;

    while (pom != NULL)
    {

        cout << "Vnesi broj";
        cin >> n;

        if (n == 0)
            continue;

        if (n < 0)
        {

            n *= -1;

            while (n > 0 && pom != NULL)
            {
                pom = pom->prev;
                n--;
            }

            if (pom == NULL)
                break;

            rez += pom->info;

            pom = pom->next;
            l.brisiPoz(pom->prev);
        }
        else if (n > 0)
        {

            while (n > 0 && pom != NULL)
            {

                pom = pom->next;
                n--;
            }

            if (pom == NULL)
                break;

            rez += pom->info;

            pom = pom->next;
            l.brisiPoz(pom->prev);
        }
    }

    return rez;
}

int main()
{

    int rez;
    DPLista L1;
    L1.init();
    L1.dodadiPrv(2);

    L1.dodadiPred(L1.head, 5);
    L1.dodadiPosleden(9);
    L1.dodadiPosleden(4);
    L1.dodadiPosleden(10);
    L1.dodadiPosleden(7);
    L1.dodadiPosleden(12);
    L1.dodadiPosleden(11);
    L1.dodadiPosleden(2);
    L1.dodadiPosleden(5);
    L1.dodadiPosleden(13);
    L1.dodadiPred(L1.tail, 1);

    rez = igrica(L1);

    L1.pechati();
    cout << "rezultat: " << rez;

    L1.brishiLista();

    return 0;
}