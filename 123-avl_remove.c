#include "binary_trees.h"

/**
 * _balance_avl_tree - Balances an AVL tree
 * @tree: pointer to root node
 * Return: root node of the balanced tree
 */
avl_t *_balance_avl_tree(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);

	/* Recursively balance the left and right subtrees */
	tree->left = _balance_avl_tree(tree->left);
	tree->right = _balance_avl_tree(tree->right);

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
 * _prune - Removes node of an AVL tree when it has no children
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
 * _prune_left - Subroutine to remove node of AVL tree for an only left child
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
 * _avl_remove - Removes node from binary search tree
 * with value equal to `value`
 * @root: root of tree from which to remove node
 * @value: value of node to remove
 * Return: pointer to new root of tree
 */
bst_t *_avl_remove(bst_t *root, int value)
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

/**
 * avl_remove -Removes a node from an AVL tree
 * @root: pointer to root node
 * @value: value of the node to remove
 * Return: the new root node after removing the node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);
	return (_balance_avl_tree(_avl_remove(root, value)));
}
