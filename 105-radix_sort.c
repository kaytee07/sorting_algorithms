#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 *              using the LSD radix sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
int *count = NULL, *output = NULL, max_digit = 0, i, j;
size_t exp = 1;
if (!array || size < 2)
return;
for (i = 0; i < (int)size; i++)
{
if (array[i] > max_digit)
max_digit = array[i];
}
count = malloc(sizeof(int) * 10);
if (!count)
return;
output = malloc(sizeof(int) * size);
if (!output)
{
free(count);
return;
}
while (max_digit / exp > 0)
{
for (i = 0; i < 10; i++)
count[i] = 0;
for (i = 0; i < (int)size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size - 1; i >= 0; i--)
{
j = (array[i] / exp) % 10;
output[count[j] - 1] = array[i];
count[j]--;
}
for (i = 0; i < (int)size; i++)
array[i] = output[i];
print_array(array, size);
exp *= 10;
}
free(count);
free(output);
}
