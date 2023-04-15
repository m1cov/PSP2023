#include <iostream>

using namespace std;

struct node
{

    int info;
    node *prev, *next;
};

struct CDLL
{
    node *head, *tail;

    void init()
    {

        head = tail = NULL;
    }

    void create_list(int x)
    {

        node *t = new node;
        t->info = x;
        t->next = t;
        t->prev = t;

        head = tail = t;
    }

    void ins_first(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {
            node *t = new node;
            t->info = x;

            t->next = head;
            t->prev = tail;

            head->prev = t;
            tail->next = t;
            head = t;
        }
    }

    void ins_last(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *t = new node;

            t->info = x;
            t->prev = tail;
            t->next = head;

            head->prev = t;
            tail->next = t;

            tail = t;
        }
    }

    void del_first()
    {

        if (head != NULL)
        {

            if (head->next == head)
                delete head;
            else
            {

                node *t = head;

                tail->next = head->next;
                head->next->prev = tail;

                head = head->next;

                delete t;
            }
        }
    }

    void del_last()
    {

        if (head != NULL)
        {

            if (head->next == head)
                delete head;
            else
            {

                node *t = tail;

                head->prev = tail->prev;
                tail->prev->next = head;

                tail = tail->prev;

                delete t;
            }
        }
    }

    void del_list()
    {

        while (head != NULL)
            del_last();
    }

    void print()
    {

        node *t = head;

        do
        {

            cout << t->info << '\t';
            t = t->next;

        } while (t != head);

        cout << endl;
    }
};

void modificiraj(CDLL &l1, CDLL &l2, CDLL &l3)
{
}

int main()
{

    CDLL l1, l2, l3;

    int list1[8] = {2, 5, 7, 9, 3, 3, 7, 1};
    int list2[12] = {5, 3, 4, 1, 5, 1, 1, 5, 3, 4, 4, 3};

    l1.init();
    l2.init();
    l3.init();

    /*
        int a, b, x;

        cout << "Vnesi dolzina na prvata i vtorata lista" << endl;
        cin >> a >> b;

        cout << "Vnesi elementi na prvata lista" << endl;
        for (int i = 0; i < a; i++)
        {
            cin >> x;
            l1.ins_last(x);
        }

        cout << "Vnesi elementi na vtorata lista" << endl;
        for (int i = 0; i < b; i++)
        {
            cin >> x;
            l2.ins_last(x);
        } */

    for (int i = 0; i < 8; i++)
        l1.ins_last(list1[i]);

    cout << "Prvata lista pred modifikacija" << endl;
    l1.print();

    for (int i = 0; i < 12; i++)
        l2.ins_last(list2[i]);

    cout << "Vtorata lista pred modifikacija" << endl;
    l2.print();

    modificiraj(l1, l2, l3);

    cout << "Prvata lista po modifikacija" << endl;
    l1.print();

    cout << "Vtorata lista po modifikacija" << endl;
    l2.print();

    cout << "Treta lista po modifikacija" << endl;
    l3.print();

    return 0;
}