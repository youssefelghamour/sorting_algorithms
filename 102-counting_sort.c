#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 *		   Counting sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *index, *places;
	int max;
	size_t i;

	if (size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] >= max)
			max = array[i];
	}
	index = malloc(sizeof(int) * (max + 1));
	if (!index)
		return;

	for (i = 0; i < size; i++)
		index[array[i]]++;
	for (i = 0; (int)i <= max; i++)
		index[i] = index[i] + index[i - 1];

	print_array(index, max + 1);
	places = malloc(sizeof(int) * size);
	if (!places)
	{
		free(index);
		return;
	}
	for (i = 0; i < size; i++)
	{
		places[index[array[i]] - 1] = array[i];
		index[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = places[i];

	free(index);
	free(places);
}
