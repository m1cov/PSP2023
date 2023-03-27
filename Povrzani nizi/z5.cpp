#include <iostream>

using namespace std;

typedef int info_t;

struct node
{

    info_t info;
    node *link;
};

struct list
{

    node *head;
    node *tail;

    inline void init() { head = tail = NULL; }

    void create(info_t x)
    {

        node *p = new node;

        p->info = x;
        head = tail = p;
        p->link = p;
    }

    void insert_first(info_t x)
    {

        if (head == NULL)
            create(x);
        else
        {
            node *p = new node;

            p->info = x;
            tail->link = p;
            p->link = head;
            head = p;
        }
    }

    void insert_last(info_t x)
    {

        if (head == NULL)
            create(x);
        else
        {

            node *p = new node;

            p->info = x;
            tail->link = p;
            p->link = head;
            tail = p;
        }
    }

    void delete_first()
    {

        if (head != NULL)
        {
            if (head->link == NULL)
            {

                delete head;
                head = tail = NULL;
            }
            else
            {

                node *p = new node;

                p = head;
                head->link = head;
                tail->link = head;

                delete head;
            }
        }
    }

    void delete_last()
    {

        if (head != NULL)
        {

            if (head->link == NULL)
            {

                delete tail;
                tail = head = NULL;
            }
            else
            {

                node *temp = new node;
                temp = head;

                while (temp->link != tail)
                {
                    temp = temp->link;
                }

                node *p = temp->link;
                tail = temp;
                temp->link = head;
                delete p;
            }
        }
    }

    void delete_list()
    {

        while (head != NULL)
        {

            delete_last();
        }
    }

    void print_list()
    {

        node *temp = new node;
        temp = head;

        do
        {

            cout << temp->link << '\t';
            temp = temp->link;
        } while (temp != head);

        cout << endl;
    }

    
};
