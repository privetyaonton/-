#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, i, j, m, * p, ** pp,**pp1, a, b;
	printf("Введите количество действительных чисел - ");
	a = scanf_s("%d", &n);
	printf("\nВведите число k - ");
	b = scanf_s("%d", &k);
	if (a != 1 || b != 1)
	{
		printf("\nСКАЗАЛИ ЖЕ ВВЕСТИ ЧИСЛО!!!!!");
		return 1;
	}
	p = (int*)calloc(n, sizeof(int));
	printf("\nВведите действительные числа\n");
	for (i = 0; i < n; i++)
	{
		printf("Число %d - ", i + 1);
		a = scanf_s("%d", &p[i]);
		if (a != 1)
		{
			printf("\nЧто-то не так, попробуй ещё раз\n");
			return 1;
		}
	}

	pp = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		pp[i] = (int*)calloc(n, sizeof(int));
	m = n + 1;
	pp1 = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		pp1[i] = (int*)calloc(m, sizeof(int));
	printf("\nВведите матрицу\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("Число [%d][%d] - ", i, j);
			a = scanf_s("%d", &pp[i][j]);
			if (a != 1)
			{
				printf("\nЧто-то не так, попробуйте ещё раз");
				return 1;
			}
		}
	printf("\nВы ввели матрицу:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("%d ", pp[i][j]);
			if (j == n - 1)
				printf("\n");
		}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= k; j++)
		{
			if (j == k)
				pp1[i][j] = p[i];
			else
				pp1[i][j] = pp[i][j];
		}
		for (j = k + 1; j < m; j++)
			pp1[i][j] = pp[i][j - 1];

	}
	printf("\nПолученная матрица\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("%d ", pp1[i][j]);
			if (j == n)
				printf("\n");
		}
	return 0;
}