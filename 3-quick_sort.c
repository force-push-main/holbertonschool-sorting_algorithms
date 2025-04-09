#include "sort.h"

/**
 * lomuto - entry point
 *
 * Description: recursively sorts array
 * @array: array to sort
 * @low: lowest index to search from
 * @high: highest index to search to
 * @size: size of array
 * Return: void
 */

void lomuto(int *array, int low, int high, size_t size)
{
	int i, j, p, tmp;

	if (low >= high)
		return;

	p = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= p)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		tmp = array[high];
		array[high] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}

	lomuto(array, low, i - 1, size);
	lomuto(array, i + 1, high, size);
}


/**
 * quick_sort - entry point
 *
 * Description: calls lomuto
 * @array: array to search
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	lomuto(array, 0, size - 1, size);
}
