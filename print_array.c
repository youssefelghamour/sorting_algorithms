#include <stdlib.h>
#include <stdio.h>

/**
 *  * print_array - Prints an array of integers
 *   *
 *    * @array: The array to be printed
 *     * @size: Number of elements in @array
 *      */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

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
