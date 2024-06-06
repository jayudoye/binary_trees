#include "binary_trees.h"

/**
 * _max - compares 2 numbers to find the greater one
 * @x: first number
 * @y: second number
 * Return: the greater number
 */
int _max(int x, int y)
{
	return ((x > y) ? x : y);
}

/**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: the tree to measure the height
 * Return: the height of the tree
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left || tree->right))
		return (1);
	return (_max(_binary_tree_height(tree->left),
				_binary_tree_height(tree->right)) + 1);
}


/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: the tree to measure the balance factor
 * Return: the balance factor (l-r)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree || !(tree->left || tree->right))
		return (0);

	return (_binary_tree_height(tree->left) - _binary_tree_height(tree->right));
}
