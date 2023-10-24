#include <stdio.h>
#include "deck.h"
#include <string.h>
#include <stdlib.h>

/**
 * card_value_compare - Compare two cards for sorting.
 * @card1: First card
 * @card2: Second card
 * Return: Negative if a < b, Positive if a > b.
 */
static int card_value_compare(const card_t *card1, const card_t *card2)
{
	return (strcmp(card1->value, card2->value));
}

/**
 * card_kind_compare - Compare two cards for sorting.
 * @card1: First card
 * @card2: Second card
 * Return: Negative if a < b, Positive if a > b.
 */
static int card_kind_compare(const card_t *card1, const card_t *card2)
{
	return (card1->kind - card2->kind);
}

/**
 * card_compare - Compare two cards for sorting.
 * @a: First card
 * @b: Second card
 * Return: Negative if a < b, Positive if a > b, 0 if a == b
 */
static int card_compare(const void *a, const void *b)
{
	const card_t *card1 = ((deck_node_t *)a)->card;
	const card_t *card2 = ((deck_node_t *)b)->card;

	int value_cmp = strcmp(card1->value, card2->value);

	if (value_cmp != 0)
	{
		return (value_cmp);
	}

	return (card_kind_compare(card1, card2));
}

/**
 * sort_deck - Sorts a deck of cards in a specific order.
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 0;
	deck_node_t *current = *deck;

	if (deck == NULL || *deck == NULL)
	{
		return;
	}

	while (current)
	{
		deck_size++;
		current = current->next;
	}
	deck_node_t *deck_array[deck_size];

	current = *deck;

	for (size_t i = 0; i < deck_size; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, deck_size, sizeof(deck_node_t *), card_compare);

	for (size_t i = 0; i < deck_size; i++)
	{
		if (i > 0)
		{
			deck_array[i]->prev = deck_array[i - 1];
		}
		else
		{
			deck_array[i]->prev = NULL;
			*deck = deck_array[i];
		}

		if (i < deck_size - 1)
		{
			deck_array[i]->next = deck_array[i + 1];
		}
		else
		{
			deck_array[i]->next = NULL;
		}
	}
}
