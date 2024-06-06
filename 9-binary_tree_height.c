#include "binary_trees.h"

/**
 * max - Compares 2 numbers to find the greater one
 * @x: first number
 * @y: second number
 * Return: the greater number
 */
int max(int x, int y)
{
	return ((x > y) ? x : y);
}

/**
 * binary_tree_height - Computes the height of a binary tree
 * @tree: the tree to compute height for
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || !(tree->left || tree->right))
		return (0);
	return (max(binary_tree_height(tree->left),
			   binary_tree_height(tree->right)) + 1);
}
