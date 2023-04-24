#include "sort.h"


/**
 * lomuto - used to partition an array in two parts
 * @arr: array to be partitioned
 * @low: this is the first elem of the array
 * @high: this is the last elem of the array
 * @size:  this is the size of the array
 * Return: returns the index of the pivot
 */
size_t lomuto(int *arr, int low, int high, size_t size)
{
int pivot = arr[high];
int i = low - 1, j, tmp;

for (j = low; j < high; j++)
{
if (arr[j] < pivot)
{
i++;
if (i != j)
{
tmp = arr[i];
arr[i] = arr[j];
arr[j] = tmp;
print_array(arr, size);
}
}
}

if (i + 1 != high)
{
tmp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = tmp;
print_array(arr, size);
}
return (i + 1);
}

/**
 * quicksort - calls the lomuto partition till the condition is met
 * @array: array to be sorted
 * @start: this is the first elem of the array
 * @end: this is the last elem of the array
 * @size: this is the size of th array
 */

void quicksort(int *array, int start, int end, size_t size)
{
if (start < end)
{
size_t pivot = lomuto(array, start, end, size);

quicksort(array, pivot + 1, end, size);
quicksort(array, start, pivot - 1, size);
}
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array to be partitioned
 * @size: this is the size of the of the array
 */
void quick_sort(int *array, size_t size)
{
quicksort(array, 0, size - 1, size);
}
