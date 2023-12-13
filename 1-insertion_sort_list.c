#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *			 order using the Insertion sort algorithm
 *
 * @list: the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *a, *b;

	if (!list)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			a = temp->prev;
			b = temp;

			if (a->prev)
				a->prev->next = b;
			if (b->next)
				b->next->prev = a;

			a->next = b->next;
			b->prev = a->prev;
			b->next = a;
			a->prev = b;

			if (b->prev == NULL)
				*list = b;

			temp = b;

			print_list(*list);
		}

		current = current->next;
	}
}
