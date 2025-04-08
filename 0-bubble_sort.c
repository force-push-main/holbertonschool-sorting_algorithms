#include "sort.h"

/**
 * bubble_sort - entry point
 *
 * Description: sorts array in ascending order
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
	}
}
