#include "graphs.h"
#include <stdlib.h>
#include <string.h>

static vertex_t *init_vertex(const char *str, size_t index)
{
	vertex_t *new_vertex = NULL;

	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);
	new_vertex->content = strdup(str);
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;
	new_vertex->index = index;
	return (new_vertex);
}

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t **created_vertex;

	if (!graph || !str)
		return (NULL);
	created_vertex = &graph->vertices;
	while (*created_vertex != NULL)
	{
		if (strcmp(str, (*created_vertex)->content) == 0)
			return (NULL);
		created_vertex = &(*created_vertex)->next;
	}

	*created_vertex = init_vertex(str, graph->nb_vertices);
	graph->nb_vertices += 1;
	return (*created_vertex);
}
