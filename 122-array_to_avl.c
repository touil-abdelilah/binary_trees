#include "binary_trees.h"

/**
 *  * array_to_avl - Builds an AVL tree array.
 *   *
 *    * @array: A pointer first element array.
 *     * @size: The number of element in the array.
 *      *
 *       * Return: A pointer node of the created AVL tree.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
