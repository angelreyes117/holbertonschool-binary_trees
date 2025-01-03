#include "binary_trees.h"

/**
 * is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * @index: Current node index.
 * @node_count: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Total number of nodes.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_heap_util - Validates the heap property of a binary tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree satisfies the heap property, otherwise 0.
 */
int is_heap_util(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_heap_util(tree->left) && is_heap_util(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, otherwise 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);

	node_count = count_nodes(tree);

	return (is_complete(tree, 0, node_count) && is_heap_util(tree));
}
