#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * using the Insertion sort algorithm
 * @list: A pointer to a pointer  the  head of list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
