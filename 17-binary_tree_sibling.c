#include "binary_trees.h"

/**
 * binary_tree_sibling - finds a node's sibling in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 * Return: a pointer to the sibling if present else NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
