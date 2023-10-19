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
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[jMin])
			{
				jMin = j;
			}
		}
		if (jMin != i)
		{
			swap(a[i], a[jMin]);
		}
	}
}
				
