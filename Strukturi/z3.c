#include <stdio.h>

typedef struct s
{

    char ime[30];
    char prezime[30];
    int index[2];
    int poeni;

} student;

int main()
{

    student lista[100];
    int n;
    int p1, p2, p3, p4;

    printf("Vnesi broj na studenti\n");
    scanf("%d", &n);

    // Vnesi podatoci za site studenti
    printf("Vnesi podatoci za studentite eden po eden");
    for (int i = 0; i < n; i++)
    {

        scanf("%s %s %d %d %d %d %d $d", lista[i].ime, lista[i].prezime, &lista[i].index[0], &lista[i].index[1], &p1, &p2, &p3, &p4);
        lista[i].poeni = p1 + p2 + p3 + p4;
    }

    // Sortiraj gi po poeni
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (lista[j].poeni > lista[i].poeni)
            {

                student temp;
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }

    // Pecati gi studentite sortirani po p
    for (int i = 0; i < n; i++)
    {

        printf("%s %s, %d/%d, %d\n", lista[i].prezime, lista[i].ime, lista[i].index[0], lista[i].index[1], lista[i].poeni);
    }

    return 0;
}