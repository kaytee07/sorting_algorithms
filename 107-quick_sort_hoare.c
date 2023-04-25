#include "sort.h"


/**
 * swap - swaps two integers in an array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * qsh_partition - partitions an array of integers
 * @array: the array to partition
 * @lo: the lowest index of the partition
 * @hi: the highest index of the partition
 * @size: the size of the array
 *
 * Return: the partition index
 */
int qsh_partition(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi];
    int i = lo - 1, j = hi + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    qsh_recursive(array, 0, size - 1, size);
}

/**
 * qsh_recursive - sorts a partition of an array of integers
 * @array: the array to sort
 * @lo: the lowest index of the partition
 * @hi: the highest index of the partition
 * @size: the size of the array
 */
void qsh_recursive(int *array, int lo, int hi, size_t size)
{
    if (lo < hi)
    {
        int p = qsh_partition(array, lo, hi, size);

        qsh_recursive(array, lo, p, size);
        qsh_recursive(array, p + 1, hi, size);
    }
}
