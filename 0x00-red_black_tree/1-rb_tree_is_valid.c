#include "rb_trees.h"
#include <stdio.h>

/**
 * check_bst - check if a tree is binary search tree valid
 * @tree: node to check
 * @min: min number to compare
 * @max: max number to compare
 *
 * Return: 1 on success, 0 on error
 */
int check_bst(const rb_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	/* false if this node violates the min/max rule */
	if (tree->n < min || tree->n > max)
		return (0);

	/* Check sub trees recursively */
	return (check_bst(tree->left, min, (tree->n - 1)) &&
		check_bst(tree->right, (tree->n + 1), max));
}

int check_tree_colors(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->color != RED && tree->color != BLACK)
		return (0);

	if (tree->color == RED)
	{
		if (tree->left && tree->right)
		{
			if (tree->left->color != BLACK)
				return (0);

			if (tree->right->color != BLACK)
				return (0);
		}
	}

	if ((check_tree_colors(tree->left) != 1) ||
		(check_tree_colors(tree->right) != 1))
		return (0);

	return (1);
}

int rb_tree_is_valid(const rb_tree_t *tree)
{
	int val = 0;

	if (tree == NULL)
		return (0);
	val = check_bst(tree, INT_MIN, INT_MAX);

	if (tree->color == RED)
		return (0);

	val = check_tree_colors(tree);

	return (val);
}
