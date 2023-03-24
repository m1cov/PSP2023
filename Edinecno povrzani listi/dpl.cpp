#include <iostream>

using namespace std;

// Dvojno povrzana niza

struct node
{

    int info;
    node *next, *prev;
};

struct dpl
{

    node *head;
    node *tail;

    void init()
    {
        head = tail = NULL;
    }

    void ins_after(node *l_ptr, int x)
    {
        node *t_ptr = new node;

        t_ptr->info = x;
        t_ptr->prev = l_ptr;
        t_ptr->next = l_ptr->next;

        if (l_ptr->next == NULL)
            tail = t_ptr;
        else
            l_ptr->next->prev = t_ptr;

        l_ptr->next = t_ptr;
    };

    void ins_before(node *l_ptr, int x)
    {

        node *t_ptr = new node;

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

        node *p_ptr = new node;

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
        node *p;

        for (p = head;;)
        {
        }
    }

    node *nodeOnPosition(int n)
    {

        node *t_ptr = head;

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
                node *temp = head;
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
                node *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
    }

    node *findFirst(int x)
    {

        node *l;

        for (l = head; l != NULL && l->info != x; l = l->next)
        {
            return (l != NULL ? l : NULL);
        }
    }

    node *findLast(int x)
    {

        node *l;

        for (l = tail; l != NULL && l->info != x; l = l->prev)
        {
            return (l != NULL ? l : NULL);
        }
    }

    void insInOrder(int x)
    {

        node *p = head;

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

struct DPKL
{
    node *head, *tail;

    void printList()
    {

        node *p;

        for (p = head; p != tail; p = p->next)
        {
            printNode(p);
        }

        printNode(p);
    }

    void printNode(node *p)
    {
        cout << p->info;
    }
};

int main()
{
}