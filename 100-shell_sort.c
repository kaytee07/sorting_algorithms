#include "sort.h"


/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm and the Knuth sequence
 *
 * @array: the array of integers to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t i, j, gap = 1;
int temp;


while (gap < size / 3)
gap = gap * 3 + 1;


while (gap > 0)
{



for (i = gap; i < size; i++)
{
temp = array[i];
for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
array[j] = array[j - gap];
array[j] = temp;
}
gap /= 3;
print_array(array, size);
}
}
