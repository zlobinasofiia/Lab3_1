#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return 0.4 * pow(x -100, 3) + 3.0 *pow(x, 2) - 0.2 * x + 200;
}

double df(double x)
{
    return 1.2 * pow(x - 100, 2) + 6.0 * x - 0.2;
}

void inputData(double *x1, double *x2, double *delta, unsigned int *N)
{
    int variant = 0;

    while (variant != 1 && variant != 2)
    {
        printf("Oberit variant (1 - za N, 2 - za delta): ");
        scanf("%d", &variant);

        if(variant != 1 && variant != 2)
        {
            printf("Pomylka! Vvedit 1 abo 2.\n");
        }
    }

    printf("Vvedit X1: ");
    scanf("%lf", x1);

    printf("Vvedit X2: ");
    scanf("%lf", x2);

    while (*x2 <= *x1)
    {
        printf("pomylka! X2 maye bytu bilshe X1.\n");

        printf("Vvedit X2 ");
        scanf("%lf", x2);
    }

    if (variant == 1)
    {
        printf("Vvedit kilkist tochok N: ");
        scanf("%u", N);

        while (*N < 2)
        {
            printf("Pomylka! N maye bytu ne menshe 2.\n");

            printf("Vvedit kilkist tochok N: ");
            scanf("%u", N);
        }

        *delta = (*x2 - *x1)/(*N - 1);
    }
    else
    {
      printf("Vvedit krok delta: ");
      scanf("%lf", delta);

      while (*delta <= 0 || *delta > (*x2 - *x1))
      {
          printf("Pomylka! Delta maye bytu bilshe 0.\n");

          printf("Vvedit krok delta: ");
          scanf("%lf", delta);
      }

      *N = (unsigned int)((*x2 - *x1)/ *delta) + 1;
    }
}

int main()
{
    double x1;
    double x2;
    double delta;

    unsigned int N;

    inputData(&x1, &x2, &delta, &N);

    system("cls");

    printf("\n");
    printf("*******************************************************\n");
    printf("*              DOSLIDZHENNYA FUNKTSIYI               *\n");
    printf("*******************************************************\n");

    printf("\nX1    = %.2lf", x1);
    printf("\nX2    = %.2lf", x2);
    printf("\nN     = %u", N);
    printf("\ndelta = %.2lf\n", delta);
}
