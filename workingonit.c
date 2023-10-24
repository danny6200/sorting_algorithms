#include "sort.h"

/**
 * print_step - Prints an array in order
 * @label - The label to be sorted
 * @array - The array to be sorted
 * @size -  The size of the array
 */
void print_step(const char *label, int *array, size_t size)
{
	size_t i;
	printf("%s:\n", label);
	for (i = 0; i < size; i++)
	{
		if (i > 0 )
		{
			printf(", ");
		}
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_recursive(array, size, 1);

	print_step("Merging [16/16] (UP)", array, size);
	print_step("Result [16/16] (UP)", array, size);
}

/**
 * bitonic_recursive - Recursively sort a Bitonic sequence
 * @array: The array to be sorted
 * @size: The size of the array
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
	size_t half = size / 2;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%lu/%lu] (UP):\n", size, size);
		else
			printf("Merging [%lu/%lu] {DOWN):\n", size, size);

		print_array(array, size);

		bitonic_recursive(array, half, 1);
		bitonic_recursive(array + half, half, 0);
		bitonic_merge(array, size, dir);

		printf("Result [%lu/%lu] (UP):\n", size, size);
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges two Bitonic sequences into a single sequence.
 * @array: The array containig the sequences to be merged
 * @size: The size of the sequences
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t half = size / 2;

	if (size > 1)
	{
		bitonic_compare(array, size, dir);


		bitonic_merge(array, half, dir);
		bitonic_merge(array + half, half, dir);
	}
}

/**
 * bitonic_compare - Compares and swaps elements to create a Bitonic.
 * @array: The array containig the sequence to be compared and swapped.
 * @size: The size of the sequence
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t size, int dir)
{
	size_t half = size / 2;
	int temp;
	size_t i;

	for (i = 0; i < half; i++)
	{
		if ((array[i] > array[i + half]) == dir)
		{
			temp = array[i];
			array[i] = array[i + half];
			array[i + half] = temp;
			printf("Swap: %d > %d\n", array[i], array[i + half]);
		}
	}
}
