#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order using
 * selection sort algorithm.
 * @array: An array of integers.
 * @size: Size of an array.
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		minimum = array + m;
		for (n = m + 1; n < size; n++)
			minimum = (array[n] < *minimum) ? (array + n) : minimum;

		if ((array + m) != minimum)
		{
			swap_ints(array + m, minimum);
			print_array(array, size);
		}
	}
}
