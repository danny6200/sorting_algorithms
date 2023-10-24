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

	bitonic_sort_recursive(array, size, 0, size, 1);
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: The array to be sorted
 * @size: The size of the array
 * @start: starting index
 * @seq: size of sequence block
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size,
			size_t start, size_t seq, int dir)
{
	size_t mid = seq / 2;
	const char *direction = (dir == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s): ", seq, size, direction);
		print_array(array + start, seq);

		bitonic_sort_recursive(array, size, start, mid, 1);
		bitonic_sort_recursive(array, size, start + mid, mid, 0);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s): ", seq, size, direction);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_merge - Merge two arrays in a ascending order.
 * @array: The array to be sorted
 * @size: The size of the elements in the array
 * @start: determines the starting index
 * @seq: size of the sequence to start
 * @dir: 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t mid = seq / 2;
	size_t i;
	int temp;

	if (seq > 1)
	{
		for (i = start; i < start + mid; i++)
		{
			if ((dir == 1 && array[i] > array[i + mid]) ||
					(dir == 0 && array[i] < array[i + mid]))
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}

		bitonic_merge(array, size, start, mid, dir);
		bitonic_merge(array, size, start + mid, mid, dir);
	}
}
