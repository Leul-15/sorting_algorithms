#include "sort.h"
/**
 * quick_sort_recur - sorts an array of integers in ascending order using
 * the Selection sort algorithm using recursion
 * @array: pointer to array
 * @size: size of the array
 * @array_num: initial pointer to array
 * @size_num: initial size of the array
 **/
void quick_sort_recur(int *array_num, size_t size_num, int *array, size_t size)
{
	size_t j, new;
	int new2;
	int i = -1, n, pivot = array[size - 1];

	if (array && size > 1)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				new = i;
				if (new != j && array[j] != array[new])
				{
					n = array[j];
					array[j] = array[i];
					array[i] = n;
					print_array(array_num, size_num);
				}
			}


		}
		new2 = size;
		if (new2 - 1 != i + 1 && array[new2 - 1] != array[i + 1])
		{
			array[size - 1] = array[i + 1];
			array[i + 1] = pivot;
			print_array(array_num, size_num);
		}
		if (i > 0)
		{
			quick_sort_recur(array_num, size_num, array, i + 1);
		}
		quick_sort_recur(array_num, size_num, array + i + 2,  size - (i + 2));
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: pointer to array
 * @size: size of the array
**/
void quick_sort(int *array, size_t size)
{
	int *array_num;
	size_t size_num;

	if (array)
	{
		array_num = array;
		size_num = size;
		quick_sort_recur(array_num, size_num, array, size);
	}
}
