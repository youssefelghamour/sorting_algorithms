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
 * hoare - move all elements smaller than pivot left and higher numbers right
 * @array: array to be sorted
 * @i: lowest index
 * @j: max index
 * @size: size of the array
 * Return: Nothing
 */
int hoare(int *array, int i, int j, size_t size)
{
	int pivot = array[j];
	int low = i - 1, high = j + 1;

	while (low < high)
	{
		do {
			low++;
		} while (array[low] < pivot);
		do {
			high--;
		} while (array[high] > pivot);
		if (low < high)
		{
			swap(array, low, high);
			print_array(array, size);
		}
	}
	return (low);
}

/**
 * quick_sort2 - partition the array
 * @array: array to be sorted
 * @i: lowest index
 * @j: max index
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort2(int *array, int i, int j, size_t size)
{
	int p;

	if (i >= j)
		return;
	p = hoare(array, i, j, size);
	quick_sort2(array, i, p - 1, size);
	quick_sort2(array, p, j, size);
}

/**
 * quick_sort_hoare - sorts array of integers using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort2(array, 0, size - 1, size);
}
