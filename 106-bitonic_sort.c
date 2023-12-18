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

void bitonic_merge(int *array, int low_idx, int count, int dir, size_t size)
{
	int k, i;

	if (count > 1)
	{
		k = count / 2;
		for (i = low_idx; i < low_idx + k; i++)
		{
			if (dir == (array[i] > array[i + k]))
			{
				swap(array, i, i + k);
			}
		}
		bitonic_merge(array, low_idx, k, dir, size);
		bitonic_merge(array, low_idx + k, k, dir, size);
	}
}

void sort(int *array, int low_idx, int count, int dir, size_t size)
{
	int k;
	char *str;

	if (count > 1)
	{
		if (dir == 1)
			str = "UP";
		else
			str = "DOWN";
		k = count / 2;
		printf("Merging [%d/%ld] (%s):\n", count, size, str);
		print_array(array + low_idx, count);
		sort(array, low_idx, k, 1, size);
		sort(array, low_idx + k, k, 0, size);
		bitonic_merge(array, low_idx, count, dir, size);
		printf("Result [%d/%ld] (%s):\n", count, size, str);
		print_array(array + low_idx, count);
	}
}

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size, 1, size);
}
