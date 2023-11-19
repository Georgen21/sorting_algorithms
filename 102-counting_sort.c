#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, m;

	for (max = array[0], m = 1; m < size; m++)
	{
		if (array[m] > max)
			max = array[m];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: Prints the counted array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *order, *sorted, max, m;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	order = malloc(sizeof(int) * (max + 1));
	if (order == NULL)
	{
		free(sorted);
		return;
	}

	for (m = 0; m < (max + 1); m++)
		order[m] = 0;
	for (m = 0; m < (int)size; m++)
		order[array[m]] += 1;
	for (m = 0; m < (max + 1); m++)
		order[m] += order[m - 1];
	print_array(order, max + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[order[array[m]] - 1] = array[m];
		order[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];

	free(sorted);
	free(order);
}
