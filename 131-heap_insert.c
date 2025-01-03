#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swap the values of two nodes.
 * @node1: First node.
 * @node2: Second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp;

    temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * find_insert_position - Find the next position to insert in level order.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the parent node for insertion.
 */
heap_t *find_insert_position(heap_t *root)
{
    heap_t **queue;
    size_t front = 0, back = 0;
    heap_t *current;

    queue = malloc(sizeof(heap_t *) * 1024); /* Sufficient size for a binary heap */
    if (!queue)
        return (NULL);

    queue[back++] = root;

    while (front < back)
    {
        current = queue[front++];
        if (!current->left || !current->right)
        {
            free(queue);
            return (current);
        }
        queue[back++] = current->left;
        queue[back++] = current->right;
    }

    free(queue);
    return (NULL);
}

/**
 * heapify_up - Reorganize the heap after insertion.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to insert in the heap.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    parent = find_insert_position(*root);
    if (!parent)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    heapify_up(new_node);

    return (new_node);
}
