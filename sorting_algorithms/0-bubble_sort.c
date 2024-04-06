/*
 * File: 0-bubble_sort.c
 * Auth: Gabriel Morffe, Agustin Rodriguez
 */

#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending
 *					order using the Bubble sort algorithm
 * @array: array of numbers.
 * @size: size of array.
 * Return: Always 0 (Success)
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = 0;
	int aux;

	if (!array || !size)
		return;

	while (size - n)
	{
		for (i = 0; i < size - n - 1; i++)
			if (array[i] > array[i + 1])
			{
				aux = array[i + 1];
				array[i + 1] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
		n++;
	}
}
