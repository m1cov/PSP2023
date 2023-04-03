#include <iostream>

using namespace std;

struct node
{

    int info;
    node *link;
};

struct csll
{

    node *head, *tail;

    void init()
    {

        head = tail = NULL;
    }

    void create_list(int x)
    {

        node *temp = new node;

        temp->info = x;
        temp->link = temp;

        head = tail = temp;
    }

    void insert_first(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {
            node *temp = new node;
            temp->info = x;

            temp->link = head;
            head = temp;
            tail->link = head;
        }
    }

    void insert_last(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *temp = new node;
            temp->info = x;

            tail->link = temp;
            tail = temp;
            tail->link = head;
        }
    }

    void delete_first()
    {

        if (head != NULL)
        {

            if (head->link == head)
                delete head;
            else
            {

                node *temp = head;

                head = head->link;
                tail->link = head;

                delete temp;
            }
        }
    }

    void delete_last()
    {

        if (head != NULL)
        {

            if (head->link == head)
            {

                head = tail = NULL;
                delete head;
            }
            else
            {

                node *temp = head;

                while (temp->link != tail)
                    temp = temp->link;

                temp->link = head;
                delete tail;
                tail = temp;
            }
        }
    }

    void delete_list()
    {

        while (head != NULL)
            delete_last();
    }

    void print_list()
    {

        if (head != NULL)
        {
            node *temp = head;

            cout << temp->info << '\t';
            temp = temp->link;

            while (temp != head)
            {
                cout << temp->info << '\t';
                temp = temp->link;
            }
        }
        else
            cout << "Empty\n";
    }
};

void func(csll &l, int x)
{

    node *temp = l.head;

    if (temp->info == x)
    {

        node *p = new node;
        p->info = x;

        p->link = temp->link;
        temp->link = p;

        temp = p->link;
    }
    else
        temp = temp->link;

    while (temp != l.head)
    {

        if (temp->info == x)
        {

            node *p = new node;
            p->info = x;

            p->link = temp->link;
            temp->link = p;

            temp = p->link;
        }
        else
            temp = temp->link;
    }
}

int main()
{

    int n, br;
    csll lista;

    lista.init();

    cout << "Vnesi dolzina na niza" << endl;
    cin >> n;

    cout << "Vnesi elementi na nizata" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> br;
        lista.insert_last(br);
    }

    cout << "Vnesi broj za proverka" << endl;

    func(lista, br);

    lista.print_list();

    return 0;
}