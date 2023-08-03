#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: new root node's pointer after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pvt = tree->left;
	tmp = pvt->right;
	pvt->right = tree;
	tree->left = tmp;

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
