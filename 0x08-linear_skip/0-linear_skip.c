#include "search.h"

/**
 * list_len - gets the length of a list
 * @list: pointer to the list
 * Return: number of elements in the list
 */
size_t list_len(const skiplist_t *list)
{
	size_t i = 0;

	for (; list; list = list->next)
		++i;
	return (i);
}

/**
 * linear_skip - searches for an element in a skip list
 * @list: pointer to skip list
 * @value: value to search
 * Return: pointer to node containing the value or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *walkman = NULL;

	if (!list)
		return (NULL);
	for (walkman = list; walkman->express && walkman->express->n < value;
		walkman = walkman->express)
	{
		printf("Value checked at [%lu] = [%d]\n",
				walkman->express->index, walkman->express->n);
	}
	if (walkman == list)
		printf("Value checked at [%lu] = [%d]\n", walkman->express->index,
				walkman->express->n);
	else if (walkman->express && walkman->express->n > value)
		printf("Value checked at [%lu] = [%d]\n", walkman->express->index,
				walkman->express->n);

	if (walkman->express)
		printf("Value found between indexes [%lu] and [%lu]\n", walkman->index,
				walkman->express->index);
	else
		printf("Value found between indexes [%lu] and [%lu]\n", walkman->index,
				list_len(list) - 1);

	while (walkman && walkman->n != value)
	{
		printf("Value checked at [%lu] = [%d]\n", walkman->index, walkman->n);
		walkman = walkman->next;
	}
	if (walkman)
		printf("Value checked at [%lu] = [%d]\n", walkman->index, walkman->n);

	return (walkman);
}

