#include <iostream>

using namespace std;

struct node
{

    int info;
    node *link;
};

struct SLList
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

    void insert_front(int x)
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

    void insert_back(int x)
    {

        if (head == NULL)
            create_list(x);
        else
        {

            node *pom = head;

            node *temp = new node;
            temp->info = x;
            temp->link = NULL;

            while (pom->link != NULL)
                pom = pom->link;

            pom->link = temp;
        }
    }
};

void func(SLList &l, int br)
{

    

}

int main()
{

    SLList lista;
    int n, el;

    lista.init();

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> el;
        lista.insert_back(el);
    }

    cin >> el;

    func(lista, el);

    return 0;
}
