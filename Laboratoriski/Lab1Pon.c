#include <stdio.h>
#include <string.h>

typedef struct l
{
    char ime[50];
    int parcinja;
} Lek;

typedef struct a
{

    char ime[50];
    int brlekovi;
    Lek lekovi[];
} Apteka;

void dostava(Lek l[], int dolzina, Apteka *a)
{

    int i, j;

    for (i = 0; i < dolzina; i++)
    {
        int najden = 0;

        for (j = 0; j < a->brlekovi; j++)
        {
            if (strcat(a->lekovi[j].ime, l[i].ime) == 0)
            {

                najden = 1;
                a->lekovi[j].parcinja += l[i].parcinja;
            }
        }

        if (najden == 0)
        {

            a->brlekovi++;
            a->lekovi[j].parcinja = l[i].parcinja;
            strcpy(a->lekovi[j].ime, l[i].ime);
        }
    }
}

void popis(Apteka a)
{

    printf("%s ima %d lekovi\n", a.ime, a.brlekovi);

    for (int i = 0; i < a.brlekovi; i++)
    {
        printf("%s %d\n", a.lekovi[i].ime, a.lekovi[i].parcinja);
    }
}

int main()
{

    Lek l1[50], l2[50];
    Apteka apteka;
    int m, n;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
    {
        scanf("%s %d", l1[i].ime, &l1[i].parcinja);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", l2[i].ime, &l2[i].parcinja);
    }

    dostava(l1, m, &apteka);
    dostava(l2, n, &apteka);

    popis(apteka);

    return 0;
}