#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is complete, 0 if it is not.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	/* Flag to indicate if a NULL node is encountered */
	bool null_node_found = false;

	/* Queue for level-order traversal */
	const binary_tree_t *queue[10000], *current;
	int front = -1, rear = -1;

	if (!tree)
		return (0);

	/* Enqueue the root node */
	queue[++rear] = tree;

	while (front != rear)
	{
		current = queue[++front];

		if (current == NULL)
		{
			null_node_found = true;
		}
		else
		{
			/* If a NULL node was previously encountered, the tree is not complete */
			if (null_node_found)
				return (0);

			/* Enqueue the left and right children of the current node */
			queue[++rear] = current->left;
			queue[++rear] = current->right;
		}
	}

	return (1);
}

/**
 * is_max_heap_recursive - Checks if a tree is max heap
 * @node: a pointer to the root node
 * Return: 1 if the tree is max heap
 */
int is_max_heap_recursive(binary_tree_t *node)
{
	if (!node)
		return (1);

	if (!binary_tree_is_complete(node))
		return (0);

	if (node->left && node->left->n > node->n)
		return (0);

	if (node->right && node->right->n > node->n)
		return (0);

	return (is_max_heap_recursive(node->left) &&
			is_max_heap_recursive(node->right));
}

/**
 * binary_tree_is_heap - Checks if a tree is a max heap
 * @tree: a pointer to the root node
 * Return: 1 if true else 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_max_heap_recursive((binary_tree_t *)tree));
}
