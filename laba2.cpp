#include <iostream>

int main()
{
	int a, b, h, x;
	double y, y1, y2;
	scanf_s("%d%d%d", &a, &b, &h);
	x = a * b * h;
	y1 = pow(x, 2) + sin(x) + 3 * sqrt(cos(2 * x));
	y2 = (3 * log(x)) / 2;
	y = y1 / y2;
	printf_s("%f", y);
	return 0;
}
