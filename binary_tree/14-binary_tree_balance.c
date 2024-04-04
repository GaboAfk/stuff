/*
 * File: 14-binary_tree_balance.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */
#include "binary_trees.h"

/**
 * binary_tree_balance - Function that measures the balance
 *							factor of a binary tree.
 * @tree:  Pointer to the root node of the tree to measure the balance factor.
 * Return: Balance factor of @tree. 0 if it is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	left_height = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_balance(tree->right) : 0;

	return (left_height - right_height);
}
