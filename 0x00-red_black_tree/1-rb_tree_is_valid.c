#include "rb_trees.h"

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

int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}
