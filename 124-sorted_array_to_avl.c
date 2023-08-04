#include "binary_trees.h"

avl_t *aux_sort(avl_t *parent, int *array, int start, int end);

/**
 * sorted_array_to_avl - create a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * aux_sort - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @start: position where the array starts
 * @end: position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	binary_tree_t *tree;
	int mid_point = 0;

	if (start <= end)
	{
		mid_point = (start + end) / 2;
		tree = binary_tree_node((binary_tree_t *)parent, array[mid_point]);
		if (tree == NULL)
			return (NULL);
		root = (avl_t *)tree;
		root->left = aux_sort(root, array, start, mid_point - 1);
		root->right = aux_sort(root, array, mid_point + 1, end);
		return (root);
	}
	return (NULL);
}
