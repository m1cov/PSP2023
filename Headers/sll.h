#include <iostream>

using namespace std;

typedef int info_t;

struct SLLnode
{

    info_t info;
    SLLnode *link;
};

struct sll
{
    SLLnode *head;

    void create_list(int nov)
    {

        head = new SLLnode;
        head->info = nov;
        head->link = NULL;
    }

    void insert_first(int prv)
    {

        SLLnode *temp = new SLLnode;
        temp->info = prv;
        temp->link = head;
        head = temp;
    }

    void insert_last(int posl)
    {

        SLLnode *dvizenje = head;
        SLLnode *temp = new SLLnode;

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

        for (SLLnode *temp = head; temp != NULL; temp = temp->link)
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

                SLLnode *temp = head, *del;

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

                SLLnode *temp = head;
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

    void insert(SLLnode *p, int data)
    {

        SLLnode *temp = new SLLnode;
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }

    void delete_after(SLLnode *p)
    {

        if (p->link == NULL)
            return;

        SLLnode *tmp = p->link;
        p->link = tmp->link;
        delete tmp;
    }
};
