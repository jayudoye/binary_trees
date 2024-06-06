#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a BST
 * @tree: pointer to the root node
 * @value: the value to insert
 * Return: a pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

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
		return (bst_insert(&(*tree)->left, value));
	return (bst_insert(&(*tree)->right, value));
}
