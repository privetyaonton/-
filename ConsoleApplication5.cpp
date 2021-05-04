#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include <math.h>
#define COLOR_RED system("color 04")
#define COLOR_YELLOW system("color 46")

struct date
{
    int day;
    int mouth;
    int year;
};

struct info
{
    int a;
    char fam[50];
    int nom;
    char kn[50];
    date r;
}ss[100];

struct info sss[100];

struct info buffer;

int n,g,aa,bb,cc,dd;

int putss(int b)
{
    int i;
    for (i = 0; i < b; i++)
    {
        printf(" ");
    }
    return 0;
}

int l()
{
    system("CLS");
    return 0;
}

int o()
{
    printf("Неправильный ввод попробуйте ещё раз\n\n");
    return 0;
}

int u(int a)
{
    int c, b, i;
    b = 0;        
    i = 0;
    while (b == 0)
    {  
        rewind(stdin);
        b = scanf_s("%d", &a);
        if (b == 0)
        {        
            rewind(stdin);
            l();
            o();
        }          
    }
    return a;
}

int raz(int a)
{
    int d,k;
    k = 0;
    d = a;
    while (d > 0)
    {
        k++;
        d = d / 10;
    }
    return k;
}

int vyvod()
{
    int i,b1,b2,b3,b4;
    l();
    b1 = 1;
    b2 = 3;
    b3 = 26;
    b4 = 14;
    for (i = 0; i < n; i++)
    {
        if (raz(i + 1) > b1)
        {
            b1 = raz(i + 1);
        }
        if (strlen(ss[i].fam) > b2)
        {
            b2 = strlen(ss[i].fam);
        }
        if (raz(ss[i].nom) > b3)
        {
            b3 = raz(ss[i].nom);
        }
        if (strlen(ss[i].kn) > b4)
        {
            b4 = strlen(ss[i].kn);
        }
    }
    aa = b1;
    bb = b2;
    cc = b3;
    dd = b4;
    printf("\033[31m№");
    putss(b1 + 4);
    printf("ФИО");
    putss(b2 + 2);
    printf("Номер читательского билета");
    putss(b3 - 21);
    printf("Название книги");
    putss(b4 - 9);
    printf("Срок сдачи\033[37m\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", i + 1);
        putss(b1 - raz(i + 1) + 5);
        printf("%s", ss[i].fam);
        putss(b2 - strlen(ss[i].fam) + 5);
        printf("%d", ss[i].nom);
        putss(b3 - raz(ss[i].nom) + 5);
        printf("%s", ss[i].kn);
        putss(b4 - strlen(ss[i].kn) + 5);
        printf("%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
    }
    return 0;
}

int hh2()
{
    int i, y, j;
    i = 0;
    y = 0;
    printf("Хотите ещё раз? (0 - да, 1 - нет)");
    j = 0;
    while (j == 0)
    {
        y = u(y);
        if (y == 0 || y == 1)
        {
            i = y;
            j = 1;
        }
        else printf("Неправильный ввод, попробуйте ещё раз");
    }
    return i;
}

int st()
{
    l();
    printf("\nТакой элемент был найден в этой структуре: \n\n");
    printf("№");
    putss(aa + 4);
    printf("ФИО");
    putss(bb + 2);
    printf("Номер читательского билета");
    putss(cc - 21);
    printf("Название книги");
    putss(dd - 9);
    printf("Срок сдачи\n");      
    return 0;
}

int sr02(int a, int n)
{
    int i, d, k;
    d = 0;
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (a == ss[i].nom)
        {
            if (d == 0)
            {
                st();
            }
            printf("\033[37m\033[40m%d", i + 1);
            putss(aa - raz(i + 1) + 5);
            printf("%s", ss[i].fam);
            putss(bb - strlen(ss[i].fam) + 5);
            printf("\033[33m\033[41m%d\033[40m", ss[i].nom);
            putss(cc - raz(ss[i].nom) + 5);
            printf("\033[37m%s", ss[i].kn);
            putss(dd - strlen(ss[i].kn) + 5);
            printf("%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);    
            d++;
        }
    }
    if (d == 0)
    {
        printf("\nТакой элемент не был найден");
    }
    return 0;
}

int sr4(int a, int b, int c, int n)
{
    int i,d;
    d = 0;
    for (i = 0; i < n; i++)
        if (ss[i].r.day == a && ss[i].r.mouth == b && ss[i].r.year == c)
        {
            if (d == 0)
            {
                st();
            }
            printf("\033[37m\033[40m%d", i + 1);
            putss(aa - raz(i + 1) + 5);
            printf("%s", ss[i].fam);
            putss(bb - strlen(ss[i].fam) + 5);
            printf("%d", ss[i].nom);
            putss(cc - raz(ss[i].nom) + 5);
            printf("%s", ss[i].kn);
            putss(dd - strlen(ss[i].kn) + 5);
            printf("\033[33m\033[41m%d %d %d\033[40m\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
            d++;
        }
    return 0;
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
            if (strcmp(a,ss[i].fam) == 0)
            {
                if (d == 0)
                {
                    st();
                }
                printf("\033[37m%d", i + 1);
                putss(aa - raz(i + 1) + 5);
                printf("\033[33m\033[41m%s\033[40m", ss[i].fam);
                putss(bb - strlen(ss[i].fam) + 5);
                printf("\033[37m%d", ss[i].nom);
                putss(cc - raz(ss[i].nom) + 5);
                printf("%s", ss[i].kn);
                putss(dd - strlen(ss[i].kn) + 5);
                printf("%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
                d++;
            }
        }
    }
    else
    {
        if (b == 3)
        {
            for (i = 0; i < n; i++)
            {
                if (strcmp(a,ss[i].kn) == 0)
                {
                    if (d == 0)
                    {
                        st();
                    }
                    printf("\033[37m%d", i + 1);
                    putss(aa - raz(i + 1) + 5);
                    printf("%s", ss[i].fam);
                    putss(bb - strlen(ss[i].fam) + 5);
                    printf("%d", ss[i].nom);
                    putss(cc - raz(ss[i].nom) + 5);
                    printf("\033[33m\033[41m%s\033[40m", ss[i].kn);
                    putss(dd - strlen(ss[i].kn) + 5);
                    printf("\033[37m%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
                    d++;
                }
            }
        }
    }
    if (d == 0)
    {
        printf("\nЭтот элемент не был найден");

    }
    return 0;
}

int sort024_up(int a, int n)
{
    int i, j, c;
    j = 0;
    i = 0;
    c = 0;
    if (a == 2)
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
                if (ss[i].nom > ss[j].nom)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
            {
                if (ss[i].r.year > ss[j].r.year)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
                else
                {
                    if (ss[i].r.mouth > ss[j].r.mouth)
                    {
                        buffer = ss[i];
                        ss[i] = ss[j];
                        ss[j] = buffer;
                    }
                    else
                    {
                        if (ss[i].r.day > ss[j].r.day)
                        {
                            buffer = ss[i];
                            ss[i] = ss[j];
                            ss[j] = buffer;
                        }
                    }
                }
            }
    }
    return 0;
}

int sort024_down(int a, int n)
{
    int i, j, c;
    j = 0;
    i = 0;
    c = 0;
    if (a == 2)
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
                if (ss[i].nom < ss[j].nom)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
            {
                if (ss[i].r.year < ss[j].r.year)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
                else
                {
                    if (ss[i].r.mouth < ss[j].r.mouth)
                    {
                        buffer = ss[i];
                        ss[i] = ss[j];
                        ss[j] = buffer;
                    }
                    else
                    {
                        if (ss[i].r.day < ss[j].r.day)
                        {
                            buffer = ss[i];
                            ss[i] = ss[j];
                            ss[j] = buffer;
                        }
                    }
                }
            }
    }
    return 0;
}

int LowCase(char* b)
{
    int i;
    for (i = 0; i < strlen(b); i++)
    {
        if (int(b[i]) >= -64 && int(b[i]) <= -33)
        {
            b[i] = b[i] + 32;
        }
    }
    return 0;
}

int sort13_up(int a, int n)
{
    int i,j,k;
    j = 0;
    k = 0;
    for (i = 0; i < n; i++)
    {
        sss[i] = ss[i];
        LowCase(sss[i].fam);
        LowCase(sss[i].kn);
    }
    if (a == 1)
    {
        for (i = 0; i<n; i++)
            for (j = i; j < n; j++)
                if (strcmp(sss[i].fam, sss[j].fam) > 0)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
                if (strcmp(sss[i].kn, sss[j].kn) > 0)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
    }
    return 0;
}

int sort13_down(int a, int n)
{
    int i, j, k, l;
    j = 0;
    k = 0;
    for (i = 0; i < n; i++)
    {
        sss[i] = ss[i];
        LowCase(sss[i].fam);
        LowCase(sss[i].kn);
    }
    if (a == 1)
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
                if (strcmp(sss[i].fam, sss[j].fam) < 0)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
            {
                l = strcmp(sss[i].kn, sss[j].kn);
                if (strcmp(sss[i].kn,sss[j].kn) < 0)
                {
                    buffer = ss[i];
                    ss[i] = ss[j];
                    ss[j] = buffer;
                }
            }

    }
    return 0;
}

int p(char *b)
{
    int a;
    a = 0;
    while (a == 0)
    {
        rewind(stdin);
        gets_s(b,50);
        if (b[0] == '\0')
        {
            o();
        }
        else
            return 0;
    }
    return 0;
}

int vvod_date(int q)
{
    int k, kk, kkk, b;
    k = 0;
    kk = 0;
    kkk = 0;
    b = 0;
    while (k == 0)
    {
        while (b == 0)
        {
            b = scanf_s("%d %d %d", &ss[q].r.day, &ss[q].r.mouth, &ss[q].r.year);
            if (b != 3)
            {
                l();
                o();
                b = 0;
            }
            else
            {
                k++;
            }
        }
        if (ss[q].r.day > 31)
        {
            o();
            continue;
        }
        else
        {
            if (ss[q].r.mouth == 1 || ss[q].r.mouth == 2 || ss[q].r.mouth == 3 || ss[q].r.mouth == 4 || ss[q].r.mouth == 5 || ss[q].r.mouth == 6 || ss[q].r.mouth == 7 || ss[q].r.mouth == 8 || ss[q].r.mouth == 9 || ss[q].r.mouth == 10 || ss[q].r.mouth == 11 || ss[q].r.mouth == 12)
            {
                if (ss[q].r.mouth == 4 || ss[q].r.mouth == 6 || ss[q].r.mouth == 9 || ss[q].r.mouth == 11)
                {
                    if (ss[q].r.day > 30)
                    {
                        o();
                        continue;
                    }
                }
                if (ss[q].r.mouth == 2)
                {
                    if (ss[q].r.day > 29)
                    {
                        o();
                        continue;
                    }
                    if (((ss[q].r.year) % 100) % 4 != 0 && ss[q].r.day > 28)
                    {
                        o();
                        continue;
                    }
                }
            }
            if (ss[q].r.year < 2021 || ss[q].r.year > 2030)
            {
                o();
                continue;
            }
        }
    }
    return 0;
}

int vvod(int q)
{
    int k, kk;    
    printf("\nФИО - ");
    p(ss[q].fam);
    printf("\n\nНомер читательского билета - ");
    ss[q].nom = u(ss[q].nom);
    printf("\n\nНазвание книги - ");
    p(ss[q].kn);
    printf("\n\nСрок возврата - ");
    k = 0;
    kk = 0;
    int kkk;
    kkk = 0;
    vvod_date(q);
    l();
    return 0;
}

int vvod_structury()
{
    int i, q, k, e, kk;
    i = 0;
    q = 0;
    k = 0;
    e = 0;
    while (i == 0)
    {
        ss[q].a = q + 1;
        printf("Читатель %d", q + 1);
        vvod(q);
        printf("Продолжить ввод? (0 - yes, 1 - no) - ");
        g = 3;
        k = u(k);
        if (k == 1)
        {
            n = q + 1;
            i = 1;
        }
        q++;
        l();
    }
    return 0;
}

int izm_fam(int b)
{
    l();
    vyvod();
    char x[100];
    printf("\nФИО - ");
    p(x);
    strcpy_s(ss[b].fam, x);
    g++;
    l();
    return 0;
}

int izm_nom(int b)
{
    l();
    vyvod();
    int q;
    q = 0;
    printf("Номер читательского билета - ");
    ss[b].nom = u(q);
    g++;
    l();
    return 0;
}

int izm_kn(int b)
{
    l();
    vyvod();
    char x[100];
    printf("\nНазвание книги - ");
    p(x);
    strcpy_s(ss[b].kn, x);
    g++;
    l();
    return 0;
}

int izm_day(int b)
{
    l();
    vyvod();
    int q;
    q = 0;
    printf("\nСрок возврата - \n");
    vvod_date(b);
    g++;
    l();
    return 0;
}

int izm_menu()
{         
    vyvod();
    int b, i, y, t, j;
    b = 0;
    i = 0;
    t = 0;
    g = 0;
    y = 0;
    j = 0;
    printf ("\nВведите номер читателя: ");
    while (i == 0)
    {
        b = u(b);
        if (b > n || b < 1)
        {
            printf("\nТакого читателя нет, попробуйте ещё раз\n");
        }
        else
            i = 1;
    }        
    b = b - 1;
    l();
    vyvod();
    printf("\nЧитатель номер %d\n", b+1);
    i = 0;
    while (i == 0)
    {    
        printf("Какой параметр хотите изменить?\n");
        printf("\n1 - ФИО\n2 - Номер читательского билета\n");
        printf("3 - Название книги\n4 - Срок сдачи книги\n");
        y = u(y);
        if (y == 1 || y == 2 || y == 3 || y == 4)
        {
            if (y == 1)
                izm_fam(b);
            if (y == 2)
                izm_nom(b);
            if (y == 3)
                izm_kn(b);
            if (y == 4)
                izm_day(b);
        }
        else
            printf("Неправильный ввод, попробуйте ещё раз");
        j = 0;
        while (j == 0)
        {
            printf("Дальнейшие действия - ");
            printf("\n1 - Вывод изменённой структуры\n2 - Изменить другой параметр этого читателя\n3 - Изменить параметры другого читателя\n");
            t = u(t);
            if (t == 1 || t == 2 || t == 3)
            {
                if (t == 1)
                {
                    return 0;
                }
                if (t == 3)
                {
                    izm_menu();
                }
            }
            else printf("Неправильный ввод, попробуйте ещё раз");
            j = 1;
        }
    }
    return 0;
}

int search_easy()
{
    l();
    vyvod();
    int b,d,k;
    b = 0;
    d = 0;
    k = 0;
    while (b == 0)
    {
        printf("\nВведите номер читательского билета: ");
        d = u(d);
        sr02(d, n);
        b = hh2();
    }
    return 0;
}

int sort_menu()
{
    l();
    vyvod();
    int c,i,j;
    int d;
    i = 0;
    j = 0;
    g = 0;
    c = 0;
    d = 0;
    while (i == 0)
    {    
        printf("\nКакую сортировку хотите сделать? (0 - по возрастанию (от А до Я), 1 - по убыванию (от Я до А) - ");
        c = u(c);
        if (c == 0 || c == 1)
        {
            printf("\nПо какому параметру хотите произвести сортировку?\n");
            printf("\n1 - ФИО\n2 - Номер читательского билета\n");
            printf("3 - Название книги\n4 - Срок сдачи книги\n");
            memcpy(sss, ss, 100 * sizeof(info));
            j = 0;
            while (j == 0)
            {
                d = u(d);
                if (d == 1 || d == 2 || d == 3 || d == 4)
                {
                    if (d == 2 || d == 4)
                    {
                        if (c == 0)
                        {
                            sort024_up(d, n);
                            g++;
                        }
                        if (c == 1)
                        {
                            sort024_down(d, n);
                            g++;
                        }
                    }
                    if (d == 1 || d == 3)
                    {
                        if (c == 0)
                        {
                            sort13_up(d, n);
                            g++;
                        }
                        if (c == 1)
                        {
                            sort13_down(d, n);
                            g++;
                        }
                    }
                }
                else printf("Неправильный ввод, попробуйте ещё раз");
                if (g != 0)
                {
                    j++;
                }
            }
        }
        else printf("Неправильный ввод, попробуйте ещё раз");
        l();
        vyvod();
        i = hh2();
    }
    return 0;
}
    
int search_hard_menu()
{
    l();
    vyvod();
    int b,d,e,i,c,k;
    char s[50];
    b = 0;
    d = 0;
    e = 0;
    i = 0;
    k = 0;
    while (b == 0)
    {
        printf("\n\nПроизведём поиск в массиве структур по любому параметру\n\n");
        printf("По какому параметру хотите произвести поиск?");
        printf("\n1 - ФИО\n2 - Номер читательского билета\n");
        printf("3 - Название книги\n4 - Срок сдачи книги\n");
        d = u(d);
        if (d == 1 || d == 2 || d == 3 || d == 4)
        {
            if (d == 2)
            {
                printf("\nВведите элемент: ");
                b = sr02(u(b), n);
            }
            else
            {
                if (d == 4)
                {
                    printf("Введите дату: \n");
                    while (k == 0)
                    {
                        k = scanf_s("%d %d %d", &e, &c, &i);
                        if (k != 1)
                        {
                            o();
                        }
                    }
                    b = sr4(e, c, i, n);
                }            
                else
                {
                    printf("Введите элемент: \n");
                    p(s);
                    b = sr13(s, d, n);
                }
            }


        }
        else
            printf("\nНеправильный ввод попробуйте ещё раз");
        b = hh2();
    }
    return 0;
}

int delete_menu()
{
    int d,b,i;
    l();
    vyvod();
    printf("\n\nПроизведём удаление одной из структур");
    printf("\nВведите номер читателя: \n");
    d = 0;
    b = 0;
    while (b == 0)
    {
        d = u(d);
        if (d > n)
        {
            o();
        }
        else b++;
    }
    for (i = 0; i < n-d; i++)
    {
        buffer = ss[d-1];
        ss[d-1] = ss[d];
        ss[d] = buffer;
        d++;
    }
    n = n - 1;
    return 0;
}

int part_search13(int a)
{
    int i, j, h, d, k;
    char b[50], c[50], e[50];
    printf("\nВведите эелемент: \n");
    p(b);
    h = 0;
    d = 0;
    for (i = 0; i < n; i++)
    {
        if (a == 1)
        {
            h = 0;
            for (j = 0; j < strlen(b); j++)
            {
                if (b[j] == ss[i].fam[j])
                    h++;
            }
            k = 0;
            for (j = strlen(b); j < strlen(ss[i].fam) + 1; j++)
            {
                e[k] = ss[i].fam[j];
                k++;
            }
            if (h == strlen(b))
            {
                if (d == 0)
                {
                    st();
                }
                printf("\033[37m%d", i + 1);
                putss(aa - raz(i + 1) + 5);
                printf("\033[33m\033[41m%s\033[40m\033", b);
                for (j = 0; j < strlen(ss[i].fam) - strlen(b); j++)
                    printf("%c", e[j]);
                putss(bb - strlen(ss[i].fam) + 5);
                printf("\033[37m%d", ss[i].nom);
                putss(cc - raz(ss[i].nom) + 5);
                printf("%s", ss[i].kn);
                putss(dd - strlen(ss[i].kn) + 5);
                printf("%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
                d++;
            }
        }
        if (a == 3)
        {
            d = 0;
            h = 0;
            for (j = 0; j < strlen(b); j++)
            {
                if (b[j] == ss[i].kn[j])
                    h++;
            }
            k = 0;
            for (j = strlen(b); j < strlen(ss[i].kn) + 1; j++)
            {
                e[k] = ss[i].kn[j];
                k++;
            }
            if (h == strlen(b))
            {
                if (d == 0)
                {
                    st();
                }
                printf("\033[37m%d", i + 1);
                putss(aa - raz(i + 1) + 5);
                printf("%s", ss[i].fam);
                putss(bb - strlen(ss[i].fam) + 5);
                printf("%d", ss[i].nom);
                putss(cc - raz(ss[i].nom) + 5);
                printf("\033[33m\033[41m%s\033[40m", b);
                for (j = 0; j < strlen(ss[i].kn) - strlen(b); j++)
                    printf("%c", e[j]);
                putss(dd - strlen(ss[i].kn) + 5);
                printf("\033[37m%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
                d++;
            }
        }
    }
    if (d == 0)
    {
        printf("\nЭтот эелемент не был найден\n");
    }
    return 0;
}

int part_search2()
{
    int i, a, k, d, ll;
    l();
    vyvod();
    k = 0;
    a = 0;
    d = 0;
    while (d == 0)
    {
        printf("\nВведите элемент\n");
        a = u(a);
        for (i = 0; i < n; i++)
            if (raz(a) > raz(ss[i].nom))
            {
                l();
                o();
                k++;
                break;
            }
        if (k == 0)
            d++;
    }
    d = 0;
    for (i = 0; i < n; i++)
    {
        if (raz(a) < raz(ss[i].nom))
        {
            k = (ss[i].nom) / pow(10, raz(ss[i].nom) - raz(a));
            if (a == k)
            {
                ll = (ss[i].nom) % int(pow(10, raz(ss[i].nom) - raz(a)));
                if (d == 0)
                {
                    st();
                }
                printf("\033[37m\033[40m%d", i + 1);
                putss(aa - raz(i + 1) + 5);
                printf("%s", ss[i].fam);
                putss(bb - strlen(ss[i].fam) + 5);
                printf("\033[33m\033[41m%d\033[40m\033[37m%d", k, ll);
                putss(cc - raz(ss[i].nom) + 5);
                printf("\033[37m%s", ss[i].kn);
                putss(dd - strlen(ss[i].kn) + 5);
                printf("%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
                d++;
            }
        }
        else
            if (a == ss[i].nom)
            {
                if (d == 0)
                {
                    st();
                }
                printf("\033[37m\033[40m%d", i + 1);
                putss(aa - raz(i + 1) + 5);
                printf("%s", ss[i].fam);
                putss(bb - strlen(ss[i].fam) + 5);
                printf("\033[33m\033[41m%d\033[40m\033[37m", ss[i].nom);
                putss(cc - raz(ss[i].nom) + 5);
                printf("\033[37m%s", ss[i].kn);
                putss(dd - strlen(ss[i].kn) + 5);
                printf("%d %d %d\n", ss[i].r.day, ss[i].r.mouth, ss[i].r.year);
                d++;
            }
    }
    if (d == 0)
    {
        printf("\nТакой элемент не был найден");
    }
    return 0;
}

int part_search4()
{
    return 0;
}

int part_search_menu()
{
    l();
    vyvod();
    int y,b;
    y = 0;
    b = 0;
    while (b == 0)
    {    
        printf("\n\n Произведём частичный поиск по любому параметру \n\n");
        printf("По какому параметру хотите произвести частичный поиск?\n1 - ФИО\n2 - Номер читательского билета\n3 - Название книги\n4 - Срок сдачи книги\n");
        y = u(y);
        if (y == 1 || y == 2 || y == 3 || y == 4)
        {
            if (y == 1 || y == 3)
            {
                part_search13(y);
            }
            if (y == 2)
            {
                part_search2();
            }
            if (y == 4)
            {
                part_search4();
            }
        }
        else
        {
            o();
        }
        b = hh2();
    }
    return 0;
}

int plus()
{
    l();
    vyvod();
    printf("\n");
    vvod(n);
    n = n + 1;
    return 0;
}

int menu()
{
    l();
    vyvod();
    printf("\nВы ввели массив струтур, что хотите с ней сделать?");
    printf("\n1 - Вывести\n2 - Добавить структуру\n3 - Изменить одну из структур\n4 - Поиск по номеру читательского билета");
    printf("\n5 - Сортировка структур по параметру\n6 - Поиск в массиве структур по параметру\n7 - Удаление структуры\n8 - Частичный поиск по любому параметру\n9 - Выход\n");
    int y,j;
    j = 0;
    y = 0;
    while (j == 0)
    {
        y = u(y);
        if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 9)
        {
            if (y == 1)
            {
                vyvod();
                menu();
            }
            if (y == 2)
            {
                plus();
                menu();
            }
            if (y == 3)
            {
                izm_menu();
                menu();
            }
            if (y == 4)
            {
                search_easy();
                menu();
            }
            if (y == 5)
            {
                sort_menu();
                menu();
            }
            if (y == 6)
            {
                search_hard_menu();
                menu();
            }
            if (y == 7)
            {
                delete_menu();
                menu();
            }
            if (y == 8)
            {
                part_search_menu();
                menu();
            }
            if (y == 9)
            {
                return 0;
            }
        }
        else printf("Неправильный ввод, попробуйте ещё раз");
    }
    return 0;
}

int main()
{   
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int q = 0;
    int i = 0;
    int a[100];
    printf("Введите структуру\n");
    vvod_structury();
    memcpy(sss, ss, 100 * sizeof(info));
    menu();
    return 0;
}