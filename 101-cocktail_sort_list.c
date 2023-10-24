#include "sort.h"
#include <stdlib.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the list.
 * @left: The left node to swap.
 * @right: The right node to swap.
 */
void swap_nodes(listint_t **list, listint_t *b, listint_t *c)
{
	if (b->prev)
		b->prev->next = c;
	else
		*list = c;
	if (c->next)
		c->next->prev = b;

	b->next = c->next;
	c->prev = b->prev;
	c->next = b;
	b->prev = c;

}

/**
 * cocktail_sort_list - Sorts a doubly liked list of integers in ascending
 * using the Cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = NULL, *right = NULL, *tmp = NULL, *cur;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		tmp = *list;
		
		while (tmp->next != right)
		{
			if (tmp->n > tmp->next->n)
			{
				cur = tmp->next;
				swap_nodes(list, tmp, cur);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
				tmp = tmp->next;
		}
		if (swapped == 0)
			break;

		swapped = 0;

		right = tmp;

		while (tmp->prev != left)
		{
			if (tmp->n < tmp->prev->n)
			{
				cur = tmp->prev;
				swap_nodes(list, cur, tmp);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
				tmp = tmp->prev;
		}
		left = tmp;
	}
}
