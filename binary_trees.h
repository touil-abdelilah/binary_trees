#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

/**
 *  * struct binary_tree_s - Binary tree node
 *   *
 *    * @n: stored node
 *     * @parent: Pointer parent node
 *      * @left: Pointer left child node
 *       * @right: Pointer right child node
 */
struct binary_tree_s
{
		int n;
			struct binary_tree_s *parent;
				struct binary_tree_s *left;
					struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 *  * struct levelorder_queue_s - Level order traversal.
 *   * @node: node of binary tree.
 *    * @next: next node binary tree.
 */
typedef struct levelorder_queue_s
{
		binary_tree_t *node;
			struct levelorder_queue_s *next;
} levelorder_queue_t;


/* helper function */
void binary_tree_print(const binary_tree_t *);

/* Tasks  structurs */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
#endif /* BINARY_TREES_H */
