/*
 * File: 4-binary_tree_is_leaf.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function that checks if a node is a leaf.
 * @node: Pointer to the node to check.
 * Return: 1 Leaf. 0 Otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->right && !node->left && node->parent)
		return (1);

	return (0);
}
