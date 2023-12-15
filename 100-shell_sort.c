#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 *		sort algorithm, using the Knuth sequence
 *
 * @array: the array to sort
 * @size: length of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j;
	int temp, i;

	while (gap < size)
		gap = gap * 3 + 1;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i] < array[i + gap])
				{
					break;
				}
				else
				{
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
				}
			}
		}
		print_array(array, size);
	}
}
