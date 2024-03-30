#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
				levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);

/**
 *  * binary_tree_is_complete - binary tree is complete.
 *   *
 *    * @tree: A pointer root node tree.
 *     *
 *      * Return: 0 if tree NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}

/**
 *  * create_node - Creates  new levelorder_queue_t node.
 *   *
 *    * @node: The binary tree node new node.
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
 *  * free_queue - Frees a levelorder_queue_t queue.
 *   *
 *    * @head: A pointer head of queue.
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
 *  * push - Pushes a node of levelorder_queue_t queue.
 *   *
 *    * @node: The binary tree node to print and push.
 *     * @head: A double pointer head queue.
 *      * @tail: A double pointer tail queue.
 *       *
 *        * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
				levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 *  * pop - Pops the head levelorder_queue_t queue.
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
