/*
 * File: 2-binary_tree_insert_right.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_insert_right - Function that inserts a node as the
 *									right-child of another node.
 * @parent: Pointer to the node to insert the right-child in.
 * @value: Value to store in the new node.
 * Return: Pointer to the created node (Success).
 *			NULL if fails or @parent is NULL (Failure).
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *aux;

	if (!parent || !value)
		return (NULL);

	aux = parent->right; /*guardo la direccion del hijo a la derecha*/

	node = binary_tree_node(parent, value);
	if (node)/*puede ser NULL*/
		node->right = aux;

	parent->right = node;

	if (aux)
		aux->parent = node;

	return (node);
}
