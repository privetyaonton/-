#include <iostream>
int main()
{
	int i,c;
	int a[15];
	for (i = 0; i < 15; i++)
		scanf_s("%d",  &a[i]);
	for (i = 0; i < 7; i++)
	{
		c = a[i];
		a[i] = a[14 - i];
		a[14 - i] = c;
	}
	for (i = 0; i < 15; i++)
		printf("%d ", a[i]);
	return 0;
}