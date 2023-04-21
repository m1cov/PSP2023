#include <iostream>
using namespace std;

struct node
{

    char info;
    node *prev, *next;
};

struct DPKLista
{
    node *head, *tail;

    void init();

    void create(){

    }

    void dodadiPrv(char c){

    }

    void dodadiPos(char c){

    }

    void pechati(){

    }

    void brisiLista(){

    }

};

void konvertiraj(DPKLista &l1, DPKLista &l2, char c){

}


int main()
{
    DPKLista L1, L2;
    L1.init();
    L1.dodadiPrv('m');
    L1.dodadiPos('n');
    L1.dodadiPos('o');
    L1.dodadiPos('g');
    L1.dodadiPos('u');
    L1.dodadiPos(' ');
    L1.dodadiPos('s');
    L1.dodadiPos('a');
    L1.dodadiPos('k');
    L1.dodadiPos('a');
    L1.dodadiPos('m');
    L1.dodadiPos(' ');
    L1.dodadiPos('p');
    L1.dodadiPos('s');
    L1.dodadiPos('p');

    L2.init();

    L2.dodadiPrv('d');
    L2.dodadiPos('e');
    L2.dodadiPos('s');
    L2.dodadiPos('e');
    L2.dodadiPos('t');
    L2.dodadiPos('k');
    L2.dodadiPos('a');

    konvertiraj(L1, L2, ' ');

    L1.pechati();
    L2.pechati();
    L1.brisiLista();
    L2.brisiLista();
    return 0;
}