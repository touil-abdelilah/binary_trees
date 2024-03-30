#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
				size_t leaf_depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);

/**
 *  * binary_tree_is_perfect - Checks if binary tree perfect.
 *   *
 *    * @tree: A pointer root node tree.
 *     *
 *      * Return: 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 *  * depth - Returns depth
 *   *         node binary tree.
 *    * @tree: A pointer node to measure depth.
 *     *
 *      * Return: The depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 *  * get_leaf - Returns a leaf of a binary tree.
 *   * @tree: A pointer root node tree find a leaf.
 *    *
 *     * Return: A pointer first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 *  * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 *   * @tree: A pointer root node tree.
 *    * @leaf_depth: The depth of one leaf binary tree.
 *     * @level: Level current node.
 *      *
 *       * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 *  * is_leaf - Checks node is a leaf of binary tree.
 *   * @node: A pointer node.
 *    *
 *     * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
