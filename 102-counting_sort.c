#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers in ascending order using
 *                 the Counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
int max = 0, i, j;
int *count_array = NULL, *output_array = NULL;
for (i = 0; i < (int) size; i++)
{
if (array[i] > max)
max = array[i];
}
count_array = malloc(sizeof(int) * (max + 1));
if (count_array == NULL)
return;
for (i = 0; i < max + 1; i++)
count_array[i] = 0;
for (i = 0; i < (int) size; i++)
count_array[array[i]]++;
for (i = 1; i < max + 1; i++)
count_array[i] += count_array[i - 1];
output_array = malloc(sizeof(int) * size);
if (output_array == NULL)
{
free(count_array);
return;
}
for (i = size - 1; i >= 0; i--)
{
j = count_array[array[i]] - 1;
output_array[j] = array[i];
count_array[array[i]]--;
}
for (i = 0; i < (int) size; i++)
array[i] = output_array[i];
printf("%d", count_array[0]);
for (i = 1; i < max + 1; i++)
printf(", %d", count_array[i]);
printf("\n");
free(count_array);
free(output_array);
}
