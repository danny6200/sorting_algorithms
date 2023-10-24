#ifndef SORT_H
#define SORT_H

/* Header Files*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Function Prototypes */

void print_array(const int *array, size_t size);
void print_array_2(int *array, size_t size, size_t start);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void counting_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *left, listint_t *right);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t end);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t left_size, size_t right_size);
void merge_sort_recursive(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_recursive(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void bitonic_compare(int *array, size_t size, int dir);
void print_step(const char *label, int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void _quick_sort_hoare(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);


#endif
