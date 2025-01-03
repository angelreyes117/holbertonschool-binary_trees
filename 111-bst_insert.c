#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *parent, *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL) /* Tree is empty, create the root node */
	{
	*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (current != NULL)
	{
		parent = current;

	if (value < current->n)
		current = current->left;
	else if (value > current->n)
		current = current->right;
	else /* Value already exists, do not insert */
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
