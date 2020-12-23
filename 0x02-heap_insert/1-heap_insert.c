#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

static int NOMEM;

/**
 * extract - pops node from line
 * @qnode: double pointer to line node
 */
void extract(line **qnode)
{
	line *tmp;

	if (*qnode)
	{
		tmp = *qnode;
		*qnode = (*qnode)->next;
		free(tmp);
	}
}

/**
 * maxforhead - swaps values with parent where child is greater
 * @in: nodevalue when stoped swap
 */
void maxforhead(heap_t **in)
{
	heap_t *cursor;
	int tmp;

	for (cursor = *in; cursor->parent; cursor = cursor->parent)
		if (cursor->n > cursor->parent->n)
		{
			tmp = cursor->parent->n;
			cursor->parent->n = cursor->n;
			cursor->n = tmp;
			*in = (*in)->parent;
		}
}

/**
 * pushq - pushes address of cursor to line
 * @qnode: double pointer to line node
 * @cursor: pointer to cursor node
 * Return: pointer to newly created line node
 */
line *pushq(line **qnode, heap_t *cursor)
{
	line **cursorq, *newq = malloc(sizeof(*newq));

	if (!newq)
		return (NULL);
	newq->node = cursor;
	newq->next = NULL;

	cursorq = qnode;
	while (*cursorq)
		cursorq = &(*cursorq)->next;
	newq->next = *cursorq;
	*cursorq = newq;
	return (newq);
}

/**
 * pushinsert - pushes node to line and inserts into binary tree
 * @cursor: pointer to current node
 * @cursorq: double pointer to current line node
 * @in: double pointer to inserted node
 * @dir: double pointer to cursor direction
 * @value: value stored in the node to be inserted
 * Return: pointer to inserted node
 */
heap_t *pushinsert(heap_t *cursor, line **cursorq, heap_t **in, heap_t **dir,
		int value)
{
	if (*dir)
	{
		if (!pushq(cursorq, *dir))
			NOMEM = 1;
	}
	else
	{
		*dir = binary_tree_node(cursor, value);
		if (!*dir)
			NOMEM = 1;
		*in = *dir;
	}
	return (*in);
}

/**
 * levelorder - traverses tree in level order
 * @root: double pointer to root node
 * @value: value stored in the node to be inserted
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *levelorder(heap_t **root, int value)
{
	line *cursorq = NULL;
	heap_t *in, *cursor = *root;

	if (!pushq(&cursorq, cursor))
		return (NULL);
	in = NULL;
	while (cursorq)
	{
		cursor = cursorq->node;
		if (!in)
			pushinsert(cursor, &cursorq, &in, &cursor->left, value);
		if (!in)
			pushinsert(cursor, &cursorq, &in, &cursor->right, value);
		if (NOMEM)
			return (NULL);
		extract(&cursorq);
	}
	return (in);
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the heap
 * @value: value stored in the node to be inserted
 *
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *in;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		in = *root;
	}
	else
	{
		in = levelorder(root, value);
		maxforhead(&in);
	}
	return (in);
}
