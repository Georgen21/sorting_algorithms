#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * order using shell sort algorithm.
 * @array:array of integers.
 * @size: size of the array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t sorted, m, n;

	if (array == NULL || size < 2)
		return;

	for (sorted = 1; sorted < (size / 3);)
		sorted = sorted * 3 + 1;

	for (; sorted >= 1; sorted /= 3)
	{
		for (m = sorted; m < size; m++)
		{
			n = m;
			while (n >= sorted && array[n - sorted] > array[n])
			{
				swap_ints(array + n, array + (n - sorted));
				n -= sorted;
			}
		}
		print_array(array, size);
	}
}
