avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
            (*tree)->left = binary_tree_node(*tree, value);
        else
            avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
            (*tree)->right = binary_tree_node(*tree, value);
        else
            avl_insert(&((*tree)->right), value);
    }
    else
    {
        return (NULL); /* Value already exists */
    }

    /* Balance the tree */
    *tree = balance_tree(tree);

    return (*tree);
}
