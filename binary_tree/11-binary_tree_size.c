/*
 * File: 11-binary_tree_size.c
 * Auth: Gabriel Morffe, Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_size - Function that measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 * Return: Size of tree. 0 if NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t leftsize = 0, rightsize = 0;

	if (!tree)
		return (0);

	leftsize = tree->left ? binary_tree_size(tree->left) : 0;
	rightsize = tree->right ? binary_tree_size(tree->right) : 0;

	return (1 + leftsize + rightsize);
}
