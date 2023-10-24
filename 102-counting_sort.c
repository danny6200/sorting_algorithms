#include "sort.h"

/**
 * counting_sort - sorts an array using counting sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int max = 0, *counting_array, j, *sorted_array;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
		return;

	counting_array = malloc((max + 1) * sizeof(int));

	if (counting_array == NULL)
	{
		free(sorted_array);
		return;
	}
	for (j = 0; j <= max; j++)
		counting_array[j] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (j = 0; j < max + 1; j++)
		counting_array[j] += counting_array[j - 1];
	print_array(counting_array, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(counting_array);
	free(sorted_array);
}
