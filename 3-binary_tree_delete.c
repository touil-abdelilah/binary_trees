#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 * Return: nothing.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
	{
		return;/* If tree is NULL, return */
	}
	else
	{
		if (tree != NULL)
		{
			/* Recursively delete the left subtree */
			binary_tree_delete(tree->left);
			/* Recursively delete the right subtree */
			binary_tree_delete(tree->right);
		}
		/* Free the memory allocated for the current node */
		free(tree);
	}

}
