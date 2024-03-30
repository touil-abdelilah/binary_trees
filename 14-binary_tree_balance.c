#include "binary_trees.h"

/**
 *  * binary_tree_balance - Measures balance factor binary tree.
 *   *
 *    * @tree: A pointer root node tree.
 *     *
 *      * Return: 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 *  * binary_tree_height - height binary tree..
 *   *
 *    * @tree: A pointer root node tree to height.
 *     *
 *      * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((lef > rig) ? lef : rig);
	}

	return (0);
}
