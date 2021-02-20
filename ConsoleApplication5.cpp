#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

struct info
{
    int a;
    char fam[100];
    int nom;
    char kn[100];
    int day;
}*ss;

struct info* sss;





int vvod(int a)
{
    scanf_s("%d", &a);
    return (a);
}

int qq()
{
    int b,i,c;
    c = 0;
    b = 0;
    printf("\nHotite eshe paz? (0 - yes, 1 - no)");
    i = 0;
    while (i == 0)
    {
        b = vvod(c);
        if (b == 0 || b == 1)
        {
            return b;
            i = 1;
        }
        else
        {
            printf("\nNepravil'nyy vvod, poprobuyte eshe raz");
        }
    }
}

int sr024(int a, int b, int n)
{
    int i,d;
    d = 0;
    if (b == 0)
    {
        for (i = 0; i < n; i++)
        {
            if (a == (ss + i)->a)
            {
                printf("\nTakoy element byl nayden v etoy structure: \n");
                printf("\n%d %s %d %s %d sutok\n", (ss + i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
                d++;
            }
        }
        if (d != 0)
            return qq();
    }
    else
    {
        if (b == 2)
        {
            for (i = 0; i < n; i++)
            {
                if (a == (ss + i)->nom)
                {
                    printf("\nTakoy element byl nayden v etoy structure: \n");
                    printf("\n%d %s %d %s %d sutok\n", (ss + i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
                    d++;
                }
            }
            if (d != 0)
                return qq();
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (a == (ss + i)->day)
                {
                    printf("\nTakoy element byl nayden v etoy structure: \n");
                    printf("\n%d %s %d %s %d sutok\n", (ss + i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
                    d++;
                }
            }
            if (d != 0)
                return qq();
        }
    }
    if (d == 0)
    {
        printf("\nEtot element ne byl naiden");
        return qq();
    }
}

int sr13(char* a, int b, int n)
{
    int i,j,c,d;
    j = 0;
    c = 0;
    d = 0;
    if (b == 1)
    {
        for (i = 0; i < n; i++)
        {
            while (a[j] != '\0')
            {
                if (a[j] == (ss + i)->fam[j])
                    c++;
                else
                {
                    c = 0;
                    break;
                }
                j++;
            }
            if (c != 0)
            {
                printf("\nTakoy element est' v takoy structure:");
                printf("\n%d %s %d %s %d sutok\n", (ss + i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
                d++;
            }
        }
        if (d != 0)
            return qq();
    }
    else
    {
        if (b == 3)
        {
            for (i = 0; i < n; i++)
            {
                while (a[j] != '\0')
                {
                    if (a[j] == (ss + i)->kn[j])
                        c++;
                    else
                    {
                        c = 0;
                        break;
                    }
                    j++;
                }
                if (c != 0)
                {
                    printf("\nTakoy element esy' v takoy structure:");
                    printf("\n%d %s %d %s %d sutok\n", (ss + i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
                    d++;
                }
            }
            if (d != 0)
                return qq();
        }
    }
    if (d == 0)
    {
        printf("\nEtot element ne byl naiden");
        return qq();
    }
}

int sort24_up(int a, int n)
{
    int i, j, c;
    j = 0;
    i = 0;
    c = 0;
    if (a == 2)
    {
        for (i = 0; i< n; i++)
            for (j = i; j< n; j++)
                if ((ss + i)->nom < (ss + j)->nom)
                {
                    c = (ss + i)->nom;
                    (ss + i)->nom = (ss + j)->nom;
                    (ss + j)->nom = c;
                }
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
                if ((ss + i)->day < (ss + j)->day)
                {
                    c = (ss + i)->day;
                    (ss + i)->day = (ss + j)->day;
                    (ss + j)->day = c;
                }
    }
}

int ww()
{
    int a, b, i;
    b = 0;
    a = 0;
    i = 0;
    while (i == 0)
    {
        a = vvod(b);
        if (a != 0 || a != 1)
            printf("\nNepravil'nyy vvod, poprobuyte eshe raz");
        else
            return a;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    ss = NULL;
    ss = (info*)calloc(100, sizeof(info));
    sss = NULL;
    sss = (info*)calloc(100, sizeof(info));
    memcpy(sss, ss, 100 * sizeof(info));
    int q = 0;
    int i = 0;
    int n,b;
    int a[100];
    printf("Vvedem structuru");
    while (i == 0)
    {
        (ss + q)->a = q + 1;
        printf("\nChitatel' nomer %d", q + 1);
        printf("\nFIO - ");
        gets_s((ss + q)->fam);
        printf("\nNomer chitatelskogo bileta - ");
        scanf_s("%d", &(ss + q)->nom);
        getchar();
        printf("\nNazvanie knigi - ");
        gets_s((ss + q)->kn);
        printf("\nSrok vozvrata - ");
        scanf_s("%d", &(ss + q)->day);
        printf("\nProdolzhit' vvod? (0 - yes, 1 - no) - ");
        scanf_s("%d", &a[q]);
        getchar();
        if (a[q] == 1)
        {
            n = q + 1;
            i = 1;
        }
        q++;
    }
    printf("\nVvedennaya structura: ");
    printf("\nNOMER FIO BILET NAZVANIE SROK\n");
    for (i = 0; i < n; i++)
        printf("%d %s %d %s %d sutok\n", (ss+i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
    int d;
    d = 0;
    b = 0;
    printf("\nHotite izmenit' structuru (0 - yes, 1 - no) - ");
    b = ww();
    while (b == 0)
    {
        printf("\n\nIzmenenie structury:\n\nVvedite nomer chitatelya: ");
        i = 0;
        while (i == 0)
        {
            d = vvod(q);
            if (d > n)
            {
                printf("Takogo chitatelya net, poprobuyte eshe raz");
            }
            else
                i = 1;
        }
        d = d - 1;
        printf("\nChitatel' nomer %d", d + 1);
        getchar();
        printf("\nFIO - ");
        gets_s((ss + d)->fam);
        printf("\nNomer chitatelskogo bileta - ");
        scanf_s("%d", &(ss + d)->nom);
        getchar();
        printf("\nNazvanie knigi - ");
        gets_s((ss + d)->kn);
        printf("\nSrok vozvrata - ");
        scanf_s("%d", &(ss + d)->day);
        getchar();
        printf("\nIzmenennaya structura: ");
        printf("\nNOMER FIO BILET NAZVANIE SROK\n");
        for (i = 0; i < n; i++)
            printf("%d %s %d %s %d sutok\n", (ss + i)->a, (ss + i)->fam, (ss + i)->nom, (ss + i)->kn, (ss + i)->day);
        printf("\nHoitite eshe raz? (yes - 0, no - 1)\n");
        d = vvod(q);
        if (d == 1)
        {
            b = 1;
        }
    }
    printf("\nHotite proizvesti poisk po nomeru chitatl'skogo bileta? (0 - yes, 1 - no) - ");
    b = ww();
    while (b == 0)
    {
        printf("\nVvedite nomer chitatel'skogo bileta: ");
        d = vvod(q);
        b = sr024(d, 0, n);
    }
    char* s;
    int c;
    s = (char*)malloc(100 * sizeof(char));  
    printf("\nHotite proizvesti sortirovku? (0 - yes, 1 - no");
    b = ww();
    c = 0;
    while (b == 0)
    {
        printf("\nKakuy sortirovku hotite sdelat'? (0 - po vosrastaniyu, 1 - po ubyvaniyu) - ");
        c = ww();
        printf("\nPo kakomu parametru hotite proizvesti sortirovku?\n");
        printf("\n1 - FIO\n2 - Nomer chitatel'skogo bileta\n");
        printf("3 - Nazvanie knigi\n4 - Srok sdachi knigi\n");
        d = vvod(q);
        if (d == 1 || d == 2 || d == 3 || d == 4)
        {
            if (d == 2 || d == 4)
            {
                if (c == 0)
                    sort24_up(d, n);

            }
        }

    }
        






    printf("\nHotite proizvesti poisk po vsem parametram? (0 - yes, 1 - no) - ");
    b = ww();
    while (b == 0)
    {
        printf("\n\nProizvedem poisk v massive structur po lubomu parametru");
        printf("Po kakomu parametru hotite proizvesti poisk?\n0 - nomer po poryadku");
        printf("\n1 - FIO\n2 - Nomer chitatel'skogo bileta\n");
        printf("3 - Nazvanie knigi\n4 - Srok sdachi knigi\n");
        d = vvod(q);
        if (d == 0 || d == 1 || d == 2 || d == 3 || d == 4)
        {
            if (d == 0 || d == 2 || d == 4)
            {
                printf("\nVvedite element: ");
                scanf_s("%d", &c);
                b = sr024(c, d, n);
            }
            else
            {
                printf("Vvedite element: ");
                getchar();
                gets_s(s,100);
                b = sr13(s, d, n);
            }
        }
        else
            printf("\nNepravil'nyy vvod, poprobuyte eshe raz");
    }

    

    



}


