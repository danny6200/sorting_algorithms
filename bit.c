#include "sort.h"

/**
 * bitonic_sort - Sort an array of integers using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1);
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: The array to be sorted
 * @size: The size of the array
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
	size_t mid;

	if (size < 2)
		return;

		mid = size / 2;
		bitonic_sort_recursive(array, mid, 1);
		bitonic_sort_recursive(array + mid, mid, 0);
		bitonic_merge(array, size, dir);
}

/**
 * bitonic_merge - Merge two arrays in a ascending order.
 * @array: The array to be sorted
 * @size: The size of the elements in the array
 * @direction: 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, int direction)
{
	size_t mid = size / 2;
	size_t i;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < mid; i++)
	{
		if ((array[i] > array[i + mid]) == direction)
		{
			temp = array[i];

			array[i] = array[i + half];
			array[i + half] = temp;
/*			printf("Swap: %d > %d\n", array[i], array[i + half]);*/
			array[i] = array[i + mid];
			array[i + mid] = temp;
		}
	}

	bitonic_merge(array, mid, direction);
	bitonic_merge(array + mid, mid, direction);
}
