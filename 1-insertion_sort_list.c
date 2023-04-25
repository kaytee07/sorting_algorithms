#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 *
 * @list: Pointer to a pointer to the first node of the list to sort.
 *
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *tmp, *curr, *prev;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

curr = (*list)->next;
while (curr != NULL)
{
tmp = curr;
prev = curr->prev;
while (prev != NULL && tmp->n < prev->n)
{
prev->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = prev;
tmp->next = prev;
tmp->prev = prev->prev;
prev->prev = tmp;
if (tmp->prev == NULL)
*list = tmp;
else
tmp->prev->next = tmp;
print_list(*list);
prev = tmp->prev;
}
curr = curr->next;
}
}
