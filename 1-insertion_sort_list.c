#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion Sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			temp->next = prev;
			prev->prev = temp;

			prev = temp->prev;

			print_list(*list);
		}

		current = current->next;
	}
}

