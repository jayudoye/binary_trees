#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: pointer to the root node
 * Return: pointer to the root node of the rotated tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root, *old_left, *parent;
	int is_left_child = 0, is_right_child = 0;

	if (!tree || !tree->right)
		return (tree);

	parent = tree->parent;
	if (parent)
	{
		if (parent->left == tree)
			is_left_child = 1;
		else
			is_right_child = 1;
	}
	old_root = tree;
	new_root = tree->right;
	old_left = tree->right->left;
	old_root->right = old_left;
	new_root->parent = parent;
	new_root->left = old_root;
	old_root->parent = new_root;
	if (old_left)
		old_left->parent = old_root;
	if (is_left_child)
		parent->left = new_root;
	if (is_right_child)
		parent->right = new_root;

	return (new_root);
}
