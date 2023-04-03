#include <iostream>

using namespace std;

struct node
{

    int info;
    node *link;
};

struct sll
{

    node *head, *tail;

    void init();
    void insert_last(int el);
};

struct igrac
{

    string ime, prezime;
    sll cekori;
    int poeni;
};

sll main_list;

void igra(igrac &p1, igrac &p2, sll pateka)
{

    node *i = p1.cekori.head;
    node *p = pateka.head;

    while (p != NULL && i != NULL)
    {

        int c = i->info;

        while (c > 0 && p != NULL)
        {

            p = p->link;
            c--;
        }

        if (p != NULL)
        {
            i = i->link;
            p1.poeni += p->info;
        }
    }

    i = p2.cekori.head;

    while (p != NULL && i != NULL)
    {

        int c = i->info;

        while (c > 0 && p != NULL)
        {

            p = p->link;
            c--;
        }

        if (p != NULL)
        {
            i = i->link;
            p2.poeni += p->info;
        }
    }
}

int main()
{

    igrac i1, i2;
    sll pateka;

    pateka.init();

    cout << "Vnesi broj na polinja" << endl;
    int n;
    cin >> n;
    int el;
    while (n > 0)
    {

        cin >> el;

        pateka.insert_last(el);
        n--;
    }

    cout << "Vnesi ime i prezime na igrac 1" << endl;
    cin >> i1.ime >> i1.prezime;

    cout << "Vnesi broj na potezi";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> el;
        i1.cekori.insert_last(el);
    }

    cout << "Vnesi ime i prezime na igrac 2" << endl;
    cin >> i2.ime >> i2.prezime;

    cout << "Vnesi broj na potezi";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> el;
        i2.cekori.insert_last(el);
    }

    igra(i1, i2, pateka);

    if (i1.poeni > i2.poeni)
        cout << i1.ime << " " << i1.prezime << endl;
    else if (i2.poeni > i1.poeni)
        cout << i2.ime << " " << i2.prezime << endl;
    else
    {

        cout << i1.ime << " " << i1.prezime << endl;
        cout << i2.ime << " " << i2.prezime << endl;
    }

    return 0;
}