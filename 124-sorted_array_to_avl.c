#include "binary_trees.h"

/**
 * _sorted_array_to_avl - A subroutine that creates
 * the left and right subtrees recursively
 * @array: a sorted array of integers
 * @size: size of the array
 * @parent: parent of the current subtree
 * Return: root of the created AVL tree
 */
avl_t *_sorted_array_to_avl(int *array, size_t size, avl_t *parent)
{
	int mid;
	avl_t  *root;

	if (!array || !size)
		return (NULL);

	mid = size / 2;
	root = binary_tree_node(parent, array[mid]);

	if (size == 1)
		return (root);

	root->left = _sorted_array_to_avl(array, mid, root);
	root->right = _sorted_array_to_avl(array + mid + 1, size - mid - 1, root);

	return (root);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array
 * @array: a sorted array of integers
 * @size: size of the array
 * Return: root of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (_sorted_array_to_avl(array, size, NULL));
}
