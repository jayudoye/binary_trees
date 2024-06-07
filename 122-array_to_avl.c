#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: a list of integers
 * @size: size of the array
 * Return: root node of the AVL tree
 */
bst_t *array_to_avl(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		avl_insert(&root, array[i]);
	}

	return (root);
}
