#include "sort.h"


/**
 * selection_sort - sort arrays in ascending order
 * @array: this is the array to be sorted
 * @size: this is the size of the array
 */

void selection_sort(int *array, size_t size)
{
size_t hook, i, j;
int temp;

if (array == NULL || size < 2)
return;

for (i = 0; i < size; i++)
{
hook = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[hook])
hook = j;
}

if (hook != i)
{
temp = array[i];
array[i] = array[hook];
array[hook] = temp;
print_array(array, size);
}
}
}
