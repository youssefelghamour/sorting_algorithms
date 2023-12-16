#include "sort.h"

/**
 * swap - swap two node of the list
 * @x: node to be swapped
 * @temp: the next node
 * @list: pointer to head of the list
 * Return Nothing
 */
void swap(listint_t *x, listint_t *temp, listint_t **list)
{
	if (temp->next != NULL)
		temp->next->prev = x;
	if (x->prev != NULL)
		x->prev->next = temp;
	else
		*list = temp;
	x->next = temp->next;
	temp->prev = x->prev;
	x->prev = temp;
	temp->next = x;
	while ((*list)->prev)
		*list = (*list)->prev;
}

/**
 * cocktail_sort_list - sort doubly linked list using cocktail sorting
 * @list: list to be sorted
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		for (ptr = *list; ptr->next != NULL; ptr = current->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swap(list, ptr, ptr->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for ( ; ptr->prev != NULL; ptr = ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap(list, ptr->prev, ptr);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
