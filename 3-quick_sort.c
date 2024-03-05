#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * @size: The size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
int pi;
if (low < high)
{
pi = partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
 * partition - Partitions the array and selects the last element as pivot
 * @array: The array to be sorted
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: The index of the pivot after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
swap_int(&array[i], &array[j]);
print_array(array, size);
}
}
swap_int(&array[i + 1], &array[high]);
print_array(array, size);
return (i + 1);
}


/**
 * swap_int - swaps two integers
 * @first_elem: first integer
 * @second_elem: second integer
*/
void swap_int(int *first_elem, int *second_elem)
{
int temp = 0;
temp = *first_elem;
*first_elem = *second_elem;
*second_elem = temp;
}
