#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t front, size_t middle,
		size_t back);
void merge_sort_recursive(int *subarray, int *buffer, size_t front,
		size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sorts a subarray of integers.
 * @subarray: subarray of an array of integers to sort.
 * @buffer: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @middle: middle index of the array.
 * @back: back index of the array.
 */
void merge_subarray(int *subarray, int *buffer, size_t front, size_t middle,
		size_t back)
{
	size_t m, n, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, middle - front);

	printf("[right]: ");
	print_array(subarray + middle, back - middle);

	for (m = front, n = middle; m < middle && n < back; k++)
		buffer[k] = (subarray[m] < subarray[n]) ? subarray[m++]
			: subarray[n++];
	for (; m < middle; m++)
		buffer[k++] = subarray[m];
	for (; n < back; n++)
		buffer[k++] = subarray[n];
	for (m = front, k = 0; m < back; m++)
		subarray[m] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - Implements the merge sort algorithm through
 * recursion.
 * @subarray: subarray of an array of integers to sort.
 * @buffer: the buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t front,
		size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subarray, buffer, front, middle);
		merge_sort_recursive(subarray, buffer, middle, back);
		merge_subarray(subarray, buffer, front, middle, back);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
