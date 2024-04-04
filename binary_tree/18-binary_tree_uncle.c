/*
 * File: 18-binary_tree_uncle.c
 * Auth: Gabriel Morffe, Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: pointer to the node to find the uncle.
 * Return: pointer to the uncle node. NULL if node is NULL or has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandpa;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grandpa = node->parent->parent;

	return (grandpa->right == node->parent ? grandpa->left : grandpa->right);
}
