#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node to the left of a node
 * @parent: the parent node
 * @value: value of the new node
 * Return: the newly inserted node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (!node)
		return (NULL);
	if (parent->left)
	{
		node->left = parent->left;
		node->left->parent = node;
	}
	parent->left = node;

	return (node);
}
