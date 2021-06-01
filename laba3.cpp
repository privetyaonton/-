#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
int base_index1, base_index2, base_index3;

struct info
{
	char name_tool[50];
	int day;
	int month;
	int year;
}tool;

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
	int b, k;
	k = 0;
	while (k == 0)
	{
		rewind(stdin);
		b = scanf_s("%d", &a);
		if (b != 1)
		{
			o();
			continue;
		}
		else {
			k++;
		}
	}
	return a;
}

int repeat()
{
	printf("\nХотите ещё раз? (0 - да, 1 - нет)\n");
	int k;
	k = 0;
	k = u(k);
	return k;
}

int day, month, year;

void input_struct(FILE* text)
{
	int k, i, b;
	k = 0;
	i = 0;
	text = fopen("file.dat", "wb");
	l();
	printf("Введём инструменты\n\n");
	while (k == 0)
	{
		l();
		printf("Название инструмента:\n");
		scanf("%s", tool.name_tool);
		printf("Дата изготовления (день.месяц.год)\n");
		b = scanf_s("%d.%d.%d", &tool.day, &tool.month, &tool.year);
		if (b != 3)
		{
			o();
			continue;
		}
		if (i == 0)
		{
			day = tool.day;
			month = tool.month;
			year = tool.year;
		}
		k = repeat();
		i++;
		fwrite(&tool, sizeof(tool), 1, text);
	}
	fclose(text);
	return;
}

void putss(int a)
{
	int i;
	for (i = 0; i < a; i++)
		printf(" ");
	return;
}

void go_max(FILE* text)
{
	int i, max_index, k, day, month, year, y, t;
	char name_tool[50];
	text = fopen("file.dat", "rb");
	i = 1;
	rewind(text);
	struct info temp;
	max_index = 1;
	fread(&temp, sizeof(temp), 1, text);
	rewind(text);
	while (!feof(text))
	{
		if (tool.year < temp.year)
		{
			temp = tool;
			max_index = i;
		}
		else
		{
			if (tool.year == temp.year)
			{
				if (tool.month < temp.month)
				{
					temp = tool;
					max_index = i;
				}
				else
				{
					if (tool.month = temp.month)
					{
						if (tool.day < temp.day)
						{
							temp = tool;
							max_index = i;
						}
					}
				}
			}
		}
		fread(&tool, sizeof(tool), 1, text);
		i++;
	}
	rewind(text);
	i = 1;
	k = 1;
	while (!feof(text))
	{
		if (k == max_index)
		{
			printf("Инструмент под названием %s является самым старым и был создан ", temp.name_tool);
			printf("%d.%d.%d\n", temp.day, temp.month, temp.year);
			break;
		}
		else
			k++;
	}
	printf("\nХотите корректировать эту запись? (1 - да, 2 - нет)\n");
	i = 0;
	y = 0;
	t = 0;
	while (i == 0)
	{
		y = u(y);
		if (y == 1 || y == 2)
		{
			if (y == 1)
			{
				l();
				printf("Что именно вы хотите корректировать?\n1 - Название инструмента\n2 - Дата изготовления\n3 - Оба параметра\n");
				t = u(t);
				if (t == 1 || t == 2 || t == 3)
				{
					if (t == 1)
					{
						printf("\nВведите название инструмента\n");
						rewind(stdin);
						gets_s(name_tool);
						day = temp.day;
						month = temp.month;
						year = temp.year;
					}
					if (t == 2)
					{
						printf("\nВведите дату\n");
						rewind(stdin);
						scanf_s("%d.%d.%d", &day, &month, &year);
						strcpy(name_tool, temp.name_tool);
					}
					if (t == 3)
					{
						printf("\nВведите название инструмента\n");
						rewind(stdin);
						gets_s(name_tool);
						rewind(stdin);
						printf("\nВведите дату\n");
						scanf_s("%d.%d.%d", &day, &month, &year);
					}
				}
			}
			i++;
		}
		else
			o();
	}
	l();
	printf("Вывод на печать:\n");
	printf("Инструмент под названием %s является самым старым и был создан ", name_tool);
	printf("%d.%d.%d\n", day, month, year);
	fclose(text);
	return;
}

void output_structs(FILE* text)
{
	int i;
	text = fopen("file.dat", "rb");
	struct info temp;
	while (fread(&temp, sizeof(temp), 1, text) == 1) {
		if (strlen(temp.name_tool) > base_index2)
			base_index2 = strlen(temp.name_tool);
	}
	printf("\033[33mНомер структуры");
	putss(5);
	printf("Название инструмента");
	putss(base_index2 - 15);
	printf("Дата изготовления\033[0m\n");
	i = 1;
	rewind(text);
	while (fread(&temp, sizeof(temp), 1, text) == 1)
	{
		printf("%d", i);
		i++;
		putss(19);
		printf("%s", temp.name_tool);
		putss(base_index2 + 5 - strlen(temp.name_tool));
		printf("%d.%d.%d\n", temp.day, temp.month, temp.year);
	}
	rewind(text);
	go_max(text);
	fclose(text);
}

void main()
{
	int b, k, day, month, year, i, y, t;
	char name_tool[50];
	FILE* text = fopen ("file.dat", "wb");
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	input_struct(text);
	k = 0;
	base_index1 = 15;
	base_index2 = 20;
	base_index3 = 17;
	l();
	output_structs(text);
	fclose(text);
	return;
}