#include "sort.h"

/**
 * selection_sort - sorts an array using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int low, min_idx, temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		low = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < low)
			{
				low = array[j];
				min_idx = j;
			}
		}
		if (low != array[i])
		{
			temp = array[i];
			array[i] = low;
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
