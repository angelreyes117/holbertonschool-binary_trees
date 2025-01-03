#include "binary_trees.h"
#include <stddef.h>

/**
 * is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * @index: Index of the current node in a complete binary tree.
 * @node_count: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * count_nodes - Counts the nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The total number of nodes in the tree.
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_max_heap - Checks if a binary tree satisfies the Max-Heap property.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree satisfies the Max-Heap property, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t node_count;

	if (!tree)
		return (0);

	node_count = count_nodes(tree);

	if (!is_complete(tree, 0, node_count))
		return (0);

	return (is_max_heap(tree));
}
