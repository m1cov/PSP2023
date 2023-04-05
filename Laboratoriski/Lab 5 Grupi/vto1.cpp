/* Да се имплементира функција која како аргументи добива единечно поврзана листа, а чија
задача е да ги заротира елементите на парна и непарна позиција (да се смета дека почетниот
елемент е на позиција 0). При промените да не се креираат и бришат јазли туку постојните јазли
да се прераспределат. Да се смета дека листата има парен број на елементи.

Пример:
list = |12|->|7|->|5|->|13|->|5|->|9|->NULL
Решение:
list = |7|->|12|->|13|->|5|->|9|->|5|->NULL

 */

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

    void create_list(int x)
    {

        node *temp = new node;

        temp->info = x;
        temp->link = NULL;

        head = temp;
    }

    void add_first(int x)
    {
        if (head == NULL)
            create_list(x);
        else
        {

            node *temp = new node;
            temp->info = x;
            temp->link = head;
            head = temp;
        }
    }

    void del_first()
    {

        if (head != NULL)
        {

            if (head->link == NULL)
                delete head;
            else
            {

                node *temp = head;

                head = head->link;
                delete temp;
            }
        }
    }

    void add_last(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *temp = head;
            while (temp->link != NULL)
                temp = temp->link;

            node *p = new node;
            p->info = x;
            p->link = NULL;

            temp->link = p;
        }
    }

    void del_last()
    {

        node *temp = head;

        while (temp->link->link != NULL)
            temp = temp->link;

        node *p = temp->link;

        temp->link = NULL;
        delete p;
    }

    void del_list()
    {

        while (head != NULL)
            del_last();
    }

    void del_node(node *p)
    {

        node *temp = head;
        node *prev = head;

        while (temp->link != NULL)
        {

            if (temp == p)
            {

                node *del = temp;

                prev->link = temp->link;
                delete del;

                break;
            }

            prev = temp;
            temp = temp->link;
        }
    }

    void print_list()
    {

        node *temp = head;

        while (temp != NULL)
        {

            cout << temp->info << '\t';
            temp = temp->link;
        }
    }
};

void func(sll &l)
{

    node *pom = l.head;
    node *t = pom->link;

    pom->link = t->link;
    t->link = pom;

    l.head = t;

    pom = pom;

    while (pom != NULL)
    {
        cout << pom->info << '\t';

        node *p = pom->link;
        t = pom->link->link;

        pom->link = t;
        p->link = t->link;
        t->link = p;

        if (pom->link->link->link == NULL)
            break;

        pom = p;

        /*                      int i = pom->info;

                            pom->info = pom->link->info;
                            pom->link->info = i;

                            pom = pom->link->link; Lesniot nacin */
    }

    cout << endl;
}

int main()
{

    int n, el;
    sll lista;
    lista.init();

    cin >> n;

    if (n % 2 != 0)
        return -1;

    for (int i = 0; i < n; i++)
    {
        cin >> el;
        lista.add_last(el);
    }

    func(lista);

    lista.print_list();

    return 0;
}