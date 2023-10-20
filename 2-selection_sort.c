/**
 * selection_sort - sorts an array using selection
 * algorithm
 * @array: unsorted array
 * @size: size of array
 *
 * Return: nothing
 */

#include "sort.h"
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}
		if (jMin != i)
		{
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
		}
		print_array(array, size);
	}
}
