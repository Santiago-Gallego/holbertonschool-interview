#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 * @value: is the value to put in the new node
 * @parent: is a pointer to the parent node of the node to create
 * Return:  new node called b, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

binary_tree_t *b;

b = malloc(sizeof(binary_tree_t));
if (b == NULL)
{
return (NULL);
}

b->n = value;
b->parent = parent;
b->left = NULL;
b->right = NULL;

return (b);

}
