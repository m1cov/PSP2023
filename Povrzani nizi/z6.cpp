#include <iostream>

using namespace std;

typedef int info_t;

struct node
{

    info_t info;
    node *prev;
    node *next;
};

struct List
{

    node *head;
    node *tail;

    void init()
    {

        head = tail = NULL;
    }

    void create_list(info_t x)
    {

        node *p = new node;
        p->info = x;
        head = tail = p;
        p->next = p->prev = p;
    }

    void insert_first(info_t x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *p = new node;

            p->info = x;
            p->next = head;
            p->prev = tail;

            head->prev = p;
            tail->next = p;

            head = p;
        }
    }

    void insert_last(info_t x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *p = new node;
            p->info = x;

            p->prev = tail;
            p->next = head;

            head->prev = p;
            tail->next = p;

            tail = p;
        }
    }

    void delete_first()
    {

        if (head != NULL)
        {

            if (head->next == NULL)
            {

                delete head;
                head = tail = NULL;
            }
            else
            {

                node *p = new node;

                p = head;
                head->next->prev = tail;
                tail->next = head->next;
                head = p->next;

                delete p;
            }
        }
    }

    void delete_last()
    {

        if (head != NULL)
        {

            if (head->next == NULL)
            {

                delete head;
                head = tail = NULL;
            }
            else
            {

                node *p = new node;

                p = tail;

                head->prev = tail->prev;
                tail = tail->prev;

                delete p;
            }
        }
    }

    void delete_poz(int x)
    {

        if (head != NULL)
        {

            node *p = head;

            do
            {

                p = p->next;
                x--;
            } while (x > 0 && p != head);

            p->prev->next = p->next;
            p->next->prev = p->prev;

            delete p;
        }
    }

    void print_list()
    {
    }
};