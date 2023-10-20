/**
 * swap - swaps two integer elements
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: nothing
 */

#include "sort.h"

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
 *
 * Return: an integer
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
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
		pivot_index = lomuto_partition(array, low, high);
		print_array(array, size);
		printf("\n");

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
	else
		return
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
