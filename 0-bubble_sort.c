#include "sort.h"


/**
 * bubble_sort - sort integers passed to the function
 * @array: this is the array of integers to sorted
 * @size: this is the size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;

if (array == NULL || size < 2)
return;

for (i = size; i > 0; i--)
{
for (j = 0; j < i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
}
}
print_array(array, size);
}
}
