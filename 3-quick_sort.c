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

/**
 * lomuto - uses lomuto partition scheme to divide the array
 * @array: array to be sorted
 * @low: lower bound of the array
 * @up: upper bound of the array
 * @size: size of the array
 * Return: Nothing
 */
int lomuto(int *array, int low, int up, size_t size)
{
	int pivot = array[up], i, j = low;

	for (i = low; i < up; i++)
	{
		if (array[i] < pivot)
		{
			if (j < i)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			j++;
		}
	}
	if (array[j] > pivot)
	{
		swap(array, up, j);
		print_array(array, size);
	}
	return (j);
}

/**
 * sorting - sort the partitioned parts of the array
 * @array: array to be sorted
 * @low: lower bound of the array
 * @up: upper bound of the array
 * @size: size of the array
 * Return: Nothing
 */
void sorting(int *array, int low, int up, size_t size)
{
	int p;

	if (low >= up || low < 0)
		return;
	p = lomuto(array, low, up, size);
	sorting(array, low, p - 1, size);
	sorting(array, p + 1, up, size);
}

/**
 * quick_sort - sorts an array of integers using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	sorting(array, 0, size - 1, size);
}
