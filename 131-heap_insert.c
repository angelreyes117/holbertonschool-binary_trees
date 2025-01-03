#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: Pointer to the parent node of the node to create.
 * @value: Value to put in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * swap_values - Swaps the values of two nodes.
 * @node1: First node.
 * @node2: Second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_up - Ensures the max-heap property by swapping upwards.
 * @node: Pointer to the newly inserted node.
 *
 * Return: Pointer to the final position of the node.
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
    return (node);
}

/**
 * insert_node - Inserts a node into the first available position.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to insert.
 *
 * Return: Pointer to the inserted node.
 */
heap_t *insert_node(heap_t **root, int value)
{
    heap_t *new_node, *current;
    queue_t *queue = NULL;

    if (!(*root))
        return ((*root = binary_tree_node(NULL, value)));

    queue = queue_push(queue, *root);
    while (queue)
    {
        current = queue_pop(&queue);

        if (!current->left)
        {
            new_node = binary_tree_node(current, value);
            current->left = new_node;
            return (new_node);
        }
        queue = queue_push(queue, current->left);


