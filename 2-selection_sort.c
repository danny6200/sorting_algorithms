/**
 * selection_sort - sorts an array using selection
 * algorithm
 * @array: unsorted array
 * @size: size of array
 *
 * Return: nothing
 */

#include "sort.h"
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}
		if (jMin != i)
		{
			swap(&array[i], &array[jMin]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
