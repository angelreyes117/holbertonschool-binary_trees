#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps the values of two nodes
 * @node1: First node
 * @node2: Second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * bubble_up - Ensures Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void bubble_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * find_insert_position - Finds the next insertion position in a complete tree
 * @root: Pointer to the root of the heap
 * @queue: Array for level-order traversal
 * @size: Size of the queue
 *
 * Return: Pointer to the parent node for insertion
 */
heap_t *find_insert_position(heap_t *root, heap_t **queue, size_t size)
{
	size_t front = 0, back = 0;

	queue[back++] = root;

	while (front < back)
	{
		heap_t *current = queue[front++];

		if (!current->left || !current->right)
			return (current);

		queue[back++] = current->left;
		queue[back++] = current->right;
	}

	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert in the heap
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	heap_t *queue[1024]; /* Arbitrary size for the complete tree level */

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insert_position(*root, queue, 1024);

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	bubble_up(new_node);

	return (new_node);
}
