#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node to the right of a node
 * @parent: the parent node
 * @value: value of the new node
 * Return: the newly inserted node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (!node)
		return (NULL);
	if (parent->right)
	{
		node->right = parent->right;
		node->right->parent = node;
	}
	parent->right = node;

	return (node);
}
