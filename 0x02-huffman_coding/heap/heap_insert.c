#include "heap.h"

binary_tree_node_t *swap_nodes(binary_tree_node_t *a, binary_tree_node_t *b)
{
	void *tmp;

	tmp = b->data;
	b->data = a->data;
	a->data = tmp;
	a = b;

	return (a);
}

binary_tree_node_t *n_node(binary_tree_node_t *node, int n)
{
	int bit_idx, mask;

	if (!node || n < 0)
		return (NULL);

	for (bit_idx = 0; 1 << (bit_idx + 1) <=  n; ++bit_idx)
		;
	for (--bit_idx; bit_idx >= 0; --bit_idx)
	{
		mask = 1 << bit_idx;
		if (n & mask)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node;

	if (!heap || !data)
		return (NULL);
	if (!heap->root)
	{
		heap->root = node = binary_tree_node(NULL, data);
		if (!node)
			return (NULL);
		++heap->size;
	}
	else
	{
		node = n_node(heap->root, ++heap->size);
		if (!node->left)
			node = node->left = binary_tree_node(node, data);
		else
			node = node->right = binary_tree_node(node, data);
	}
	return (node);
}
