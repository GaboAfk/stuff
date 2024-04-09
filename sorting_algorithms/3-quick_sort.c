/*
* File: 3-quick_sort.c
* Auth: Gabriel Morffe,Agustin Rodriguez
*/

#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending
 *					order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j = -1;
	int temp, pivot, *greaters;

	if (!array || !size)
		return;

	pivot = array[size - 1];

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			if (i > 0)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	j++;
	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
	print_array(array, size);


	quick_sort(array, j);
	greaters = &array[size - j];
	quick_sort(greaters, size - j - 1);
}
