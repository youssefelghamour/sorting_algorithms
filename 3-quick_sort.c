#include "sort.h"

int lomuto(int *array, int low, int up)
{
	int pivot = array[up], i, j = low, temp;

	for (i = low; i < up; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			j++;
			print_array(array, up + 1);
		}
	}
	temp = array[up];
	array[up] = array[j];
	array[j] = temp;
	return (j);
}

void sorting(int *array, int low, int up)
{
	int p;

	if (low >= up)
		return;
	p = lomuto(array, low, up);
	sorting(array, low, p - 1);
	sorting(array, p + 1, up);
}

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sorting(array, 0, size - 1);
}
