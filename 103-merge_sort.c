#include "sort.h"

/**
 * print_merge - prints the subarray during the merge process
 *
 * @msg: message indicating the purpose of the printed subarray
 * @array: the array or subarray to print
 * @from: The starting index of the subarray
 * @to: The ending index of the subarray
 */
void print_merge(char *msg, int *array, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, array[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - updates the original array after sorting and merging the
 *	   two sub-arrays
 *
 * @array: original array
 * @lb: lower bound
 * @mid: the middle that seperates the two sub-arrays to merge
 * @ub: upper bound
 * @b: temporary array
 */
void merge(int *array, int lb, int mid, int ub, int *b)
{
	int i = lb, j = mid + 1, k = lb;

	printf("Merging...\n");
	print_merge("left", array, lb, mid);
	print_merge("right", array, mid + 1, ub);

	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			b[k] = array[i];
			i++;
		}
		else
		{
			b[k] = array[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		b[k] = array[i];
		i++;
		k++;
	}

	while (j <= ub)
	{
		b[k] = array[j];
		j++;
		k++;
	}

	for (i = lb; i <= ub; i++)
		array[i] = b[i];

	print_merge("Done", array, lb, ub);
}

/**
 * sort - sorts the array with recursive calls
 *
 * @array: array to sort
 * @lb: lower bound
 * @ub: upper bound
 * @b: temporary array
 */
void sort(int *array, int lb, int ub, int *b)
{
	int mid;

	if (lb < ub)
	{
		mid = (ub + lb - 1) / 2;
		sort(array, lb, mid, b);
		sort(array, mid + 1, ub, b);
		merge(array, lb, mid, ub, b);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 *		the Merge sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int lb, ub;
	int *b;

	lb = 0;
	ub = size - 1;

	b = malloc(sizeof(int) * size);

	sort(array, lb, ub, b);

	free(b);
}
