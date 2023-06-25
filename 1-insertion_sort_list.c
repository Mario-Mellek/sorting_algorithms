#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *key, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	for (key = (*list)->next; key != NULL; key = key->next)
	{
		temp = key;
		while (temp->prev && (temp->prev->n > temp->n))
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
	}
}
