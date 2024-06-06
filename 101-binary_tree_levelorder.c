#include "binary_trees.h"


/**
 * tree_height - A function to find the height of the binary tree
 * @tree: Pointer to the binary tree
 * Return: Height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return  (left_height + 1);
	else
		return (right_height + 1);
}


/**
 * print_level - A function to print nodes at a specific level
 * @tree: Pointer to the binary tree
 * @level: Level to print
 * @func: Pointer to the function to call for each node
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}


/**
 * binary_tree_levelorder - Function for level-order traversal without a queue
 * @tree: Pointer to the root of the binary tree
 * @func: Pointer to the function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, i;

	if (!tree || !func)
		return;

	height = tree_height(tree);

	for (i = 1; i <= height; i++)
		print_level(tree, i, func);
}
