/*
* File: 3-quick_sort.c
* Auth: Gabriel Morffe,Agustin Rodriguez
*/

#include "sort.h"
#include <stdio.h>
/**
 * recursion_quick - auxiliary function that gets a delimited array and sort it
 * @array: array to sort
 * @start: begining of @array
 * @end: end of @array
 * @size: size of @array
 */
void recursion_quick(int *array, size_t start, size_t end, size_t size)
{
	size_t i = start, j;
	int temp, pivot;

	if (end < start || end == start)
		return;
	pivot = array[end];
	for (j = start; j < end; j++)
	{

		if (array[j] < pivot)
		{
			if (j != i)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	if (i > 0)
		recursion_quick(array, start, i - 1, size);
	recursion_quick(array, i + 1, end, size);
}
/**
 * quick_sort - function that sorts an array of integers in ascending
 *					order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	recursion_quick(array, 0, size - 1, size);
}

