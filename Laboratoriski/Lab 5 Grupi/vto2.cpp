/* Да се напише функција за работа со единечно поврзани кружни листи, која на влез добива
две пополнети листи. Функцијата треба да ги измине истовремено листите и доколку наиде на
јазли со иста вредност, јазолот од втората листа да се префрли во првата листа (во втората листа
повеќе да го нема) и тоа пред моментално разгледуваниот јазол во првата листа. Изминувањето
се прави се додека има јазли и во двете листи.

Влез:
Lista1: |10|->|2|->|5|->|7|->|13|
Lista2: |5|->|2|->|7|->|7|
Излез:
Lista1: |10|->|2|->|2|->|5|->|7|->|7|->|13|
Lista2: |5|->|7|

 */
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct node
{
    int info;
    node *link;
};

struct KLista
{

    node *head, *tail;

    inline void init() { head = tail = NULL; }

    void sozdadiLista(int x)
    {

        node *t = new node;
        t->info = x;

        t->link = t;
        head = tail = t;
    }

    void dodadiPrv(int x)
    {

        if (head == NULL)
            sozdadiLista(x);
        else
        {

            node *t = new node;
            t->info = x;

            t->link = head;
            head = t;
            tail->link = head;
        }
    }

    void dodadiPosleden(int x)
    {

        if (head == NULL)
            sozdadiLista(x);
        else
        {

            node *temp = new node;
            temp->info = x;

            tail->link = temp;
            temp->link = head;
            tail = temp;
        }
    }

    void pechati()
    {

        node *p = head;

        cout << p->info << "\t";
        p = head->link;

        while (p != head)
        {

            cout << p->info << '\t';
            p = p->link;
        }
    }

    void del_last()
    {

        node *temp = head;

        while (temp->link != tail)
        {

            temp = temp->link;
        }

        node *p = tail;
        delete tail;

        tail = temp;
        tail->link = head;
    }

    void del_first()
    {

        node *temp = head;

        head = head->link;
        tail->link = head;
        delete temp;
    }

    void brishiLista()
    {

        while (head != NULL)
        {
            del_last();
        }
    }
};

void promeni(KLista &l1, KLista &l2)
{
}

int main()
{
    KLista L1, L2;

    L1.init();
    L2.init();

    L1.dodadiPrv(10);
    L1.dodadiPosleden(2);
    L1.dodadiPosleden(5);
    L1.dodadiPosleden(7);
    L1.dodadiPosleden(13);

    L2.dodadiPosleden(7);
    L2.dodadiPrv(7);
    L2.dodadiPrv(2);
    L2.dodadiPrv(5);

    L1.pechati();
    L2.pechati();

    promeni(L1, L2);

    L1.brishiLista();
    L2.brishiLista();

    return 0;
}