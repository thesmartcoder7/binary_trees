#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node else NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *node;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			node = binary_tree_node(current, value);
			if (node == NULL)
				return (NULL);
			return (*tree = node);
		}

		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			node = binary_tree_node(current, value);
			if (node == NULL)
				return (NULL);
			return (current->left = node);
		}
		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			node = binary_tree_node(current, value);
			if (node == NULL)
				return (NULL);
			return (current->right = node);
		}
	}
	return (NULL);
}
