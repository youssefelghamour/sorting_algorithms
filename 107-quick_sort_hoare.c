#include "sort.h"

/**
 * swap -  swap two elements of the array
 * @array: array to swap its elements
 * @x: first element
 * @y: second element
 * Return: Nothing
 */
void swap(int *array, int x, int y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

int hoare(int *array, int i, int j, size_t size)
{
	int pivot = array[j];
	int low = i, high = j;

	while (low < high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low < high)
		{
			swap(array, low, high);
			print_array(array, size);
		}
	}
	return (high);
}

void quick_sort2(int *array, int i, int j, size_t size)
{
	int p;
	
	if (i >= j)
		return;
	p = hoare(array, i, j, size);
	quick_sort2(array, i, p - 1, size);
	quick_sort2(array, p, j, size);
}

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort2(array, 0, size - 1, size);
}
