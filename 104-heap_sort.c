#include "sort.h"

/**
 * heapify - compare child nodes with parent node in the max heap
 * @array: original array
 * @n: part of the heap with nodes to compare
 * @i: parent node
 * @size: size of the original array
 * Return: Nothing
 */
void heapify(int *array, int n, int i, size_t size)
{
	int larg = i;
	int lft = 2 * i + 1;
	int rgt = 2 * i + 2;

	if (lft < n && array[lft] > array[larg])
		larg = lft;
	if (rgt < n && array[rgt] > array[larg])
		larg = rgt;
	if (larg != i)
	{
		swap(array, i, larg);
		print_array(array, size);
		heapify(array, n, larg, size);
	}
}

/**
 * heap_sort - sort an array in ascending order using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(array, 0, i);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
