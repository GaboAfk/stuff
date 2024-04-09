/*
* File: 2-selection_sort.c
* Auth: Gabriel Morffe,Agustin Rodriguez
*/

#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 *					in ascending order using the Selection sort algorithm
 * @array: array of int to sort
 * @size: size of @array
 */
void selection_sort(int *array, size_t size)
{
	int min, aux;
	size_t i, j, n = 0;

	if (!array || !size)
		return;

	while (n < size)
	{
		min = array[n];
		j = n;
		for (i = n + 1; i < size; i++)
		{
			if (min > array[i])
			{
				min = array[i];
				j = i;
			}
		}

		if (j != n)
		{
			aux = array[j];
			array[j] = array[n];
			array[n] = aux;
			print_array(array, size);
		}
		n++;
	}
}
