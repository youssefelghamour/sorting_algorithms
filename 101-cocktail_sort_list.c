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
	listint_t *start = *list, *temp, *forw, *back;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		forw = back = start;
		while (forw->next)
		{
			if (forw->n > forw->next->n)
			{
				temp = forw->next;
				swap(forw, temp, list);
				swapped = 1;
				forw = temp->prev;
				print_list(*list);
			}
			forw = forw->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		back = forw;
		while (back->prev)
		{
			if (back->n > back->next->n)
			{
				temp = back->next;
				swap(back, temp, list);
				swapped = 1;
				print_list(*list);
			}
			back = back->prev;
		}
	}
}
