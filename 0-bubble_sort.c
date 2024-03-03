#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: the array
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
size_t i;
bool swap = true;
if (array == NULL || size < 2)
{
return;
}
while (swap == true)
{
swap = false;
for (i = 0; i  < size; i++)
{
if (array[i] > array[i + 1])
{
swap_int(&array[i], &array[i + 1]);
print_array(array, size);
swap = true;
}
}
}
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
