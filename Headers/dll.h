#include <iostream>

using namespace std;

struct DLLnode
{

    int info;
    DLLnode *next, *prev;
};

struct dll
{

    DLLnode *head;
    DLLnode *tail;

    void init()
    {
        head = tail = NULL;
    }

    void ins_after(DLLnode *l_ptr, int x)
    {
        DLLnode *t_ptr = new DLLnode;

        t_ptr->info = x;
        t_ptr->prev = l_ptr;
        t_ptr->next = l_ptr->next;

        if (l_ptr->next == NULL)
            tail = t_ptr;
        else
            l_ptr->next->prev = t_ptr;

        l_ptr->next = t_ptr;
    };

    void ins_before(DLLnode *l_ptr, int x)
    {

        DLLnode *t_ptr = new DLLnode;

        t_ptr->info = x;
        t_ptr->next = l_ptr;
        t_ptr->prev = l_ptr->prev;

        if (l_ptr->prev == NULL)
            head = t_ptr;
        else
            l_ptr->prev->next - t_ptr;

        l_ptr->prev = t_ptr;
    };

    void ins_first(int data)
    {

        DLLnode *p_ptr = new DLLnode;

        p_ptr->info = data;
        p_ptr->prev = NULL;
        p_ptr->next = head;

        if (head == NULL)
            tail = p_ptr;
        else
            head->prev = p_ptr;

        head = p_ptr;
    };

    void printList()
    {
        DLLnode *p;

        for (p = head;;)
        {
        }
    }

    DLLnode *DLLnodeOnPosition(int n)
    {

        DLLnode *t_ptr = head;

        for (int i = 0; i < n && t_ptr != NULL; i++)
        {
            t_ptr = t_ptr->next;
        }

        return t_ptr;
    }

    void mkLinkList(int n)
    {

        int data;
        init();

        while (n--)
        {
            cin >> data;
            ins_first(data);
        }
    }

    void del_first()
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
                DLLnode *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }
    }

    void del_last()
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
                DLLnode *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
    }

    DLLnode *findFirst(int x)
    {

        DLLnode *l;

        for (l = head; l != NULL && l->info != x; l = l->next)
        {
            return (l != NULL ? l : NULL);
        }
    }

    DLLnode *findLast(int x)
    {

        DLLnode *l;

        for (l = tail; l != NULL && l->info != x; l = l->prev)
        {
            return (l != NULL ? l : NULL);
        }
    }

    void insInOrder(int x)
    {

        DLLnode *p = head;

        if (x <= p->info)
            ins_first(x);
        else
        {

            while (p != NULL && p->info < x)
            {

                p = p->next;
            }
            if (p == NULL)
                ins_after(tail, x);
            else
                ins_before(p, x);
        }
    }

    void freeLinkList()
    {

        while (head != NULL)
        {
            del_first();
        }
    }
};