#include "binary_trees.h"

/**
 * _search_tree - Search for value in binary search tree
 * @tree: root of tree to search
 * @value: value to search for
 * Return: pointer to node containing value, or NULL if not found
 */
bst_t *_search_tree(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *) tree);
	else if (value < tree->n)
		return (_search_tree(tree->left, value));
	else
		return (_search_tree(tree->right, value));
}

/**
 * _prune - Removes node of a BST when it has no children
 * @root: root of tree in which `ophan` resides
 * @ophan: node to remove
 * @parent: pointer to member of parent that points to `ophan`
 * Return: pointer to root in case root is replaced
 */
bst_t *_prune(bst_t *root, bst_t *ophan, bst_t **parent)
{
	if (ophan->parent == NULL)
	{
		free(ophan);
		return (NULL);
	}
	*parent = NULL;
	free(ophan);
	return (root);
}

/**
 * _prune_left - Subroutine to remove node of BST for an only left child
 * @root: root of tree in which `ophan` resides
 * @ophan: node to remove
 * @parent: pointer to member of parent that points to `ophan`
 * Return: a pointer to the root in case root is replaced
 */
bst_t *_prune_left(bst_t *root, bst_t *ophan, bst_t **parent)
{
	ophan->left->parent = ophan->parent;
	if (ophan->parent == NULL)
	{
		root = ophan->left;
		free(ophan);
		return (root);
	}
	*parent = ophan->left;
	free(ophan);
	return (root);
}

/**
 * bst_remove - Remove node from binary search tree with value equal to `value`
 * @root: root of tree from which to remove node
 * @value: value of node to remove
 * Return: pointer to new root of tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t **parent, *node, *ophan = _search_tree(root, value);

	if (ophan == NULL)
		return (root);
	if (ophan->parent != NULL)
		parent = (ophan == ophan->parent->left ?
				  &ophan->parent->left : &ophan->parent->right);
	if (ophan->right == NULL)
	{
		if (ophan->left == NULL)
			return (_prune(root, ophan, parent));
		return (_prune_left(root, ophan, parent));
	}
	else
	{
		node =  ophan->right;
		while (node->left != NULL)
			node =  node->left;
		if (node != ophan->right)
		{
			ophan->right->parent = node;
			node->parent->left = node->right;
			if (node->right != NULL)
				node->right->parent = node->parent;
			node->right = ophan->right;
		}
		if (ophan->left != NULL)
			ophan->left->parent = node;
		node->left = ophan->left;
		node->parent = ophan->parent;
		if (ophan->parent == NULL)
		{
			free(ophan);
			return (node);
		}
		free(ophan);
		*parent = node;
		return (root);
	}
}
