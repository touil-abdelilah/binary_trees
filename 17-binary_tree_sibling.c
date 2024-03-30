#include "binary_trees.h"

/**
 *  * binary_tree_sibling - Finds the sibling  node.
 *   *
 *    * @node: A pointer node find sibling.
 *     *
 *      * Return: NULL if node is NULL or parent is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
