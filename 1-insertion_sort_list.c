#include "sort.h"


/**
 * insertion_sort_list - sort linked list
 * @list: linked list to be sorted 
 */

void insertion_sort_list(listint_t **list)
{
  listint_t *sorted_list, *curr, *prev, *next;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    sorted_list = NULL, curr = *list, prev = NULL, next = NULL;

    while (curr != NULL)
    {
        next = curr->next;

        while (sorted_list != NULL && sorted_list->n < curr->n)
            sorted_list = sorted_list->prev;

        if (sorted_list == NULL)
        {
            curr->prev = NULL;
            curr->next = sorted_list;
            sorted_list = curr;
        }
        else
        {
            prev = sorted_list->prev;
            curr->prev = prev;
            curr->next = sorted_list;
            sorted_list->prev = curr;

            if (prev != NULL)
                prev->next = curr;
            else
                *list = curr;
        }
	print_list(*list);

        sorted_list = curr;
        curr = next;
    }
}
