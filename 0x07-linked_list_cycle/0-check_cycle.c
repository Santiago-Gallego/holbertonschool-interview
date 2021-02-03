#include "lists.h"
/**
 * check_cycle - checks if the linked list has a cycle.
 * @list: pointer to head of list.
 * Return: 1 if has cycle, otherwise 0.
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise, *hare;

	if (list == NULL || list->next == NULL)
		return (0);

	tortoise = hare = list;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (hare == tortoise)
			return (1);
	}

	return (0);
}
