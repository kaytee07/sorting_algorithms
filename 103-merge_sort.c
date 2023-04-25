#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of an array
 *
 * @arr: The array containing the subarrays to merge
 * @size: The size of the array
 * @l: The left subarray
 * @r: The right subarray
 * @r_s: size of the right sub array
 * @l_s:size of the left subarray
 */
void merge(int *arr, size_t size, int *l, size_t l_s, int *r, size_t r_s)
{
size_t i = 0, j = 0, k = 0;
int *tmp = malloc(sizeof(int) * size);

printf("Merging...\n[left]: ");
print_array(l, l_s);
printf("[right]: ");
print_array(r, r_s);

while (i < l_s && j < r_s)
{
if (l[i] <= r[j])
tmp[k++] = l[i++];
else
tmp[k++] = r[j++];
}

while (i < l_s)
tmp[k++] = l[i++];

while (j < r_s)
tmp[k++] = r[j++];

for (i = 0; i < size; i++)
arr[i] = tmp[i];

printf("[Done]: ");
print_array(arr, size);

free(tmp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              top-down merge sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
size_t mid;
int *left, *right;
if (size < 2)
return;

mid = size / 2;
left = array;
right = array + mid;

merge_sort(left, mid);
merge_sort(right, size - mid);
merge(array, size, left, mid, right, size - mid);
}
