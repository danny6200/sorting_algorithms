#include "sort.h"
/**
 * quick_sort - sorts an array using quick sort
 * algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * swap - swaps two integer elements
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: nothing
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - This implements lomuto
 * partition
 * @array: array to be partitioned
 * @low: lowest element
 * @high: highest element
 * @size: array size
 *
 * Return: an integer
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_recursive - performs quick sort algorithm
 * recursively
 * @array: array to be sorted
 * @low: lowest element
 * @high: highest element
 * @size: holds the size of the array
 *
 * Return nothing
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}
