#include <iostream>

using namespace std;

struct node
{

    int info;
    node *link;
};

struct edpl
{

    node *head;

    inline void init() { head = NULL; }

    void insertFirst(int x)
    {

        node *temp = new node;
        temp->info = x;
        temp->link = NULL;

        head = temp;
    }

    void insertFront(int x)
    {

        if (head == NULL)
            insertFirst(x);
        else
        {
            node *temp = new node;

            temp->info = x;
            temp->link = head;

            head = temp;
        }
    }

    void insert_last(int x)
    {

        if (head == NULL)
            insertFirst(x);
        else
        {

            node *temp = new node, *p = head;

            temp->info = x;
            temp->link = NULL;

            while (p->link != NULL)
            {
                p = p->link;
            }

            p->link = temp;
        }
    }

    void deleteFirst()
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
                node *temp = new node;

                temp = head;

                head = head->link;
                delete temp;
            }
        }
    }

    void deleteLast()
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
                node *temp = new node;
                temp = head;

                while (temp->link->link != NULL)
                    temp = temp->link;

                delete temp->link;
                temp->link = NULL;
            }
        }
    }

    void deleteList()
    {

        while (head != NULL)
            deleteLast();
    }

    void print_list()
    {

        node *temp = new node;
        temp = head;

        while (temp != NULL)
        {
            cout << temp->info << "\t";
            temp = temp->link;
        }
    }

    void insert_last(node *x)
    {

        if (head == NULL)
        {

            x->link = NULL;
            head = x;
        }
        else
        {

            node *dvizenje = head;

            while (dvizenje->link != NULL)
                dvizenje = dvizenje->link;

            dvizenje->link = x;
            x->link = NULL;
        }
    }
};

void funk(edpl &l1, edpl &l2, int a, int b)
{
    node *pom = l1.head;

    while (pom->link != NULL)
    {

        if (pom->link->info >= a && pom->link->info <= b)
        {

            node *temp = pom->link;

            pom->link = temp->link;

            l2.insert_last(temp);
        }
        else
            pom = pom->link;
    }
}
int main()
{
    edpl l1, l2;

    l1.init();
    l2.init();

    int a, b, x;
    char c;

    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cin >> b;

        l1.insert_last(b);
    }

    cout << "vnesi dva broevi\n";
    cin >> a >> b;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    l1.print_list();

    funk(l1, l2, a, b);

    cout << "\nprvata\n";
    l1.print_list();

    cout << "\nvtorata\n";
    l2.print_list();

    return 0;
}