#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
levelorder_queue_t *create_node(binary_tree_t *node);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
				levelorder_queue_t **tail, void (*func)(int));
void free_queue(levelorder_queue_t *head);
void pop(levelorder_queue_t **head);

/**
 *  * binary_tree_levelorder - Goes bin-tree level-order traversal.
 *   *
 *    * @tree: A pointer root node tree traverse.
 *     * @func: A pointer function to call each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 *  * create_node - Creates a new levelorder_queue_t node.
 *   *
 *    * @node: The binary tree node to new node.
 *     *
 *      * Return: If an error occurs, NULL.
 *       *         Otherwise, a pointer new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 *  * pint_push - Runs a function on binary tree node and
 *   *             pushes children levelorder_queue_t queue.
 *    *
 *     * @node: The binary tree node to print and push.
 *      * @head: A double pointer head queue.
 *       * @tail: A double pointer tail queue.
 *        * @func: A pointer function to call @node.
 *         *
 *          * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
				levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 *  * free_queue - levelorder_queue_t queue.
 *   *
 *    * @head: A pointer head queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 *  * pop - Pops head levelorder_queue_t queue.
 *   *
 *    * @head: A double pointer head queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
