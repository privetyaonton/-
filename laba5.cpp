#include <iostream>
#include <locale.h>

int main()
{
	int a[100][100], i, j, n;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
			
	int k = 0;
	int s = 0;
	if (n % 2 == 0)
	{
		for (i = 0; i < n / 2; i++)
		{
			for (j = k; j < n - k; j++)
				s += a[i][j];
			k++;
		}
	}
	if (n % 2 == 1)
	{
		for (i = 0; i < (n / 2) + 1; i++)
		{
			for (j = k; j < n - k; j++)
				s += a[i][j];
			k++;
		}
	}
	printf("%d", s);
	return 0;
}