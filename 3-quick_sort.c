#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order of subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of array.
 * @left: starting index of the array partition to the order.
 * @right: ending index of the array partition to the order.
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: Uses the Lomuto partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
