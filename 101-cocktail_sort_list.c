#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of a doubly linked list
 *
 * @list: Pointer to the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
listint_t *tmp = node2->next;

if (node1->prev)
node1->prev->next = node2;
else
*list = node2;

if (node2->next)
node2->next->prev = node1;

node2->prev = node1->prev;
node2->next = node1;
node1->prev = node2;
node1->next = tmp;

if (tmp)
tmp->prev = node1;

print_list(*list);
}

/**
 * cocktail_sort_list - Sorts doubly linked list of integers
 *
 * @list: Pointer to the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *left, *right;
int swapped = 1;

if (!list || !*list || !(*list)->next)
return;

left = *list;
right = (*list)->prev;

while (swapped)
{
swapped = 0;

while (left != right)
{
if (left->n > left->next->n)
{
swap_nodes(list, left, left->next);
swapped = 1;
}
else
{
left = left->next;
}
}

if (!swapped)
break;

swapped = 0;
right = right->prev;

while (right != left)
{
if (right->n < right->prev->n)
{
swap_nodes(list, right->prev, right);
swapped = 1;
}
else
{
right = right->prev;
}
}

left = left->next;
}
}
