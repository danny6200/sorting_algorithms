#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * using the Insertion sort algorithm
 * @list: A pointer to a pointer  the  head of list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		for (prev_node = temp->prev;
				prev_node != NULL && temp->n < prev_node->n;
				prev_node = temp->prev)
		{
			if (temp->next != NULL)
				temp->next->prev = prev_node;
		prev_node->next = temp->next;
		temp->next = prev_node;
		temp->prev = prev_node->prev;
		prev_node->prev == temp;
		if (temp->prev == NULL)
			*list = temp;
		else
			temp->prev->next = temp;
		print_list(*list);
	}
	}
}
