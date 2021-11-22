#include "graphs.h"
#define GRAPH const graph_t *graph
#define ACTION void (*action)(const vertex_t *v, size_t depth)


/**
 * breadth_first_traverse - traverse a graph using breadth-first
 * @GRAPH: pointer to graph
 * Return:  biggest vertex depth, or 0 on failure
 **/
size_t breadth_first_traverse(GRAPH, ACTION)
{
	size_t depth, round_size, next_round_size;
	vertex_t **vertices;
	char *seen;
	edge_t *p;
	int i, j;

	if (!graph || !action || graph->nb_vertices == 0)
		return (0);
	seen = calloc(graph->nb_vertices, sizeof(char));
	vertices = calloc(graph->nb_vertices + 1, sizeof(vertex_t *));
	vertices[0] = graph->vertices;
	seen[0] = 1, depth = 0, j = 1, round_size = 1, next_round_size = 0;
	for (i = 0; vertices[i]; i++)
	{
		action(vertices[i], depth);
		for (p = vertices[i]->edges; p; p = p->next)
		{
			if (seen[p->dest->index] == 0)
			{
				vertices[j++] = p->dest, seen[p->dest->index] = 1;
				next_round_size += 1;
			}
		}
		if (--round_size == 0)
		{
			depth++, round_size = next_round_size;
			next_round_size = 0;
		}
	}
	free(seen), free(vertices);
	return (depth - 1);
}
