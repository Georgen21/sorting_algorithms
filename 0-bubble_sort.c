#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, len = size;
	bool bubbles = false;

	if (array == NULL || size < 2)
		return;

	while (bubbles == false)
	{
		bubbles = true;
		for (n = 0; n < len - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap_ints(array + n, array + n + 1);
				print_array(array, size);
				bubbles = false;
			}
		}
		len--;
	}
}
