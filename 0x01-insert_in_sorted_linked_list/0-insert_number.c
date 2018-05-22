#include "lists.h"

/**
 * insert_node - inserts a node into a linked list in sorted order
 * @head: linked list head
 * @number: new node data
 * Return: pointer to new node or NULLon failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *walk = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head && (*head)->n >= number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	else
	{
		while (walk->next && walk->next->n < number)
			walk = walk->next;
		new->next = walk->next;
		walk->next = new;
		return (new);
	}
}
