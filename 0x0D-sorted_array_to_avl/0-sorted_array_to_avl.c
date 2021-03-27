#include "binary_trees.h"
/**
 * array_to_avl - extra function
 * @array: pointer to the array
 * @start: starting index
 * @end: ending index
 * @parent: pointer to parent node
 * Return: new node
 */
avl_t *array_to_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *new;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new = malloc(sizeof(avl_t));

	if (new == NULL)
		return (NULL);

	new->n = array[mid];
	new->parent = parent;
	new->left = array_to_avl(array, start, mid - 1, new);
	new->right = array_to_avl(array, mid + 1, end, new);

	return (new);
}

/**
 * sorted_array_to_avl - inserts sorted array elements to AVL tree
 * @array: pointer to sorted array
 * @size: number of elementss of array
 * Return: node to the root of AVL tree, otherwise NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (array == NULL)
		return (NULL);

	return (array_to_avl(array, 0, size - 1, NULL));
}
