#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>


union feature{
	struct input1
	{
		char name_father1[50];
		char name_mother1[50];
		char name_brother1[50];
	}input_union1;
	struct input2
	{
		char name_father2[50];
		char name_mother2[50];
		char name_brother2[50];
		char name_sister2[50];
	}input_union2;
	struct input3
	{
		char name_mother3[50];
		char name_brother3[50];
		char name_sister3[50];
	}input_union3;
}family;

struct info
{
	char surname[50];
	char name[50];
	char patronymic[50];
	feature family;
}student[50];

int	point[50], base_indent1, base_indent2, base_indent3, base_indent4, base_indent5;

info buffer;

info copy[50];

int n;

void l()
{
	system("CLS");
	return;
}

void o()
{
	printf("\nНеправильный ввод, попробуйте ещё раз\n");
	return;
}

int u(int a)
{
	int i,b;
	i = 0;
	while (i == 0)
	{
		b = scanf_s("%d", &a);
		rewind(stdin);
		if (b != 1)
		{
			o();
		}
		else
			i = 1;
	}
	return a;
}

void p(char* b)
{
	rewind(stdin);
	gets_s(b, 50);
	return;
}

void putss(int a)
{
	int i;
	for (i = 0; i < a; i++)
		printf(" ");
	return;
}

char cc[50];

char* cu(int a, int b, int i)
{
	if (a == 1)
	{
		if (b == 1)
		{
			strcpy_s(cc, student[i].family.input_union1.name_father1);
		}
		if (b == 2)
		{
			strcpy_s(cc, student[i].family.input_union1.name_mother1);
		}
		if (b == 3)
		{
			strcpy_s(cc, student[i].family.input_union1.name_brother1);
		}
	}
	if (a == 2)
	{
		if (b == 1)
		{
			strcpy_s(cc, student[i].family.input_union2.name_father2);
		}
		if (b == 2)
		{
			strcpy_s(cc, student[i].family.input_union2.name_mother2);
		}
		if (b == 3)
		{
			strcpy_s(cc, student[i].family.input_union2.name_brother2);
		}
		if (b == 4)
		{
			strcpy_s(cc, student[i].family.input_union2.name_sister2);
		}
	}
	if (a == 3)
	{
		if (b == 2)
		{
			strcpy_s(cc, student[i].family.input_union3.name_mother3);
		}
		if (b == 3)
		{
			strcpy_s(cc, student[i].family.input_union3.name_brother3);
		}
		if (b == 4)
		{
			strcpy_s(cc, student[i].family.input_union3.name_sister3);
		}
	}
	return cc;
}

void cu1 (int a, int b, int i)
{
	if (a == 1)
	{
		if (b == 1)
		{
			strcpy_s(student[i].family.input_union1.name_father1, cc);
		}
		if (b == 2)
		{
			strcpy_s(student[i].family.input_union1.name_mother1, cc);
		}
		if (b == 3)
		{
			strcpy_s(student[i].family.input_union1.name_brother1, cc);
		}
	}
	if (a == 2)
	{
		if (b == 1)
		{
			strcpy_s(student[i].family.input_union2.name_father2, cc);
		}
		if (b == 2)
		{
			strcpy_s(student[i].family.input_union2.name_mother2, cc);
		}
		if (b == 3)
		{
			strcpy_s(student[i].family.input_union2.name_brother2, cc);
		}
		if (b == 4)
		{
			strcpy_s(student[i].family.input_union2.name_sister2, cc);
		}
	}
	if (a == 3)
	{
		if (b == 2)
		{
			strcpy_s(student[i].family.input_union3.name_mother3, cc);
		}
		if (b == 3)
		{
			strcpy_s(student[i].family.input_union3.name_brother3, cc);
		}
		if (b == 4)
		{
			strcpy_s(student[i].family.input_union3.name_sister3, cc);
		}
	}
	return;
}

void output_titel()
{
	printf("\033[31mНомер");
	putss(5);
	printf("Фамилия");
	putss(base_indent1 - 2);
	printf("Имя");
	putss(base_indent2 + 2);
	printf("Отчество");
	putss(base_indent3 - 3);
	printf("Объединение\n");
	return;
}

char cc1[50];

char* cut(int b)
{
	if (b == 1)
		strcpy_s(cc1, "Отец");
	if (b == 2)
		strcpy_s(cc1, "Мать");
	if (b == 3)
		strcpy_s(cc1, "Брат");
	if (b == 4)
		strcpy_s(cc1, "Сестра");
	return cc1;
}

int cun(int a, int b)
{
	if (a == 3)
		b++;
	return b;
}

void output_inion(int i)
{
	int q, j;
	if (point[i] == 1 || point[i] == 3)
	{
		for (q = 1; q < 4; q++)
		{
			cu(point[i], cun(point[i], q), i);
			cut(cun(point[i], q));
			printf("%s (%s)   ", cc, cc1);
		}
	}
	if (point[i] == 2)
	{
		for (q = 1; q < 5; q++)
		{
			cu(point[i], q, i);
			cut(q);
			printf("%s (%s)   ", cc, cc1);
		}
	}
	printf("\n");
}

void output_struct(int i)
{
	printf("\033[0m%d", i + 1);
	putss(9);
	printf("\033[0m%s", student[i].surname);
	putss(base_indent1 + 5 - strlen(student[i].surname));
	printf("%s", student[i].name);
	putss(base_indent2 + 5 - strlen(student[i].name));
	printf("%s", student[i].patronymic);
	putss(base_indent3 + 5 - strlen(student[i].patronymic));
	output_inion(i);
}

void output()
{
	int i, q;
	for (i = 0; i < n; i++)
	{
		if (strlen(student[i].surname) > base_indent1)
			base_indent1 = strlen(student[i].surname);
		if (strlen(student[i].name) > base_indent2)
			base_indent2 = strlen(student[i].name);
		if (strlen(student[i].patronymic) > base_indent3)
			base_indent3 = strlen(student[i].patronymic);
	}
	output_titel();
	for (i = 0; i < n; i++)
	{
		output_struct(i);
	}
	return;
}

int repeat()
{
	int a, i;
	a = 0;
	i = 0;
	printf("\nХотите продолжить?\n1 - Да\n2 - Нет\n");
	while (i == 0)
	{
		a = u(a);
		if (a == 1 || a == 2)
		{
			return a - 1;
		}
	}
	return 0;
}

void input_surname(int i)
{
	printf("Фамилия - ");
	p(student[i].surname);
	return;
}

void input_name(int i)
{
	printf("\nИмя - ");
	p(student[i].name);
	return;
}

void input_patronymic(int i)
{
	printf("\nОтчество - ");
	p(student[i].patronymic);
	return;
}

void input_name_father(char* a)
{
	printf("\nИмя отца - ");
	p(a);
	return;
}

void input_name_mother(char* a)
{
	printf("\nИмя матери - ");
	p(a);
	return;
}

void input_name_brother(char* a)
{
	printf("\nИмя брата - ");
	p(a);
	return;
}

void input_name_sister(char* a)
{
	printf("\nИмя сестры - ");
	p(a);
	return;
}

void input_union_menu(int a, int i)
{
	if (a == 1)
	{
		input_name_father(student[i].family.input_union1.name_father1);
		input_name_mother(student[i].family.input_union1.name_mother1);
		input_name_brother(student[i].family.input_union1.name_brother1);
	}
	if (a == 2)
	{
		input_name_father(student[i].family.input_union2.name_father2);
		input_name_mother(student[i].family.input_union2.name_mother2);
		input_name_brother(student[i].family.input_union2.name_brother2);
		input_name_sister(student[i].family.input_union2.name_sister2);
	}
	if (a == 3)
	{
		input_name_mother(student[i].family.input_union3.name_mother3);
		input_name_brother(student[i].family.input_union3.name_brother3);
		input_name_sister(student[i].family.input_union3.name_sister3);
	}
}

void input_struct(int i)
{
	int k, j, voice, voice1;
	k = 0;
	voice = 0;
	voice1 = 0;
	j = 0;
	while (j == 0)
	{
		printf("Тип вводимой информации\n1 - Структура без объединения\n2 - структура с объединением\n");
		voice = u(voice);
		if (voice == 1 || voice == 2)
		{
			j++;
			if (voice == 2)
			{
				while (k == 0)
				{
					printf("\nВыберите тип семьи:\n1 - Отец, Мать, Брат\n2 - Отец, Мать, Брат, Сестра\n3 - Мать, Брат, Сестра\n");
					voice1 = u(voice1);
					if (voice1 == 1 || voice1 == 2 || voice1 == 3)
					{
						k++;
						point[i] = voice1;
					}
					else
					{
						o();
					}
				}
			}
			if (voice == 1)
			{
				point[i] = 0;
			}
		}
		else o;
	}
	printf("Студент номер %d\n", i + 1);
	input_surname(i);
	input_name(i);
	input_patronymic(i);
	if (voice == 2)
	{
		input_union_menu(voice1, i);
	}
	return;
}

void input()
{
	int q, k;
	k = 0;
	q = 0;
	while (k == 0)
	{
		l();
		input_struct(q);
		n++;
		k = repeat();
		if (k == 0)
		{
			q++;
		}
	}
	return;
}

void plus()
{
	l();
	output();
	printf("\nОсуществим добавление структуры\n");
	input_struct(n);
	n++;
	return;
}

void editing_struct_menu()
{
	l();
	output();
	printf("\nОсуществим изменение структуры\n");
	int i, y, k, q, d, r;
	d = 0;
	i = 0;
	y = 0;
	k = 0;
	r = 0;
	while (i == 0)
	{
		printf("\nВведите номер структуры\n");
		k = u(k);
		if (k > n)
		{
			o();
			continue;
		}
		else
		{
			k--;
			break;
		}
	}
	while (i == 0)
	{
		l();
		output();
		printf("Какой параметр хотите изменить?\n");
		printf("1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Объединение\n");
		y = u(y);
		if (y == 1 || y == 2 || y == 3 || y == 4)
		{
			if (y == 1)
			{
				input_surname(k);
			}
			if (y == 2)
			{
				input_name(k);
			}
			if (y == 3)
			{
				input_patronymic(k);
			}
			if (y == 4)
			{
				printf("\nКакой параметр объединения хотите изменить?\n");
				if (point[k] == 1 || point[k] == 3)
				{
					for (q = 1; q < 4; q++)
					{
						printf("%d - %s\n", q, cut(cun(point[k], q)));
					}
					r = 0;
					while (r == 0)
					{
						d = u(d);
						if (d == 1 || d == 2 || d == 3)
						{
							r++;
						}
						else
						{
							o();
						}
					}
				}
				if (point[k] == 2)
				{
					for (q = 1; q < 5; q++)
					{
						printf("%d - %s\n", q, cut(q));
					}
					while (r == 0)
					{
						d = u(d);
						if (d == 1 || d == 2 || d == 3 || d == 4)
						{
							r++;
						}
						else
						{
							o();
						}
					}
				}
				d = cun(point[k], d);
				cu(point[k], d, k);
				if (d == 1)
					input_name_father(cc);
				if (d == 2)
					input_name_mother(cc);
				if (d == 3)
					input_name_brother(cc);
				if (d == 4)
					input_name_sister(cc);
				cu1(point[k], d, k);
			}
		}
		else
		{
			o();
			continue;
		}
		l();
		output();
		i = repeat();
	}
	return;
}

char* gg(int a, int i)
{
	if (a == 1)
		return student[i].surname;
	else
	{
		if (a == 2)
				return student[i].name;
		else
		{
			return student[i].patronymic;
		}
	}
}

void ii(int i)
{
	printf("\033[0m%s", student[i].surname);
	putss(base_indent1 + 5 - strlen(student[i].surname));
	printf("%s", student[i].name);
	putss(base_indent2 + 5 - strlen(student[i].name));
	printf("%s", student[i].patronymic);
	putss(base_indent3 + 5 - strlen(student[i].patronymic));
	return;
}

int output_search_full(int c, int i, char* e, char* f, char* b, int a)
{
	int d, q;
	d = 0;
	if (c == 1)
	{
		if (strcmp(b, e) == 0)
		{
			output_titel();
			printf("\033[0m%d", i + 1);
			putss(9);
			printf("\033[33m\033[41m%s\033[0m%s", e, f);
			putss(base_indent1 + 5 - strlen(student[i].surname));
			printf("%s", student[i].name);
			putss(base_indent2 + 5 - strlen(student[i].name));
			printf("%s", student[i].patronymic);
			putss(base_indent3 + 5 - strlen(student[i].patronymic));
			output_inion(i);
			d++;
		}
	}
	if (c == 2)
	{
		if (strcmp(b, e) == 0)
		{
			output_titel();
			printf("\033[0m%d", i + 1);
			putss(9);
			printf("\033[0m%s", student[i].surname);
			putss(base_indent1 + 5 - strlen(student[i].surname));
			printf("\033[33m\033[41m%s\033[0m%s", e, f);
			putss(base_indent2 + 5 - strlen(student[i].name));
			printf("%s", student[i].patronymic);
			putss(base_indent3 + 5 - strlen(student[i].patronymic));
			output_inion(i);
			d++;
		}
	}
	if (c == 3)
	{
		if (strcmp(b, e) == 0)
		{
			output_titel();
			printf("\033[0m%d", i + 1);
			putss(9);
			printf("\033[0m%s", student[i].surname);
			putss(base_indent1 + 5 - strlen(student[i].surname));
			printf("%s", student[i].name);
			putss(base_indent2 + 5 - strlen(student[i].name));
			printf("\033[33m\033[41m%s\033[0m%s", e, f);
			putss(base_indent3 + 5 - strlen(student[i].patronymic));
			output_inion(i);
			d++;
		}
	}
	if (c == 4)
	{
		if (strcmp(b, e) == 0)
		{
			output_titel();
			ii(i);
			if (point[i] == 1 || point[i] == 3)
			{
				for (q = 1; q < a; q++)
				{
					printf("%s (%s)  ", cu(point[i], cun(point[i], q), i), cut(cun(point[i], q)));
				}
				printf("\033[41m\033[33m%s\033[0m (%s)   ", cu(point[i], a, i), cut(a));
				for (q = a + 1; q < 4; q++)
				{
					printf("%s (%s)  ", cu(point[i], cun(point[i], q), i), cut(cun(point[i], q)));
				}
			}
			if (point[i] == 2)
			{
				for (q = 1; q < 5; q++)
				{
					printf("%s (%s)   ", cu(point[i], q, i), cut(q));
				}
				printf("\033[41m\033[33m%s\033[0m (%s)   ", cu(point[i], a, i), cut(a));
				for (q = a + 1; q < 5; q++)
				{
					printf("%s (%s)  ", cu(point[i], cun(point[i], q), i), cut(cun(point[i], q)));
				}
			}
		}
	}
	return d;
}

void easy_search(int a, int c, int r)
{
	char b[50];
	int i, k, d, t;
	t = c;
	k = 0;
	char f[50];
	strcpy_s(f,"\0");
	l();
	output();
	printf("\nПроизведём полный поиск");
	while (k == 0)
	{
		d = 0;	
		if (a == 0)
		{
			printf("\nВведите элемент:\n");
			p(b);
			for (i = 0; i < n; i++)
			{
				d += output_search_full(c, i, b, f, gg(t, i), 0);
			}
		}
		else
		{
			printf("\nВведите элемент:\n");
			p(b);
			for (i = 0; i < n; i++)
			{
				cu(point[i], r, i);
				d += output_search_full(c, i, b, f, cc, r);
			}
		}
		if (d == 0)
		{
			l();
			output();
			printf("\nТакого элемента не было найдено\n");
			continue;
		}
		else
		{
			k++;
		}
	}
	return;
}

void easy_search_menu()
{
	l();
	output();
	int y, k, d, r, i, t;
	t = 0;
	d = 0;
	y = 0;
	k = 0;
	while (k == 0)
	{
		printf("\nПо какому параметру хотите произвести поиск?\n");
		printf("1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Объединение\n");
		y = u(y);
		if (y == 1 || y == 2 || y == 3 || y == 4)
		{
			if (y == 1)
			{
				easy_search(0, 1, 0);
			}
			if (y == 2)
			{
				easy_search(0, 2, 0);
			}
			if (y == 3)
			{
				easy_search(0, 3, 0);
			}
			if (y == 4)
			{
				r = 0;
				printf("\nПо какому члену семьи хотите произвести поиск?\n1 - Отец\n2 - Мать\n3 - Брат\n4 - Сестра\n");
				while (r == 0)
				{
					d = u(d);
					if (d == 1 || d == 2 || d == 3 || d == 4)
					{
						r++;
					}
					else
					{
						o();
					}
				}
				easy_search(1, 4, d);
			}
		}
		else
		{
			o();
			continue;
		}
		k = repeat();
	}
}

void LowCase(char* b)
{
	int i;
	for (i = 0; i < strlen(b); i++)
	{
		if (int(b[i]) >= -64 && int(b[i]) <= -33)
		{
			b[i] = b[i] + 32;
		}
	}
	return;
}

int sr(char a[50], char b[50], int c)
{
	if (c == 1)
	{
		if (strcmp(a,b) > 0)
			return 0;
	}
	if (c == 2)
	{
		if (strcmp(a, b) < 0)
			return 0;
	}
}

int point1[50];

int sort(int a, int c, int y)
{
	memcpy(copy, student, sizeof(info) * 50);
	int i, j, d, k, t;
	char b[50];
	memcpy(point1, point, sizeof(int[50]));
	k = 0;
	for (i = 0; i < n; i++)
	{
		LowCase(copy[i].name);
		LowCase(copy[i].surname);
		LowCase(copy[i].patronymic);
		LowCase(copy[i].family.input_union1.name_brother1);
		LowCase(copy[i].family.input_union1.name_father1);
		LowCase(copy[i].family.input_union1.name_mother1);
		LowCase(copy[i].family.input_union2.name_brother2);
		LowCase(copy[i].family.input_union2.name_father2);
		LowCase(copy[i].family.input_union2.name_mother2);
		LowCase(copy[i].family.input_union2.name_sister2);
		LowCase(copy[i].family.input_union3.name_brother3);
		LowCase(copy[i].family.input_union3.name_mother3);
		LowCase(copy[i].family.input_union3.name_sister3);
	}
	if (a == 2)
	{
		d = n;
		for (i = 0; i < d; i++)
			for (j = i; j < d; j++)
				if (sr(copy[i].name, copy[j].name, c) == 0)
				{
					buffer = student[i];
					student[i] = student[j];
					student[j] = buffer;
					t = point[i];
					point[i] = point[j];
					point[j] = t;
				}
	}
	if (a == 1)
	{
		d = n;
		for (i = 0; i < d; i++)
			for (j = i; j < d; j++)
				if (sr(copy[i].surname, copy[j].surname, c) == 0)
				{
					buffer = student[i];
					student[i] = student[j];
					student[j] = buffer;
					t = point[i];
					point[i] = point[j];
					point[j] = t;
				}
	}
	if (a == 3)
	{
		d = n;
		for (i = 0; i < d; i++)
			for (j = i; j < d; j++)
				if (sr(copy[i].patronymic, copy[j].patronymic, c) == 0)
				{
					buffer = student[i];
					student[i] = student[j];
					student[j] = buffer;
					t = point[i];
					point[i] = point[j];
					point[j] = t;
				}
	}
	if (a == 4)
	{
		k = 0;
		l();
		output_titel();
		for (i = 0; i < n; i++)
		{
			if (y == 2 || y == 3)
				if (point[i] != 0)
				{
					copy[k] = student[i];
					ii(i);
					cu(point[i], y, i);
					cut(y);
					printf("%s (%s)\n", cc, cc1);
					k++;
				}
			if (y == 1)
			{
				if (point[i] == 1 || point[i] == 2)
				{
					copy[k] = student[i];
					ii(i);
					cu(point[i], y, i);
					cut(y);
					printf("%s (%s)\n", cc, cc1);
					k++;
				}
			}
			if (y == 4)
			{
				if (point[i] == 2 || point[i] == 3)
				{
					copy[k] = student[i];
					ii(i);
					cu(point[i], y, i);
					cut(y);
					printf("%s (%s)\n", cc, cc1);
					k++;
				}
			}
		}
		if (k == 0)
		{
			printf("\nПо такому параметру структур не было найдено\n");
			return 0;
		}
		
		d = k;	
		for (i = 0; i < d; i++)
		{
			for (j = i; j < d; j++)
			{
				cu(point[j], y, j);
				strcpy_s(b, cc);
				cu(point[i], y, i);
				if (sr(cc,b, c) == 0)
				{
					buffer = copy[i];
					copy[i] = copy[j];
					copy[j] = buffer;
					t = point1[i];
					point1[i] = point1[j];
					point1[j] = t;
				}
			}
		}
		l();
		output_titel();
		for (i = 0; i < d; i++)
		{
			printf("\033[0m%d", i + 1);
			putss(9);
			printf("\033[0m%s", copy[i].surname);
			putss(base_indent1 + 5 - strlen(copy[i].surname));
			printf("%s", copy[i].name);
			putss(base_indent2 + 5 - strlen(copy[i].name));
			printf("%s", copy[i].patronymic);
			putss(base_indent3 + 5 - strlen(copy[i].patronymic));
			if (point1[i] == 1)
			{
				if (y == 1)
				{
					strcpy_s(cc, copy[i].family.input_union1.name_father1);
				}
				if (y == 2)
				{
					strcpy_s(cc, copy[i].family.input_union1.name_mother1);
				}
				if (y == 3)
				{
					strcpy_s(cc, copy[i].family.input_union1.name_brother1);
				}
			}
			if (point1[i] == 2)
			{
				if (y == 1)
				{
					strcpy_s(cc, copy[i].family.input_union2.name_father2);
				}
				if (y == 2)
				{
					strcpy_s(cc, copy[i].family.input_union2.name_mother2);
				}
				if (y == 3)
				{
					strcpy_s(cc, copy[i].family.input_union2.name_brother2);
				}
				if (y == 4)
				{
					strcpy_s(cc, copy[i].family.input_union2.name_sister2);
				}
			}
			if (point1[i] == 3)
			{
				if (y == 2)
				{
					strcpy_s(cc, copy[i].family.input_union3.name_mother3);
				}
				if (y == 3)
				{
					strcpy_s(cc, copy[i].family.input_union3.name_brother3);
				}
				if (y == 4)
				{
					strcpy_s(cc, copy[i].family.input_union3.name_sister3);
				}
			}
			cut(y);
			printf("%s (%s)\n", cc, cc1);
		}
		k = 20;
	}
	return k;
}

void sort_menu()
{
	l();
	output();
	int k, y, d, i, j, t, b;
	k = 0;
	y = 0;
	d = 0;
	j = 0;
	t = 0;
	while (k == 0)
	{
		l();
		output();
		printf("\nКакую сортировку хотите сделать? (1 - От А до Я, 2 - От Я до А)\n");
		y = u(y);
		if (y == 1 || y == 2)
		{
			i = 0;
			while (i == 0)
			{
				l();
				output();
				printf("\nПо какому параметру хотите произвести сортировку?\n");
				printf("1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Объединение\n");
				d = u(d);
				if (d == 1 || d == 2 || d == 3)
				{
					b = sort(d, y, 0);
					i++;
				}
				else
				{
					if (d != 4)
					{
						o();
					}
					else
					{
						printf("\nПо какому члену семьи хотите произвести сортировку?\n1 - Отец\n2 - Мать\n3 - Брат\n4 - Сестра\n");
						i = 0;
						while (i == 0)
						{
							t = u(t);
							if (t == 1 || t == 2 || t == 3 || t == 4)
							{
								i++;
								b = sort(d, y, t);
							}
							else
							{
								o();
							}
						}
					}
				}
			}
		}
		else
		{
			o();
			continue;
		}
		if (b != 20)
		{
			l();
			output();
		}
		printf("\n");
		k = repeat();
	}
	return;
}

void delete_struct()
{
	int b, i, y;
	b = 0;
	y = 0;
	while (b == 0)
	{		
		l();
		output();
		printf("\nОсуществим удаление структуры");
		printf("\nВведите номер структуры\n");
		y = u(y);
		if (y <= n)
		{
			while (y < n)
			{
				buffer = student[y - 1];
				student[y - 1] = student[y];
				student[y] = buffer;
				y++;
			}
		}
		else
		{
			o();
			continue;
		}
		n--;
		l();
		output();
		b = repeat();
	}
	return;
}

void hard_search_menu()
{
	int b, i, y, k, d, j, t;
	char e[50];
	char c[50];
	char f[50];
	char g[50];
	strcpy_s(g, "");
	b = 0;
	k = 0;
	y = 0;
	d = 0;
	i = 0;
	t = 0;
	while (b == 0)
	{
		l();
		output();
		printf("\nОсуществим частичный поиск по любому из параметров\n");
		printf("По какому параметру хотите произвести поиск?\n");
		printf("1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Объединение\n");
		y = u(y);
		if (y == 1 || y == 2 || y == 3 || y == 4)
		{
			if (y == 4)
			{
				printf("\nПо какому члену семьи хотите произвести частичный поиск?\n1 - Отец\n2 - Мать\n3 - Брат\n4 - Сестра\n");
				while (i == 0)
				{
					t = u(t);
					if (t == 1 || t == 2 || t == 3 || t == 4)
					{
						i++;
					}
					else
					{
						o();
					}
				}
			}
			k = 0;
			while (k == 0)
			{
				l();
				output();
				printf("\nВведите элемент:\n");
				p(c);
				for (i = 0; i < n; i++)
				{
					cu(point[i], t, i);
					if (strlen(c) > strlen(cc))
					{
						o();
						break;
					}
					else
					{
						k++;
					}
				}
			}
			l();
			for (i = 0; i < n; i++)
			{
				if (y == 4)
				{
					cu(point[i], t, i);
				}
				else
				{
					strcpy(cc, gg(y, i));
				}
				if (strlen(c) == strlen(cc))
				{
					if (strcmp(c, cc) == 0)
					{
						d = output_search_full(y, i, c, g, cc, t);
					}
				}
				if (strlen(c) < strlen(cc))
				{
					for (j = 0; j < strlen(c); j++)
					{
						e[j] = cc[j];
					}
					e[strlen(c)] = '\0';
					k = 0;
					for (j = strlen(c); j < strlen(cc); j++)
					{
						f[k] = cc[j];
						k++;
					}
					f[strlen(gg(y, i)) - strlen(c)] = '\0';
					d = output_search_full(y, i, e, f, c, t);
				}
			}
		}
		else
		{
			o();
			continue;
		}
		if (d == 0)
		{
			o();
			continue;
		}
		else
		{
			b = repeat();
		}
	}
	return;
}

void switch_family()
{
	l();
	output();
	int k, d, b;
	k = 0;
	d = 0;
	while (k == 0) {
		printf("\nВведите номер структуры - ");
		d = u(d);
		if (d > n)
		{
			o();
			continue;
		}
		else
			k++;
	}
	b = 0;
	k = 0;
	while (k == 0)
	{
		printf("\nТип семьи:\n0 - Без объединения\n1 - Отец, Мать, Брат\n2 - Отец, Мать, Брат, Сестра\n3 - Мать, Брат, Сестра\n");
		b = u(b);
		if (b == 0 || b == 1 || b == 2 || b == 3)
		{
			point[d - 1] = b;
			if (b == 0)
				return;
			else
			{
				input_union_menu(b, d - 1);
			}
		}
	}
	return;
}

void menu()
{
	l();
	output();
	printf("Вы ввели структуру, что хотите с ней сделать?\n");
	printf("1 - Добавление структуры\n2 - Изменение структуры\n");
	printf("3 - Поиск в массиве структур (полный) по любому параметру\n4 - Сортировка в массиве структур по любому параметру\n");
	printf("5 - Удаление структуры\n6 - Поиск в массиве структур (частичный) по любому параметру\n7 - Изменить для одной из структуры тип семьи\n8 - Выход\n");
	int y,i;
	y = 0;
	i = 0;
	while (i == 0)
	{
		y = u(y);
		if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5 || y == 6 || y == 7 || y == 8)
		{
			if (y == 1)
			{
				plus();
				menu();
			}
			if (y == 2)
			{
				editing_struct_menu();
				menu();
			}
			if (y == 3)
			{
				easy_search_menu();
				menu();
			}
			if (y == 4)
			{
				sort_menu();
				menu();
			}
			if (y == 5)
			{
				delete_struct();
				menu();
			}
			if (y == 6)
			{
				hard_search_menu();
				menu();
			}
			if (y == 7)
			{
				switch_family();
				menu();
			}
			if (y == 8)
			{
				return;
			}
		}
		else
		{
			o();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	base_indent1 = 7;
	base_indent2 = 3;
	base_indent3 = 8;
	l();	
	n = 0;
	int i;
	printf("\033[0mВведём структуру\n");	
	input();
	menu ();
	return 0;
}