#include "sort.h"

/**
 * swap_nodes - Swaping two nodes in a listint_t doubly-linked list.
 * @k: Pointer to the head of the doubly-linked list.
 * @n1: Pointer to the first node to swap.
 * @n2: Second node to swap.
 */
void swap_nodes(listint_t **k, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*k = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using
 * insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *inter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (inter = (*list)->next; inter != NULL; inter = tmp)
	{
		tmp = inter->next;
		insert = inter->prev;
		while (insert != NULL && inter->n < insert->n)
		{
			swap_nodes(list, &insert, inter);
			print_list((const listint_t *)*list);
		}
	}
}
