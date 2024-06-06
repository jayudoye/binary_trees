#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks whether a node is a root
 * @node: the node to check
 * Return: 1 if true else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
