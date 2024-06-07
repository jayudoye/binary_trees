#include "binary_trees.h"

/**
 * balance_avl_tree - Balances an AVL tree
 * @tree: pointer to root node
 * Return: root node of the balanced tree
 */
avl_t *balance_avl_tree(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);

	/* Recursively balance the left and right subtrees */
	tree->left = balance_avl_tree(tree->left);
	tree->right = balance_avl_tree(tree->right);

	/* Check the balance factor of the current node */
	balance = binary_tree_balance(tree);

	/* Perform rotations if needed */
	if (balance > 1 && binary_tree_balance(tree->left) >= 0)
	{
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && binary_tree_balance(tree->right) <= 0)
	{
		return (binary_tree_rotate_left(tree));
	}
	if (balance > 1 && binary_tree_balance(tree->left) < 0)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && binary_tree_balance(tree->right) > 0)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

/**
 * _avl_insert- Inserts a value in AVL tree
 * @tree: pointer to the AVL tree
 * @value: the value to insert
 * Return: the inserted node
 */
avl_t *_avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value == (*tree)->n)
		return (NULL);
	else if (value < (*tree)->n && !(*tree)->left)
	{
		node = binary_tree_node(*tree, value);
		(*tree)->left = node;
		return (node);
	}
	else if (value > (*tree)->n && !(*tree)->right)
	{
		node = binary_tree_node(*tree, value);
		(*tree)->right = node;
		return (node);
	}
	else if (value < (*tree)->n)
		return (_avl_insert(&(*tree)->left, value));
	return (_avl_insert(&(*tree)->right, value));
}

/**
 * avl_insert- Inserts a node in AVL tree
 * @tree: pointer to root node
 * @value: value to insert
 * Return: inserted node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = _avl_insert(tree, value);

	if (!*tree)
		return (NULL);
	*tree = balance_avl_tree(*tree);

	return (node);
}
