#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks is tree is AVL
 * @tree: pointer to root node
 * Return: 1 if AVL else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}

/**
 * is_avl - recursively checks if tree is AVL
 * @tree: pointer to current root
 * @min: current min val
 * @max: current max val
 * @height: height of this tree by address
 * Return: true if is AVL else 0
 */
int is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!is_avl(tree->left, min, tree->n, &h1) ||
		!is_avl(tree->right, tree->n, max, &h2))
		return (0);
	*height = MAX(h1, h2) + 1;
	return (ABS(h1 - h2) <= 1);
}
