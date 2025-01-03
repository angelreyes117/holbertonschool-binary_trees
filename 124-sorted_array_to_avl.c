#include "binary_trees.h"
#include <stdlib.h>

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created subtree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	int mid;
		avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = build_avl_tree(array, start, mid - 1, node);
	node->right = build_avl_tree(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, NULL));
}
