#include "search.h"

/**
 * list_len - gets the length of a list
 * @list: pointer to the list
 * Return: number of elements in the list
 */
size_t list_len(skiplist_t *list)
{
	skiplist_t *walk = list;
	size_t i = 0;

	for (; walk; walk = walk->next)
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
	for (walkman = list; walkman; walkman = walkman->express)
	{
		if (walkman->express && walkman->express->n > value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				walkman->express->index, walkman->express->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
				walkman->index, walkman->express->index);
			break;
		}
		else if (walkman->express && walkman->express->n == value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				walkman->express->index, walkman->express->n);
			return (walkman->express);
		}
		else if (walkman->n == value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				walkman->index, walkman->n);
			return (walkman);
		}
		else if (!walkman->express)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				walkman->index, list_len(list) - 1);
			break;
		}
		else
			printf("Value checked at index [%lu] = [%d]\n",
				walkman->express->index, walkman->express->n);
	}
	for (; walkman; walkman = walkman->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			walkman->index, walkman->n);
		if (walkman->n == value)
			return (walkman);
		if (walkman->n > value)
			return (NULL);
	}
	return (NULL);
}
