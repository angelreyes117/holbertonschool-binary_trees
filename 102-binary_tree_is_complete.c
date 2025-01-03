#include "binary_trees.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree. If tree is NULL, return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_complete - Helper function to check if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @node_count: Total number of nodes in the tree
 *
 * Return: true if the tree is complete, false otherwise
 */
bool is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (tree == NULL)
		return (true);

	if (index >= node_count)
		return (false);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node_count;

	if (tree == NULL)
		return (0);

	node_count = binary_tree_size(tree);

	return (is_complete(tree, 0, node_count) ? 1 : 0);
}
