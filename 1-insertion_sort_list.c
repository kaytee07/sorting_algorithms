#include "sort.h"


/**
 *
 *
 *
 *
 */

void insertion_sort_list(listint_t **list)
{
  listint_t *array, *array_t, *temp;
  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;
  
  array = *list;
  array_t = (*list)->next;

  while (array_t != NULL)
    {
      printf("%d\n", array_t->n);
      while (array != array_t)
	{
	  printf("%d: %da ", array->n, array_t->n);
	   if (array->n > array_t->n)
	    {
	      array->prev->next = array->next;
              if (array->next != NULL)
                array->next->prev = array->prev;

              // Insert the current node in front of the next node
              array->prev = array_t->prev;
              array->next = array_t;
              if (array_t->prev != NULL)
                array_t->prev->next = array;
              array_t->prev = array;

              // Update array_t to point to the next node
              temp = array_t;
              array_t = array;
              array = temp;

	    }
	  array = array->next;
	  }
      printf("\n");
      print_list(*list);
      array_t = array_t->next;
      array = *list;
    }
}
