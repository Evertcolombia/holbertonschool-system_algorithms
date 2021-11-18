#include "graphs.h"
#include <stdlib.h>
#include <string.h>

static int init_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *new, **p;

	if (!dest || !src)
		return (0);
	p = &src->edges;
	while (*p)
	{
		if ((*p)->dest == dest)
			return (0);
		 p = &(*p)->next;
	}
	new = malloc(sizeof(edge_t));
	if (!new)
		return (0);
	new->dest = dest;
	new->next = NULL;
	*p = new;
	src->nb_edges += 1;
	return (1);
}

static vertex_t *get_vertex(graph_t *graph, const char *content)
{
	vertex_t *p;

	p = graph->vertices;
	while (p)
	{
		if (!strcmp(p->content, content))
			return (p);
		p = p->next;
	}
	return (p);
}

int graph_add_edge(
	graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *src_vertex, *dest_vertex;

	if (!graph || !src || !dest || type > BIDIRECTIONAL)
		return (0);
	src_vertex = get_vertex(graph, src);
	if (!src_vertex)
		return (0);
	dest_vertex = get_vertex(graph, dest);
	if (!dest_vertex)
		return (0);
	if (type == UNIDIRECTIONAL)
		return (init_edge(src_vertex, dest_vertex));
	init_edge(src_vertex, dest_vertex);
	init_edge(dest_vertex, src_vertex);
	return (1);
}
