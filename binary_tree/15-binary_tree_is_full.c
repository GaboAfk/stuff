/*
 * File: 15-binary_tree_is_full.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */
#include "binary_trees.h"

/**
 * binary_tree_is_full - Function that checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if @tree is full. 0 if not or @tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full_left = 0, full_right = 0;

	if (!tree)
		return (0);

	full_left = tree->left ? 1 + binary_tree_is_full(tree->left) : 0;
	full_right = tree->right ? 1 + binary_tree_is_full(tree->right) : 0;

	return (full_left == full_right);
}
