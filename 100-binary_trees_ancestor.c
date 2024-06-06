#include "binary_trees.h"

/**
 * _binary_tree_depth - Measures the distance of a node from the root
 * @tree: pointer to a node
 * Return: the depth of the node
 */
size_t _binary_tree_depth(const binary_tree_t *tree)
{
	size_t  depth = 0;
	const binary_tree_t *node;

	if (!tree || !tree->parent)
		return (0);

	node = tree;

	while (node->parent)
	{
		depth += 1;
		node = node->parent;
	}

	return (depth);
}


/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t df = _binary_tree_depth(first);
	size_t ds = _binary_tree_depth(second);

	if (!first || !second)
		return (NULL);

	while (df > ds)
	{
		first = first->parent;
		df--;
	}
	while (ds > df)
	{
		second = second->parent;
		ds--;
	}
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
