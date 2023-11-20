#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sorts bitonic sequence inside an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t n, hop = seq / 2;

	if (seq > 1)
	{
		for (n = start; n < start + hop; n++)
		{
			if ((flow == UP && array[n] > array[n + hop]) ||
			    (flow == DOWN && array[n] < array[n + hop]))
				swap_ints(array + n, array + n + hop);
		}
		bitonic_merge(array, size, start, hop, flow);
		bitonic_merge(array, size, start + hop, hop, flow);
	}
}

/**
 * bitonic_seq - Converts an array of integers into a bitonic sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of a block for building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @flow: direction to sort bitonic sequence block.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t set = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, set, UP);
		bitonic_seq(array, size, start + set, set, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
