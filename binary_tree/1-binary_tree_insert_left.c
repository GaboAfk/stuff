/*
 * File: 1-binary_tree_insert_left.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function that inserts a node as the
 *									left-child of another node.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: Value to store in the new node.
 * Return: Pointer to the created node (Success).
 *			NULL if fails or @parent is NULL (Failure).
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *aux;

	if (!parent || !value)
		return (NULL);

	aux = parent->left; /*guardo la direccion del hijo a la izquierda*/

	node = binary_tree_node(parent, value);
	if (node)/*puede ser NULL*/
		node->left = aux;

	parent->left = node;

	if (aux)
		aux->parent = node;

	return (node);
}
