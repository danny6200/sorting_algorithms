#include "sort.h"

/**
 * sift_down - Performs a sift-down operation on the heap
 * @array: The array to be sorted
 * @size: The size of the array
 * @root: The root of the heap
 * @end: The end of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max, child;
	int temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		max = root;


		if (child + 1 <= end && array[child] < array[child + 1])
			max = child + 1;

		if (array[root] < array[max])
		{
			temp = array[root];
			array[root] = array[max];
			array[max] = temp;
			print_array(array, size);
			root = max;
		}
		else
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heaps
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
