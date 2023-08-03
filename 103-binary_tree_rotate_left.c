#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: new root node's pointer after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pvt = tree->right;
	tmp = pvt->left;
	pvt->left = tree;
	tree->right = tmp;

	if (tmp != NULL)
		tmp->parent = tree;

	tmp = tree->parent;
	tree->parent = pvt;
	pvt->parent = tmp;

	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pvt;
		else
			tmp->right = pvt;
	}

	return (pvt);
}
