/*
 * File: 9-binary_tree_height.c
 * Auth: Gabriel Morffe and Bryan Aleman
 */
#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the @tree. 0 if it is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftH, rightH;

	leftH = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rightH = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (leftH > rightH ? leftH : rightH);
}
