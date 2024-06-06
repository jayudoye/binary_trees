#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: the root node of the tree to measure the size
 * Return: number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
