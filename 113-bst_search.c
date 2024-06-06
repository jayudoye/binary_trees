#include "binary_trees.h"

/**
 * bst_search  - Searches for a value in a BST
 * @tree: pointer to root node
 * @value: value of the node to search
 * Return: the target node if found else NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
