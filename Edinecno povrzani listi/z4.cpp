#include <iostream>

using namespace std;

typedef int info_t;

struct node
{

    info_t info;
    node *link;
};

struct SLList
{

    node *head;

    void init()
    {
        head = NULL;
    }

    void insFirst(info_t x)
    {

        init();
        node *p = new node;
        p->info = x;
        p->link = NULL;
        head = p;
    }

    void insFront(info_t x)
    {

        if (head != NULL)
        {

            node *p = new node;
            p->info = x;
            p->link = head;
            head = p;
        }
        else
            insFirst(x);
    }

    void insLast(info_t x)
    {

        if (head != NULL)
        {

            node *p = new node;
            p->info = x;
            p->link = NULL;

            node *k = head;

            while (k->link != NULL)
                k = k->link;

            k->link = p;
        }
        else
            insFirst(x);
    }

    void delFront()
    {

        if (head != NULL)
        {

            if (head->link != NULL)
            {

                node *temp = new node;
                temp = head;

                head = head->link;
                delete temp;
            }
            else
                delete head;
        }
    }

    void delLast()
    {

        if (head != NULL)
        {

            if (head->link == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {

                node *pom = head;

                while (pom->link->link != NULL)
                {
                    pom = pom->link;
                }

                delete pom->link;
                pom->link = NULL;
            }
        }
    }

    void printList()
    {

        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->info << endl;
            temp = temp->link;
        }
    }

    void deleteList()
    {

        while (head != NULL)
        {
            delLast();
        }
    }
};

int main()
{

    SLList lista;
    info_t x;
    int n;

    lista.init();

    cout << "Vnesi broj na elementi" << endl;
    cin >> n;

    cout << "Vnesi prv elem" << endl;
    cin >> x;
    lista.insFirst(x);

    for (int i = 1; i < n; i++)
    {
        cout << "Vnesi element" << endl;
        cin >> x;

        i % 2 == 0 ? lista.insFront(x) : lista.insLast(x);
    }

    lista.printList();
    lista.delFront();
    lista.delLast();

    lista.printList();
    lista.deleteList();

}