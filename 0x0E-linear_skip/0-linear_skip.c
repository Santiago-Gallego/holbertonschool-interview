#include "search.h"
/**
 * lin_search - linear search in a linked list
 * @prev: pointer to node at start of search
 * @exp: pointer to node at end of search
 * @value: value to search
 * Return: pointer to node where value is found, or NULL if not found
 */
skiplist_t *lin_search(skiplist_t *prev, skiplist_t *exp, int value)
{
	printf("Value found between indexes [%li] and [%li]\n",
			prev->index, exp->index);
	while (prev != exp->next)
	{
		printf("Value checked at index [%li] = [%i]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip -  searches for a value in a sorted skip list of integers
 * @list: input list
 * @value: value to be searched
 * Return: pointer to node where value is found, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *exp;

	if (!list)
		return (NULL);
	exp = list;
	while (exp)
	{
		prev = exp;
		if (exp->express)
			exp = exp->express;
		else
		{
			while (exp->next)
				exp = exp->next;
			break;
		}
		printf("Value checked at index [%li] = [%i]\n", exp->index, exp->n);
		if (exp->n >= value)
			return (lin_search(prev, exp, value));
	}
	return (lin_search(prev, exp, value));
}
