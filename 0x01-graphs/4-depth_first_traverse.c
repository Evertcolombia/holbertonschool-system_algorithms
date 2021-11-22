#include "graphs.h"
#define GRAPH const graph_t *graph
#define ACTION void (*action)(const vertex_t *v, size_t depth)

/**
 * depth_get - helper function for depth_first_traverse
 * @v: vertex being dealt with
 * @action: action to take on vertex
 * @seen: array that keeps track of which vertexes have been seen
 * @depth: current depth of traversal
 * Return: maximum depth encountered
 **/
size_t depth_get(const vertex_t *v, action_t action, char *seen, size_t depth)
{
	edge_t *edge;
	size_t tmp, res = 0;

	if (seen[v->index])
		return (depth - 1);
	action(v, depth);
	seen[v->index] = 1;
	edge = v->edges;
	while (edge)
	{
		tmp = depth_get(edge->dest, action, seen, depth + 1);
		if (tmp > res)
			res = tmp;
		edge = edge->next;
	}
	return (res);
}

/**
 * depth_first_traverse - traverses a graph using depth-first algorithm
 * @GRAPH: pointer to graph
 * @ACTION: pointer to function to perform
 * Return: biggest vertex depth (See example), or 0 on failure
 **/
size_t depth_first_traverse(GRAPH, ACTION)
{
	char *seen;
	size_t max_depth = 0;

	if (!graph)
		return (0);

	if (graph->nb_vertices)
	{
		seen = calloc(graph->nb_vertices, sizeof(char));
		max_depth = depth_get(graph->vertices, action, seen, max_depth);
		free(seen);
	}
	return (max_depth);

}
