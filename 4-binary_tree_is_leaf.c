#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks whether a node is a leaf
 * @node: the node to check
 * Return: 1 if true else 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return (1);
}
