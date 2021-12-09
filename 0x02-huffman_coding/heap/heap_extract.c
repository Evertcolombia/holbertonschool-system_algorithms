#include "heap.h"

void *extract_root(heap_t *heap)
{
	binary_tree_node_t *node;
	void *data;

	node = n_node(heap->root, heap->size);
	if (node->parent)
	{
		data = swap_nodes(heap->root, node)->data;
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else
	{
		data = heap->root->data;
		heap->root = NULL;
	}
	free(node);
	if (--heap->size == 0)
		heap->root = NULL;
	return (data);
}

void *heap_extract(heap_t *heap)
{
	void *data;

	if (!heap)
		return (NULL);
	data = extract_root(heap);
	return (data);
}
