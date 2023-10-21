/**
 * counting_sort - sorts an array using counting sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
#include "sort.h"
void counting_sort(int *array, size_t size)
{
	int max = 0, *counting_array, index, j;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting_array = malloc((max + 1) * sizeof(int));

	if (counting_array == NULL)
		return;
	for (j = 0; j <= max; j++)
		counting_array[j] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, max);
	printf("\n");

	index = 0;
	for (j = 0; j <= max; j++)
	{
		while (counting_array[j] > 0)
		{
			array[index] = j;
			index++;
			counting_array[j]--;
		}
	}
	free(counting_array);
}
