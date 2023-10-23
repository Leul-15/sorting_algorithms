#include "sort.h"


/**
 * selection_sort - sorts array with selection sort algorithm
 * @array: pointer to array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;
	int new;


	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			new = array[min];
			array[min] = array[i];
			array[i] = new;
			print_array(array, size);
		}
	}
}
