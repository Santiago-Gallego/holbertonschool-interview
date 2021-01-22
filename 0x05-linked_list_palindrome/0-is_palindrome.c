#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: list of listint_t
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *cp;
	int len = 0, i = 0, r = 0;
	int array[1000000];

	if (!head)
		return (0);

	cp = *head;
	while (cp != NULL)
	{
		array[len] = cp->n;
		len++;
		cp = cp->next;
	}

	for (i = 0, r = len - 1; i < (len / 2); i++, r--)
	{
		if (array[i] != array[r])
			return (0);
	}
	return (1);
}
