#include <stdio.h>

typedef struct s
{
    int re, im;
} complex;

complex soberi(complex a, complex b)
{

    complex br;

    br.re = a.re + b.re;
    br.im = a.im + b.im;

    return br;
}

complex odzemi(complex a, complex b)
{

    complex br;

    br.re = a.re - b.re;
    br.im = a.im - b.im;

    return br;
}

complex mnozenje(complex a, complex b)
{

    complex br;

    br.re = (a.re * b.re) - (a.im * b.im);
    br.im = (a.re * b.re) + (a.im * b.im);

    return br;
}

int main()
{

    complex a, b, c;

    printf("Vnesi gi kompleksnite broevi\n");
    scanf("%d %d", &a.re, &a.im);
    scanf("%d %d", &b.re, &b.im);

    c = soberi(a, b);
    printf("Zbirot e %d + %di\n", c.re, c.im);

    c = odzemi(a, b);
    printf("Razlikata e %d + %di\n", c.re, c.im);

    c = mnozenje(a, b);
    printf("Proizvodot e %d + %di\n", c.re, c.im);

    return 0;
}