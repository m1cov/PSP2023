#include <iostream>

using namespace std;

typedef int info_t;

struct node
{

    info_t info;
    node *link;
};

struct SLL
{
    node *head;

    void create_list(int nov)
    {

        head = new node;
        head->info = nov;
        head->link = NULL;
    }

    void insert_first(int prv)
    {

        node *temp = new node;
        temp->info = prv;
        temp->link = head;
        head = temp;
    }

    void insert_last(int posl)
    {

        node *dvizenje = head;
        node *temp = new node;

        temp->info = posl;

        if (head == NULL)
            head = temp;
        else
        {
            while (dvizenje->link != NULL)
            {
                dvizenje = dvizenje->link;

                dvizenje->link = temp;
            }
        }

        temp->link = NULL;
    }

    void print_list()
    {

        for (node *temp = head; temp != NULL; temp = temp->link)
        {

            cout << temp->info << '\t';
        }
    }

    void delete_last()
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

                node *temp = head, *del;

                while (temp->link->link != NULL)
                    temp = temp->link;

                del = temp->link;
                temp->link = NULL;
                delete del;
            }
        }
    }

    void delete_first()
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

                node *temp = head;
                head = head->link;
                delete temp;
            }
        }
    }

    int list_length()
    {

        int n = 0;

        while (head != NULL)
        {
            n++;
        }

        return n;
    }

    void insert(node *p, int data)
    {

        node *temp = new node;
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }

    void delete_after(node *p)
    {

        if (p->link == NULL)
            return;

        node *tmp = p->link;
        p->link = tmp->link;
        delete tmp;
    }
};
