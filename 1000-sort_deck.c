#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * compare_cards - Compare two cards for sorting
 * @a: First card node
 * @b: Second card node
 *
 * Return: 0 if equal, negative if a < b, positive if a > b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = ((deck_node_t *)a)->card;
	const card_t *card_b = ((deck_node_t *)b)->card;

	if (card_a->kind < card_b->kind)
		return (-1);
	else if (card_a->kind > card_b->kind)
		return (1);
	else
		return (strcmp(card_a->value, card_b->value));
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: A pointer to the head of the deck.
 *
 * Return: Always 0
 */
void sort_deck(deck_node_t **deck)
{
	int num_cards = 52;
	deck_node_t *deck_array[52];
	int i;

	for (i = 0; i < num_cards; i++)
	{
		deck_array[i] = *deck;
		*deck = (*deck)->next;
	}

	qsort(deck_array, num_cards, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < num_cards; i++)
	{
		if (i == 0)
		{
			deck_array[i]->prev = NULL;
		} else
			deck_array[i]->prev = deck_array[i - 1];

		if (i == num_cards - 1)
		{
			deck_array[i]->next = NULL;
		} else
			deck_array[i]->next = deck_array[i + 1];
	}

	*deck = deck_array[0];
}
