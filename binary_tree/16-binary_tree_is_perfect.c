/*
 * File: 16-binary_tree_is_perfect.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */
#include "binary_trees.h"

/**
 * perfect_aux - Function that checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if is perfect. 0 otherwise or @tree is NULL.
 */
int perfect_aux(const binary_tree_t *tree)
{
	int perfect_left = 0, perfect_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		perfect_left = 1 + perfect_aux(tree->left);

	if (tree->right)
		perfect_right = 1 + perfect_aux(tree->right);

	return (perfect_left > perfect_right ? perfect_left : perfect_right);
}

/**
 * binary_tree_is_perfect - Function that checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if is perfect. 0 otherwise or @tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (perfect_aux(tree->left) == perfect_aux(tree->right));
}
