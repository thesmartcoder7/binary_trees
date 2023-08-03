#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
unsigned char is_leaf(const binary_tree_t *node);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if perfect else 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * is_perfect_recursive - checks if a binary tree is recursively perfect.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: 1 if perfect, else 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * is_leaf - this checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: 1 if is_leaf, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * get_leaf - Returns a leaf of a given tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * depth - Returns the depth of a given node.
 * @tree: A pointer to the node to measure the depth of.
 * Return: The depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}
