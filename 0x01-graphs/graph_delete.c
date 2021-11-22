#include "graphs.h"

/**
 * graph_delete - Frees a graph in memory
 * @graph: pointer to graph
 * Returns: Nothing
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertex, *vertex_temp;
	edge_t *edge, *edge_temp;

	if (!graph)
		return;
	vertex = graph->vertices;
	while (vertex)
	{
		free(vertex->content);
		edge = vertex->edges;
		while (edge)
		{
			edge_temp = edge;
			edge = edge->next;
			free(edge_temp);
		}
		vertex_temp = vertex;
		vertex = vertex->next;
		free(vertex_temp);
	}
	free(graph);
}
