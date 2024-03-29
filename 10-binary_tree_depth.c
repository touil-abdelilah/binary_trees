#include "binary_trees.h"

/**
 *  * binary_tree_depth - Measures depth node  binary tree.
 *   *
 *    * @tree: A pointer node measure depth.
 *     *
 *      * Return: 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
		return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
