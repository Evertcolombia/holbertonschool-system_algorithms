#include "rb_trees.h"

#include <stdio.h>

/**
 * rb_tree_node - create a node for red black tree
 * @parent: parentf of the new node
 * @value: value for the node
 * @color: color of the node
 *
 * Return: node on success. NULL if fails
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new = NULL;


	new = malloc(sizeof(rb_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->color = color;

	return (new);
}
