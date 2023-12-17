#include "sort.h"

/**
 * getMax - returns the maximum value in an array
 *
 * @array: the array
 * @size: size of the array
 *
 * Return: the maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - performs counting sort on a specified digit
 *
 * @array: array to sort
 * @size: size of the array
 * @pos: the current digit being considered
 */
void countSort(int *array, size_t size, int pos)
{
	int *b;
	int count[10] = {0};
	size_t i;

	b = malloc(size * sizeof(int));
	if (!b)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / pos) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		b[count[(array[i - 1] / pos) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / pos) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = b[i];

	print_array(array, size);
	free(b);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 *		the LSD Radix sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	size_t pos;

	if (!array || size < 2)
		return;

	for (pos = 1; max / pos > 0; pos *= 10)
		countSort(array, size, pos);
}
