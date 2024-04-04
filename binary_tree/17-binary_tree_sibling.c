/*
 * File: 17-binary_tree_sibling.c
 * Auth: Gabriel Morffe, Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_sibling - Function that finds the sibling of a node.
 * @node: Pointer to the node to find the sibling.
 * Return: Pointer to the sibling node. NULL if node or parent are NULL or
 *				has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *aux;

	if (!node || !node->parent)
		return (NULL);

	aux = node->parent;

	return (aux->left == node ? aux->right : aux->left);
}
