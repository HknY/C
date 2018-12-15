#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct deneme
{
    int ilk;
    int son;
    int dizi[10];
} kuyruk1, kuyruk2;

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

void goster()
{
    system("cls");
    printf("\n");
    int i = kuyruk1.ilk;
    int j = kuyruk2.ilk;
    int sayac = 0;
    int son = 0;

    if (kuyruk1.son - kuyruk1.ilk > kuyruk2.son - kuyruk2.ilk)
        son = kuyruk1.son;
    else
        son = kuyruk2.son;

    while (sayac <= son)
    {
        if (kuyruk1.dizi[i] != -1 && kuyruk1.son > i)
        {
            printf("\t|%5d    |\t\t", kuyruk1.dizi[i]);
        }
        else if (i == kuyruk1.son)
        {
            printf("\t-----------\t\t");
        }
        else
        {
            printf("\t           \t\t");
        }

        if (kuyruk2.dizi[j] != -1 && kuyruk2.son > j)
        {
            printf("|%5d    |\n", kuyruk2.dizi[j]);
        }
        else if (j == kuyruk2.son)
        {
            printf("-----------\n");
        }
        else
        {
            printf("           \n");
        }

        i++;
        j++;
        sayac++;
    }

    delay(1);
}

void ekle(int sayi)
{
    while (kuyruk1.dizi[kuyruk1.ilk] > sayi)
    {
        kuyruk2.dizi[kuyruk2.son] = kuyruk1.dizi[kuyruk1.ilk];

        kuyruk2.son++;
        kuyruk1.ilk++;

        goster();
    }

    kuyruk1.ilk--;

    kuyruk1.dizi[kuyruk1.ilk] = sayi;

    goster();

    while (kuyruk2.ilk != kuyruk2.son)
    {
        kuyruk2.son--;
        kuyruk1.ilk--;

        kuyruk1.dizi[kuyruk1.ilk] = kuyruk2.dizi[kuyruk2.son];
        kuyruk2.dizi[kuyruk2.son] = -1;

        goster();
    }
}

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        kuyruk2.dizi[i] = -1;
    }
    for (i = 0; i < 10; i++)
    {
        kuyruk1.dizi[i] = -1;
    }

    kuyruk1.ilk = 5;
    kuyruk1.son = 5;

    kuyruk2.ilk = 5;
    kuyruk2.son = 5;

    int sayi;
    goster();
    while (sayi != -1)
    {
        if (kuyruk1.ilk != 0)
        {
            printf("Sayi Girin: ");
            scanf("%d", &sayi);

            ekle(sayi);
        }
        else
        {
            printf("Bellek Doldu");
            break;
        }
    }

    return 0;
}
