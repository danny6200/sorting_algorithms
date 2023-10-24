#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in
 * ascending order using
 * the Quick Sort algorithm with the Hoare partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_sort_hoare(array, 0, size - 1, size);
}

/**
 * _quick_sort_hoare - Recursively sorts an array 
 * using the Quick Sort
 * algorithm with Hoare partition scheme.
 * @array: The array to be sorted.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 *
 * Return: nothing
 */
void _quick_sort_hoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		_quick_sort_hoare(array, low, pivot - 1, size);
		_quick_sort_hoare(array, pivot + 1, high, size);
		print_array(array, size);
	}
}

/**
 * hoare_partition - Partitions the array using the Hoare 
 * partition scheme.
 * @array: The array to be partitioned.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 *
 * Return: The pivot index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], temp;
	int i = low - 1;
	int j = high + 1;

	(void)size;

	while (1)
	{
		do
		{
			i++;
		}
		while (array[i] < pivot);
		do
		{
			j--;
		} 
		while (array[j] > pivot);

		if (i >= j)
			return (j);
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
}
