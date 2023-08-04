#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the given array.
 * Return: A pointer to the root node of the created AVL else NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&avl_tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (avl_tree);
}
