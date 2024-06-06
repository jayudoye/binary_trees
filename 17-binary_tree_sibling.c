#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: the node to find the sibling
 * Return: the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
