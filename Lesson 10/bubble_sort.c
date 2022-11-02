#include <stdio.h>

void bubble_sort(int number[], int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (number[j] > number[j + 1])
			{
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int number[5] = { 77, 23, 45, 12, 53 };
	bubble_sort(number, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", number[i]);
	}
	return 0;
}
