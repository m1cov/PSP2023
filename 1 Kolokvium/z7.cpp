#include <iostream>

using namespace std;

struct node
{

    int info;
    node *next, *prev;
};

struct list
{

    node *head;

    inline void init() { head = NULL; }
    void create_list(int x)
    {
    }

    void add_first(int x)
    {
    }

    void add_last(int x)
    {
    }

    void delete_first()
    {
    }

    void delete_last()
    {
    }

    void delete_list()
    {
    }

    void print_list()
    {
    }
};

void func(list &l1, list &l2)
{

    node *t1 = l1.head, *t2 = l2.head;

    while (t1 != NULL && t2 != NULL)
    {

        if (t1->info == t2->info)
        {

            node *temp = t2;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->next = t1->next;
            t1->next->prev = temp;
            t1->next = temp;
            temp->prev = t1;
        }

        t1 = t1->next;
        t2 = t2->next;
    }
}