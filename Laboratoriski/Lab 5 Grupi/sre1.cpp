#include <iostream>

using namespace std;

struct node
{

    int info;
    node *link;
};

struct sll
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

    void insertBack(int x)
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

    void PrintList()
    {

        node *temp = new node;
        temp = head;

        while (temp != NULL)
        {
            cout << temp->info << "\t";
            temp = temp->link;
        }
    }
};

void func(sll &list, int br)
{

    node *pom = list.head;

    while (pom->link != NULL)
    {

        if (pom->info == br)
        {

            node *temp = new node;

            temp->info = br;

            temp->link = pom->link;
            pom->link = temp;
            pom = temp->link;
        }
        else
            pom = pom->link;
    }
}

int main()
{

    sll list;
    int br, n;

    list.init();

    cout << "Broj za proverka | Dolzina na niza" << endl;
    cin >> br >> n;

    int x;
    for (int i = 0; i < n; i++)
    {

        cin >> x;
        list.insertBack(x);
    }

    func(list, br);

    list.PrintList();

    return 0;
}
