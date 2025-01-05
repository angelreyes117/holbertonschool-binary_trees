#include "binary_trees.h"

/**
 * binary_tree_size - Counts the number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The total number of nodes in the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Helper function to check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 * @index: Index of the current node in level-order traversal.
 * @total_nodes: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes)
{
	if (!tree)
		return (1);

	if (index >= total_nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, total_nodes) &&
		is_complete(tree->right, 2 * index + 2, total_nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t total_nodes;

	if (!tree)
		return (0);

	total_nodes = binary_tree_size(tree);
	return (is_complete(tree, 0, total_nodes));
}
