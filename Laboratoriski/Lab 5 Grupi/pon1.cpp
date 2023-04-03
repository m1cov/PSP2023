#include <iostream>

using namespace std;

struct node
{

    int info;
    node *link;
};

struct SLList
{

    node *head;

    inline void init() { head = NULL; }

    void create_list(int x)
    {

        node *temp = new node;
        temp->info = x;
        temp->link = NULL;
        head = temp;
    }

    void insert_front(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *temp = new node;
            temp->info = x;
            temp->link = head;
            head = temp;
        }
    }

    void insert_back(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *pom = head;

            node *temp = new node;
            temp->info = x;
            temp->link = NULL;

            while (pom->link != NULL)
                pom = pom->link;

            pom->link = temp;
        }
    }

    void delete_front()
    {

        if (head != NULL)
        {

            if (head->link == NULL)
                delete head;
            else
            {

                node *temp = head;

                head = head->link;
                delete temp;
            }
        }
    }

    void delete_last()
    {

        if (head != NULL)
        {

            if (head->link == NULL)
                delete head;
            else
            {

                node *temp = head;

                while (temp->link->link != NULL)
                {
                    temp = temp->link;
                }

                node *del = temp->link;

                temp->link = NULL;
                delete del;
            }
        }
    }

    void delete_list()
    {

        node *temp = head;

        while (temp->link != NULL)
            delete_last();
    }

    void print_list()
    {

        node *temp = head;

        while (temp != NULL)
        {

            cout << temp->info << '\t';
            temp = temp->link;
        }
    }
};

void func(SLList &l, int br)
{

    node *dvizenje = l.head;
    node *prev = l.head;

    while (dvizenje != NULL)
    {

        if (dvizenje->info == br)
        {

            node *p = dvizenje;

            prev->link = dvizenje->link;

            dvizenje = dvizenje->link;
            delete p;
        }
        else
        {

            prev = dvizenje;
            dvizenje = dvizenje->link;
        }
    }
}

int main()
{

    SLList lista;
    int n, el;

    lista.init();

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> el;
        lista.insert_back(el);
    }

    cin >> el;

    func(lista, el);

    lista.print_list();

    return 0;
}
