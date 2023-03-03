#include <stdio.h>

typedef struct p
{
    char ime[50];
    char lokacija[50];
    int vraboteni;
} restoran;

typedef struct s
{

    char ime[50];
    int br;
    restoran restorani[10];

} lanec;

void f(lanec l, int v)
{

    for (int i = 0; i < l.br; i++)
    {

        if (l.restorani[i].vraboteni < v)
        {

            printf("Restoranot se vika  %s na adresa %s\n", l.restorani[i].ime, l.restorani[i].lokacija);
        }
    }
}

int main()
{

    lanec lanci[2];
    int v = 3;

    for (int j = 0; j < 2; j++)
    {
        printf("Vnesi gi podatocite za lanecot\n");
        scanf("%s %d", lanci[j].ime, &lanci[j].br);

        for (int i = 0; i < lanci[j].br; i++)
        {
            printf("Vnesi gi podatocite za restoranot\n");
            scanf("%s %s %d", lanci[j].restorani[i].ime, lanci[j].restorani[i].lokacija, &lanci[j].restorani[i].vraboteni);
        }
    }

    f(lanci[0], v);
    f(lanci[1], v);

    return 0;
}