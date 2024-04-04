/*
 * File: 0-binary_tree_node.c
 * Auth: Gabriel Morffe, Bryan Aleman
 */

#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: pointer to the parent of the node .
 * @value: is the value to put in the new node.
 * Return: pointer to the new node (Success). NULL (Failure).
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!value)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);

}
