#include "binary_trees.h"

/**
 *  * bst_search - Searches value Binary Search Tree.
 *   *
 *    * @tree: A pointer root node oBST.
 *     * @value: value search tree.
 *      *
 *       * Return: A pointer node value equals to value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
