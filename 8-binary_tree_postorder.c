#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses the tree in the order: left, right, node
 * @tree: the tree to traverse
 * @func: the function to call on each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
