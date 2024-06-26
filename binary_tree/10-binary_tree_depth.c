/*
 * File: 10-binary_tree_depth.c
 * Auth: Gabriel Morffe, Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_depth - Function that measures the depth of
 *							a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 * Return: Depth of the node or 0 if is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree && tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);
}
