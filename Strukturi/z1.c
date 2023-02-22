#include <stdio.h>
#include <math.h>

typedef struct s
{
    int x, y;
} Tocka;

int rastojanie(Tocka t1, Tocka t2)
{

    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t2.y, 2));
}

int main()
{
    Tocka t1, t2, t3;
    int a, b, c, L;

    printf("Vnesi gi koordinatite na triagolnikot\n");
    scanf("%d %d", &t1.x, &t1.y);
    scanf("%d %d", &t2.x, &t2.y);
    scanf("%d %d", &t3.x, &t3.y);

    a = rastojanie(t1, t2);
    b = rastojanie(t2, t3);
    c = rastojanie(t3, t1);
    L = a + b + c;

    if ((a + b) > c && (a + c) > b && (b + c) > a)
        printf("Parametarot na triagolnikot e %d", L);

    return 0;
}