#include "binary_trees.h"

/**
 * _binary_tree_size - Measures the size of a binary tree
 * @tree: the root node of the tree to measure the size
 * Return: number of nodes in the tree
 */
size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + _binary_tree_size(tree->left) +
			_binary_tree_size(tree->right));
}


/**
 * _binary_tree_is_full - Checks if a binary tree is full
 * @tree: the root node of the tree to check
 * Return: 1 if it is full else 0
 */
int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1);

	return (_binary_tree_is_full(tree->left) &&
			_binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: the root node of the tree to check
 * Return: 1 if true else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1); /* tree with only 1 node */
	if (_binary_tree_size(tree->left) !=
			_binary_tree_size(tree->right))
		return (0);
	return (_binary_tree_is_full(tree->left) &&
			_binary_tree_is_full(tree->right));
}
