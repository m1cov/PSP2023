#include <iostream>

using namespace std;

// Dvojno povrzana niza

struct jazol
{

    int info;
    jazol *next, *prev;
};

struct dpl
{

    jazol *head;
    jazol *tail;

    void init()
    {
        head = tail = NULL;
    }
    void ins_after(jazol *l_ptr, int x)
    {
        jazol *t_ptr = new jazol;

        t_ptr->info = x;
        t_ptr->prev = l_ptr;
        t_ptr->next = l_ptr->next;

        if (l_ptr->next == NULL)
            tail = t_ptr;
        else
            l_ptr->next->prev = t_ptr;

        l_ptr->next = t_ptr;
    };
    void ins_before(jazol *l_ptr, int x)
    {

        jazol *t_ptr = new jazol;

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

        jazol *p_ptr = new jazol;

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
        jazol *p;

        for (p = head;;)
        {
        }
    }
    jazol *nodeOnPosition(int n)
    {

        jazol *t_ptr = head;

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
                jazol *temp = head;
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
                jazol *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
    }

    jazol *findFirst(int x)
    {

        jazol *l;

        for (l = head; l != NULL && l->info != x; l = l->next)
        {
            return (l != NULL ? l : NULL);
        }
    }

    jazol *findLast(int x)
    {

        jazol *l;

        for (l = tail; l != NULL && l->info != x; l = l->prev)
        {
            return (l != NULL ? l : NULL);
        }
    }

    

};

int main()
{
}