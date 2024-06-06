#include "binary_trees.h"

/**
 * array_to_bst - Builds a BST from an array
 * @array: a list of integers
 * @size: size of the array
 * Return: root node of the BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return (root);
}
