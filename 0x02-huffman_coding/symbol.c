#include "huffman.h"

/**
 * symbol_create - create new symbol_t object
 * @data: data to store
 * @freq: associated frequency
 *
 * Return: pointer to created structure, NULL on failure
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol = malloc(sizeof(*symbol));

	if (!symbol)
		return (NULL);
	symbol->data = data;
	symbol->freq = freq;
	return (symbol);
}
