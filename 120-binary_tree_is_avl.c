#include "binary_trees.h"

/**
 * max - Returns the maximum of 2 numbers
 * @a: first number
 * @b: second number
 * Return: the greater of a and b
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: the height of a tree
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	return (1 + max(left_height, right_height));
}

/**
 * binary_tree_is_balanced - Checks if a binary tree is balanced
 * @tree: pointer to the root node
 * Return: 1 if it is balanced else 0
 */
int binary_tree_is_balanced(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_balanced(tree->left) &&
			binary_tree_is_balanced(tree->right));
}

/**
 * _binary_tree_is_bst - Checks if a tree is BST
 * @tree: pointer to the root node
 * @min: minimum possible value
 * @max: maximum possible value
 * Return: 1 if it is BST else 0
 */
int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
	{
		return (0);
	}

	return _binary_tree_is_bst(tree->left, min, tree->n) &&
		   _binary_tree_is_bst(tree->right, tree->n, max);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL
 * @tree: root of the tree to check
 * Return: 1 if it is an AVL else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_bst, is_balanced;

	if (tree == NULL)
		return (0);

	is_bst = _binary_tree_is_bst(tree, INT_MIN, INT_MAX);
	is_balanced = binary_tree_is_balanced(tree);

	return (is_bst && is_balanced);
}
