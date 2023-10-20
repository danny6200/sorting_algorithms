#include "sort.h"
#include <stdlib.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the list.
 * @left: The left node to swap.
 * @right: The right node to swap.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly liked list of integers in ascending
 * using the Cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right, *cur;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		for (left = *list; left->next != NULL; left = left->next)
		{
			if (left->n > left->next->n)
			{
				cur = left->next;
				swap_nodes(list, left, cur);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;

		swapped = 0;

		for (right = left; right->prev != NULL; right = right->prev)
		{
			if (right->n < right->prev->n)
			{
				cur = right->prev;
				swap_nodes(list, cur, right);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
