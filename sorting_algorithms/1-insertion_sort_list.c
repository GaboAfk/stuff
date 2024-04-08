/*
 * File: 1-insertion_sort_list.c
 * Auth: Gabriel Morffe
 */

#include "sort.h"
/**
 * swap - auxiliary function that swap double linked nodes
 * @a: double node to swap with @b
 * @b: double node to swap with @a
 */
void swap(listint_t *a, listint_t *b)
{
	a->next = b->next;
	if (b->next)
	b->next->prev = a;

	b->next = a;

	b->prev = a->prev;
	if (a->prev)
		a->prev->next = b;

	a->prev = b;
}
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 *				integers in ascending order using the Insertion sort algorithm
 * @list: list of double linked integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p = *list, *aux;

	if (!list)
		return;

	while (p)
	{
		if (p->next && p->next->n < p->n)
		{
			swap(p, p->next);
			print_list(*list);

		aux = p->prev;
		while (aux)
		{
			if (aux->prev && aux->prev->n > aux->n)
				swap(aux->prev, aux);
				print_list(*list);
				aux = aux->prev;
		}
		}
		p = p->next;
	}
}
