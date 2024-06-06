#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: the root node of the tree to check
 * Return: 1 if it is full else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
