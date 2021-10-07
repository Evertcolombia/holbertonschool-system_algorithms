#include "rb_trees.h"
#include <limits.h>

rb_tree_t *left_rotation(rb_tree_t **root, rb_tree_t *tree)
{
	rb_tree_t *right = NULL;

	right = tree->right;
	tree->right = right->left;
	if (tree->right)
		tree->right->parent = tree;
	right->parent = tree->parent;
	if (!tree->parent)
		*root = right;
	else if (tree == tree->parent->left)
		tree->parent->left = right;
	else
		tree->parent->right = right;
	right->left = tree;
	tree->parent = right;
	return (tree);
}

rb_tree_t *right_rotation(rb_tree_t **root, rb_tree_t *tree)
{
	rb_tree_t *left = NULL;

	left = tree->left;
	tree->left = left->right;
	if (tree->left)
		tree->left->parent = tree;
	left->parent = tree->parent;
	if (!tree->parent)
		*root = left;
	else if (tree == tree->parent->left)
		tree->parent->left = left;
	else
		tree->parent->right = left;
	left->right = tree;
	tree->parent = left;
	return (tree);
}

rb_tree_t *bst_insert(rb_tree_t **root, int value)
{
	rb_tree_t *node, *prev = NULL, *curr;

	if (!root)
		return (NULL);
	curr = *root;
	while (curr)
	{
		prev = curr;
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else
			return (NULL);
	}
	node = rb_tree_node(prev, value, RED);
	if (!node)
		return (NULL);
	if (!prev)
	{
		node->color = BLACK;
		*root = node;
		return (node);
	}
	if (value < prev->n)
		prev->left = node;
	else
		prev->right = node;
	return (node);
}

rb_tree_t *fix_left(rb_tree_t **root, rb_tree_t *new)
{
	rb_tree_t *uncle = GRANDPARENT(new)->left;

	if (uncle && uncle->color == RED)
	{
		uncle->color = BLACK;
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		new = GRANDPARENT(new);
	}
	else
	{
		if (new == PARENT(new)->left)
		{
			new = PARENT(new);
			right_rotation(root, new);
		}
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		left_rotation(root, GRANDPARENT(new));
	}
	return (new);
}

rb_tree_t *fix_right(rb_tree_t **root, rb_tree_t *new)
{
	rb_tree_t *uncle = GRANDPARENT(new)->right;

	if (uncle && uncle->color == RED)
	{
		uncle->color = BLACK;
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		new = GRANDPARENT(new);
	}
	else
	{
		if (new == PARENT(new)->right)
		{
			new = PARENT(new);
			left_rotation(root, new);
		}
		PARENT(new)->color = BLACK;
		GRANDPARENT(new)->color = RED;
		right_rotation(root, GRANDPARENT(new));
	}
	return (new);
}

void conserve_properties(rb_tree_t **root, rb_tree_t *new)
{
	rb_tree_t *grand_parent = NULL;

	while (new != *root && PARENT(new) && PARENT(new)->color == RED)
	{
		grand_parent = GRANDPARENT(new);
		if (PARENT(new) == grand_parent->left)
		{
			new = fix_right(root, new);
		}
		else
		{
			new = fix_left(root, new);
		}
	}
	(*root)->color = BLACK;
}

rb_tree_t *rb_tree_insert(rb_tree_t **root, int value)
{
	rb_tree_t *new_node = NULL;

	if (!root)
		return (NULL);
	new_node = bst_insert(root, value);
	if (!new_node)
		return (NULL);
	conserve_properties(root, new_node);
	return (new_node);
}
