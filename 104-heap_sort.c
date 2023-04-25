#include "sort.h"

/**
 * sift_down - repair the heap whose root element is at index start
 * @array: Array of integers to sort
 * @start: Position to start sifting down from
 * @end: Position to stop sifting down
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
int temp;
 size_t root = start, child, swap;
while (2 * root + 1 <= end)
{
child = 2 * root + 1;
swap = root;
if (array[swap] < array[child])
swap = child;
if (child + 1 <= end && array[swap] < array[child + 1])
swap = child + 1;
if (swap == root)
return;
temp = array[root];
array[root] = array[swap];
array[swap] = temp;
print_array(array, size);
root = swap;
}
}

/**
 * heap_sort - sorts an array of integers in ascending order usin hs
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
int start, end, temp; 
if (size <= 1)
return;

for (start = (size - 2) / 2; start >= 0; start--)
sift_down(array, start, size - 1, size);

for (end = size - 1; end > 0; end--)
{
temp = array[end];
array[end] = array[0];
array[0] = temp;
print_array(array, size);
sift_down(array, 0, end - 1, size);
}
}
