#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

char pole[10][10];
int mas[11][11];

int kol(int x, int y)
{
	int s;
	s = 0;
	if (x == 1 || x == 10 || y == 1 || y == 10)
	{
		if (x == 1 && y == 1)
		{
			if (mas[y][x - 1] == 9)
				s++;
			if (mas[y][x] == 9)
				s++;
			if (mas[y - 1][x] == 9)
				s++;
		}
		if (x == 1 && y == 10)
		{
			if (mas[y - 1][x] == 9)
				s++;
			if (mas[y - 2][x - 1] == 9)
				s++;
			if (mas[y - 2][x] == 9)
				s++;
		}
		if (x == 10 && y == 1)
		{
			if (mas[y][x - 2] == 9)
				s++;
			if (mas[y][x - 1] == 9)
				s++;
			if (mas[y - 1][x - 2] == 9)
				s++;
		}
		if (x == 10 && y == 10)
		{
			if (mas[y - 1][x - 2] == 9)
				s++;
			if (mas[y - 2][x - 2] == 9)
				s++;
			if (mas[y - 2][x - 1] == 9)
				s++;
		}
		if (x == 1 && y != 1 && y != 10)
		{
			if (mas[y][x - 1] == 9)
				s++;
			if (mas[y][x] == 9)
				s++;
			if (mas[y - 1][x] == 9)
				s++;
			if (mas[y - 2][x - 1] == 9)
				s++;
			if (mas[y - 2][x] == 9)
				s++;
		}
		if (x == 10 & y != 1 && y != 10)
		{
			if (mas[y][x - 2] == 9)
				s++;
			if (mas[y][x - 1] == 9)
				s++;
			if (mas[y - 1][x - 2] == 9)
				s++;
			if (mas[y - 2][x - 2] == 9)
				s++;
			if (mas[y - 2][x - 1] == 9)
				s++;
		}
		if (y == 1 && x != 1 && x != 10)
		{
			if (mas[y][x - 2] == 9)
				s++;
			if (mas[y][x - 1] == 9)
				s++;
			if (mas[y][x] == 9)
				s++;
			if (mas[y - 1][x - 2] == 9)
				s++;
			if (mas[y - 1][x] == 9)
				s++;
		}
		if (y == 10 && x != 1 && x != 10)
		{
			if (mas[y - 1][x - 2] == 9)
				s++;
			if (mas[y - 1][x] == 9)
				s++;
			if (mas[y - 2][x - 2] == 9)
				s++;
			if (mas[y - 2][x - 1] == 9)
				s++;
			if (mas[y - 2][x] == 9)
				s++;
		}
	}
	else
	{
		if (mas[y][x-2] == 9)
			s++;
		if (mas[y][x-1] == 9)
			s++;
		if (mas[y][x] == 9)
			s++;
		if (mas[y - 1][x - 2] == 9)
			s++;
		if (mas[y - 1][x] == 9)
			s++;
		if (mas[y - 2][x - 2] == 9)
			s++;
		if (mas[y - 2][x - 1] == 9)
			s++;
		if (mas[y - 2][x] == 9)
			s++;
	}
	return s;
}

void haha(int k, int l)
{
	int k1[8], l1[8], i;
	if (mas[k - 1][l - 1] == 1)
		pole[k - 1][l - 1] = '1';
	if (mas[k - 1][l - 1] == 2)
		pole[k - 1][l - 1] = '2';
	if (mas[k - 1][l - 1] == 3)
		pole[k - 1][l - 1] = '3';
	if (mas[k - 1][l - 1] == 4)
		pole[k - 1][l - 1] = '4';
	if (mas[k - 1][l - 1] == 5)
		pole[k - 1][l - 1] = '5';
	if (mas[k - 1][l - 1] == 6)
		pole[k - 1][l - 1] = '6';
	if (mas[k - 1][l - 1] == 7)
		pole[k - 1][l - 1] = '7';
	if (mas[k - 1][l - 1] == 8)
		pole[k - 1][l - 1] = '8';
	if (mas[k - 1][l - 1] == 0)
	{
		k1[0] = k - 1;
		k1[1] = k - 1;
		k1[2] = k - 1;
		k1[3] = k;
		k1[4] = k;
		k1[5] = k + 1;
		k1[6] = k + 1;
		k1[7] = k + 1;
		l1[0] = l - 1;
		l1[1] = l;
		l1[2] = l + 1;
		l1[3] = l - 1;
		l1[4] = l + 1;
		l1[4] = l - 1;
		l1[6] = l;
		l1[7] = l + 1;
		for (i = 0; i < 8; i++)
		{
			haha(k1[i], l1[i]);
		}
	}
	return;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k1[8], l1[8];
	int k2[25], l2[25];
	int mas[11][11], i, j, b, k, l, y, n, d;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			pole[i][j] = '#';
		}
	j = 0;
	k2[0] = 11;
	l2[0] = 11;
	n = 1;
	for (i = 0; i < 25; i++)
	{
		b = 0;
		while (b == 0)
		{
			k = rand() % 8;
			l = rand() % 8;
			d = 0;
			for (j = 0; j < n; j++)
			{
				if (k == k2[j] && l == l2[j])
					d++;
			}
			if (d == 0)
			{
				k2[i] = k;
				l2[i] = l;
				mas[k][l] = 9;
				n++;
				b = 1;
			}
		}

	}
	for (i = 9; i >= 0; i--)
		for (j = 0; j < 10; j++)
		{
			if (mas[i][j] != 9)
			{
				mas[i][j] = kol(j + 1, i + 1);
			}
		}
	b = 0;
	while (b == 0)
	{
		system("CLS");
		printf("X ");
		for (i = 0; i < 10; i++)
			printf("%d ", i + 1);
		printf("\n");
		for (i = 0; i < 10; i++)
		{
			printf("%d ", i + 1);
			for (j = 0; j < 10; j++)
			{
				printf("%c ", pole[i][j]);
				if (j == 9)
					printf("\n");
			}
		}
		printf("\nХотите найти мину (1) или открыть элемент поля(2)?\n");
		scanf_s("%d", &y);
		if (y == 1)
		{
			printf("\nВведите координаты точки - ");
			scanf_s("%d %d", &k, &l);
			pole[k - 1][l - 1] = 'Z';
		}
		if (y == 2)
		{
			printf("\nВведите координаты точки - ");
			scanf_s("%d %d", &k, &l);
			if (mas[k - 1][l - 1] == 9)
			{
				printf("\n\nВы проиграли\n\n");
				b++;
			}
			else
			{
				haha(k, l);
			}
		}
	}
	return 0;
}