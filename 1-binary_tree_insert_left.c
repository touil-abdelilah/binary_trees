#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Allocate memory for new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize new node */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    /* If parent already has a left-child */
    if (parent->left != NULL)
    {
        /* Set the old left-child as the left-child of the new node */
        new_node->left = parent->left;
        /* Set the parent of the old left-child to the new node */
        parent->left->parent = new_node;
    }

    /* Set the new node as the left-child of the parent */
    parent->left = new_node;

    return (new_node);
}
