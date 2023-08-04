#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: height else 0.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_check - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @smallest: The value of the smallest node visited thus far.
 * @largest: The value of the largest node visited this far.
 * Return: 1, otherwise, 0.
 */
int is_avl_check(const binary_tree_t *tree, int smallest, int largest)
{
	size_t left_h, right_h, diff;

	if (tree != NULL)
	{
		if (tree->n < smallest || tree->n > largest)
			return (0);
		left_h = height(tree->left);
		right_h = height(tree->right);
		diff = left_h > right_h ? left_h - right_h : right_h - left_h;
		if (diff > 1)
			return (0);
		return (is_avl_check(tree->left, smallest, tree->n - 1) &&
			is_avl_check(tree->right, tree->n + 1, largest));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if valid else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_check(tree, INT_MIN, INT_MAX));
}
