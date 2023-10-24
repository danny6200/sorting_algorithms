#include "sort.h"

/**
 * sift_down - Performs a sift-down operation on the heap
 * @array: The array to be sorted
 * @size: The size of the array
 * @root: The root of the heap
 * @max: The maximum index in the heap
 *
 * Return: nothing
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
	size_t largest, left, right;
	int temp;

	largest = root;
	left = (2 * root) + 1;
	right = (2 * root) + 2;

	if (left < max && array[left] > array[largest])
		largest = left;

	if (right < max && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, largest, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heaps
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
