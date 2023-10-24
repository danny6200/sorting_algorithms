#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers using Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: 0 on success and 1 on failure
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i;
	int *output = malloc(sizeof(int) * size);

	if (size < 2)
		return;


	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		/**int *output = malloc(sizeof(int) * size);**/
		int count[10] = {0};

		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i < size; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
		free(output);
	}
}
