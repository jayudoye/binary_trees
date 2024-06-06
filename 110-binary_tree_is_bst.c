#include "binary_trees.h"

/**
 * is_bst_helper - Checks whether a binary tree is a valid BST
 * @node: a node of a tree
 * @min: minimum possible value
 * @max: possible value
 * Return: 1 if tree is BST else 0
 */
int is_bst_helper(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (is_bst_helper(node->left, min, node->n) &&
			is_bst_helper(node->right, node->n, max));
}


/**
 * binary_tree_is_bst - checks if a tree is a valid BST
 * @tree: a pointer to the root node
 * Return:  if tree is BST else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	int min = INT_MIN; /* Initialize with the minimum possible value */
	int max = INT_MAX; /* Initialize with the maximum possible value */

	if (!tree)
		return (0);

	return (is_bst_helper(tree, min, max));
}
