#include <iostream>

using namespace std;

typedef int info_t;

struct jazol
{

    info_t info;
    jazol *link;
};

struct SLL
{
    jazol *head;

    void kreirajLista(int nov)
    {

        head = new jazol;
        head->info = nov;
        head->link = NULL;
    }

    void dodadiPrv(int prv)
    {

        jazol *pom = new jazol;
        pom->info = prv;
        pom->link = head;
        head = pom;
    }

    void dodadiPosleden(int posl)
    {

        jazol *dvizenje = head;
        jazol *pom = new jazol;

        pom->info = posl;

        if (head == NULL)
            head = pom;
        else
        {
            while (dvizenje->link != NULL)
            {
                dvizenje = dvizenje->link;

                dvizenje->link = pom;
            }
        }

        pom->link = NULL;
    }

    void pechatiLista()
    {

        for (jazol *pom = head; pom != NULL; pom = pom->link)
        {

            cout << pom->info << '\t';
        }
    }

    void brisiPosleden()
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

                jazol *pom = head, *brisi;

                while (pom->link->link != NULL)
                    pom = pom->link;

                brisi = pom->link;
                pom->link = NULL;
                delete brisi;
            }
        }
    }

    void brisiPrv()
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

                jazol *pom = head;
                head = head->link;
                delete pom;
            }
        }
    }

    int listLenght()
    {

        int n = 0;

        while (head != NULL)
        {
            n++;
        }

        return n;
    }

    void insert(jazol *j, int data)
    {

        jazol *pom = new jazol;
        pom->info = data;
        pom->link = j->link;
        j->link = pom;
    }

    void deleteAfter(jazol *ja)
    {

        if (ja->link == NULL)
            return;

        jazol *tmp = ja->link;
        ja->link = tmp->link;
        delete tmp;
    }

    void spojuvanje(jazol *a, jazol *b)
    {

        if ((a != NULL) && (b != NULL))
        {

            if (a->link == NULL)
            {

                a->link = b;
            }
            else
                spojuvanje(a->link, b);
        }
    }
};

struct KruznaLista
{
    jazol *head;
    jazol *opas;
    int brojElementi;

    void init()
    {
        head = opas = NULL;
        brojElementi = 0;
    }

    void kreirajLista(int nov){

        jazol *pom = new jazol;
        

    }

};

int main()
{
    /* Normalna lista
        int *lista = new int[100];
        int *pom = new int[10];

        for (int i = 0; i < 10; i++)
        {
            pom[i] = lista[i];
        }

        delete[] lista;

        lista = new int[10];

        for (int i = 0; i < 10; i++)
        {
            lista[i] = pom[i];
        } */

    SLL l1;

    l1.kreirajLista(5);
}
