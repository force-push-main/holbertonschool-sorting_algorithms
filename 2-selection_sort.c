#include "sort.h"

/**
 * selection_sort - entry point
 *
 * Description: sorts array using selection sort algo
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, pos_min;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		pos_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos_min])
				pos_min = j;
		}
		if (pos_min != i)
		{
			tmp = array[i];
			array[i] = array[pos_min];
			array[pos_min] = tmp;
			print_array(array, size);
		}
	}
}
