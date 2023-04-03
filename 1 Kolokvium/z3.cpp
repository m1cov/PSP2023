#include <iostream>

using namespace std;

struct node
{

    node *link;
    int info;
};

struct sll
{

    node *head, *tail;

    void init()
    {
        head = tail = NULL;
    }
};

int mozniPremini[10] = {2, 5, 7, 4, 8, 2, 6, 9, 3, 1};

void func(sll &l, int x)
{

    node *pom = l.head;
    int i = 0;

    node *prev = l.head;

    while (x > 0)
    {

        int z = mozniPremini[i];
        bool premin = false;

        do
        {

            prev = pom;
            pom = pom->link;
            z--;

            if (pom == l.head)
                x--;
        } while (z > 0);

        node *d = new node;
        d->info = pom->info;

        prev->link = d;
        d->link = pom;

        if (pom == l.head)
        {

            l.head = d;
            l.tail->link = d;
        }

        i++;
    }
}
int main()
{
}