#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_insert_node - Helper to insert a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_node(avl_t **tree, int value)
{
	avl_t *new_node;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			if (!new_node)
				return (NULL);
			(*tree)->left = new_node;
		}
		else
		{
			new_node = avl_insert_node(&((*tree)->left), value);
		}
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
		if (!new_node)
			return (NULL);
		(*tree)->right = new_node;
		}
		else
		{
			new_node = avl_insert_node(&((*tree)->right), value);
		}
	}
	else
	{
		return (NULL); /* Value already exists */
	}

	return (new_node);
}

/**
 * balance_tree - Balances an AVL tree after insertion
 * @tree: Double pointer to the root node of the tree
 *
 * Return: Pointer to the new root after balancing
 */
avl_t *balance_tree(avl_t **tree)
{
	int balance;

	if (!tree || !(*tree))
		return (NULL);

	balance = binary_tree_balance(*tree);

	if (balance > 1) /* Left heavy */
	{
		if (binary_tree_balance((*tree)->left) < 0)
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1) /* Right heavy */
	{
		if (binary_tree_balance((*tree)->right) > 0)
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);
	*tree = new_node;
	return (new_node);
	}

	new_node = avl_insert_node(tree, value);
	if (new_node)
		*tree = balance_tree(tree);

	return (new_node);
}
