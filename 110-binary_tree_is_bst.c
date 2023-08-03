#include "binary_trees.h"
#include "limits.h"

int bst_checker(const binary_tree_t *tree, int smallest, int largest);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if valid else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* INT_MIN and INT_MAX will be coming from the limits.h file */
	return (bst_checker(tree, INT_MIN, INT_MAX));
}

/**
 * bst_checker - checks for a valid binary search tree( helper ).
 * @tree: A pointer to the root node of the tree to check.
 * @smallest: The value of the smallest node visited thus far.
 * @largest: The value of the largest node visited tlargests far.
 * Return: 1 if valid, otherwise, 0.
 */
int bst_checker(const binary_tree_t *tree, int smallest, int largest)
{
	if (tree != NULL)
	{
		if (tree->n < smallest || tree->n > largest)
			return (0);
		return (bst_checker(tree->left, smallest, tree->n - 1) &&
			bst_checker(tree->right, tree->n + 1, largest));
	}
	return (1);
}
