#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Finds the node with the minimum value in a subtree
 * @node: Pointer to the subtree's root
 *
 * Return: Pointer to the node with the minimum value
 */
avl_t *find_min(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * remove_node - Removes a node from the tree
 * @root: Pointer to the root of the subtree
 * @value: Value to remove
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *remove_node(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = remove_node(root->left, value);
	else if (value > root->n)
		root->right = remove_node(root->right, value);
	else
	{
	if (root->left == NULL || root->right == NULL)
	{
		temp = root->left ? root->left : root->right;
		free(root);
		return (temp);
	}
	temp = find_min(root->right);
	root->n = temp->n;
	root->right = remove_node(root->right, temp->n);
	}
	return (root);
}

/**
 * avl_remove - Removes a value from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	root = remove_node(root, value);

	if (root == NULL)
		return (NULL);

	/* Rebalance the tree */
	if (binary_tree_balance(root) > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		root = binary_tree_rotate_right(root);
	}
	else if (binary_tree_balance(root) < -1)
	{
	if (binary_tree_balance(root->right) > 0)
		root->right = binary_tree_rotate_right(root->right);
	root = binary_tree_rotate_left(root);
	}

	return (root);
}
