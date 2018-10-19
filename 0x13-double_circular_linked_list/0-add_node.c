#include "list.h"

/**
 * add_node_end - adds a node to the end of a doubly circular linked-list
 * @list: pointer to list head pointer
 * @str: data to insert in node
 * Return: new node pointer
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = str ? strdup(str) : NULL;
	new_node->next = *list ? *list : new_node;
	new_node->prev = *list ? (*list)->prev : new_node;

	if (*list)
	{
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	} else
		*list = new_node;
	return (new_node);
}

/**
 * add_node_begin - adds a node to the beginning of the list
 * @list: pointer to head node pointer
 * @str: data to insert in node
 * Return: pointer to new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = str ? strdup(str) : NULL;
	new_node->next = *list ? *list : new_node;
	new_node->prev = *list ? (*list)->prev : new_node;

	if (*list)
	{
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}
	*list = new_node;
	return (new_node);
}
