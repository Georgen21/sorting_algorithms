#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - turns a binary tree into a complete binary heap.
 * @array: array of integers representing a binary tree.
 * @size: size of the array in a binary tree.
 * @base: index of the base row of the binary tree.
 * @root: root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, search;

	left = 2 * root + 1;
	right = 2 * root + 2;
	search = root;

	if (left < base && array[left] > array[search])
		search = left;
	if (right < base && array[right] > array[search])
		search = right;

	if (search != root)
	{
		swap_ints(array + root, array + search);
		print_array(array, size);
		max_heapify(array, size, base, search);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: implements the sift-down heap sort
 * algorithm. prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int m;

	if (array == NULL || size < 2)
		return;

	for (m = (size / 2) - 1; m >= 0; m--)
		max_heapify(array, size, size, m);

	for (m = size - 1; m > 0; m--)
	{
		swap_ints(array, array + m);
		print_array(array, size);
		max_heapify(array, size, m, 0);
	}
}
