#include <iostream>

using namespace std;

struct student
{

    string indeks;
    int poeni;
};

typedef student info_t;

struct node
{

    info_t info;
    node *link;
};

struct sll
{

    node *head;
    void init();
    void dodadi(info_t x);
};

void func(sll lista, sll &r)
{

    r.init();
    int n = 0;
    float prosek = 0;

    node *pom = lista.head;

    while (pom->link != NULL)
    {
        n++;
        prosek += pom->info.poeni;

        pom = pom->link;
    }

    prosek /= n;

    pom = lista.head;

    while(pom->link != NULL){

        if(pom->info.poeni > prosek){

            r.dodadi(pom->info);

        }

        

    }

}

int main()
{
}