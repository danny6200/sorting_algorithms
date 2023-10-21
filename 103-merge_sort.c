#include "sort.h"
/**
 * merge - merges two subarrays into one sorted
 * subarray
 * @array: array of integers
 * @left_size: size of left subarray
 * @right_size: size of right subarray
 *
 * Return: nothing
 */

void merge(int *array, size_t left_size, size_t right_size)
{
	int *temp = malloc((left_size + right_size) * sizeof(int));
	size_t i, j, k, x;

	if (temp == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	i = 0;
	j = left_size;
	k = 0;

	while (i < left_size && j < left_size + right_size)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < left_size)
		temp[k++] = array[i++];

	while (j < left_size + right_size)
		temp[k++] = array[j++];

	for (x = 0; x < left_size + right_size; x++)
		array[x] = temp[x];
	free(temp);
}

/**
 * merge_sort_recursive - recursively implements the
 * merge sort top down algorithm
 * @array: array of integers
 * @size: array size
 *
 * Return: nothing
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid, left_size, right_size;

	if (size > 1)
	{
		mid = size / 2;
		left_size = mid;
		right_size = size - mid;

		merge_sort_recursive(array, left_size);

		merge_sort_recursive(array + mid, right_size);
		printf("Merging...\n[left]: ");
		print_array_2(array, left_size, 0);
		printf("\n[right]: ");
		print_array_2(array, size, left_size);
		merge(array, left_size, right_size);
		printf("\n[Done]: ");
		print_array(array, size);
	}
}

/**
 * merge_sort - sorts an array using merge sort top
 * down algorithm
 * @array: array of integers
 * @size: array size
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_sort_recursive(array, size);
}

/**
 * print_array_2 - prints an given its size and starting
 * point without new line character at the end
 * @array: array of integers to be printed
 * @size: size of array
 * @start: index to start printing from
 *
 * Return: nothing
 */
void print_array_2(int *array, size_t size, size_t start)
{
	size_t i;

	for (i = start; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
}
