#include "lists.h"

/**
 * is_palindrome - determines if a linked list is a palindrome
 * @head: pointer to linked-list head
 * Return: boolean value
 */
int is_palindrome(listint_t **head)
{
	listint_t **arr, *stride = *head;
	unsigned int len = 0, i = 0;

	if (!*head)
		return (1);
	for (; stride ; len += 1)
		stride = stride->next;

	arr = malloc(sizeof(listint_t *) * (len / 2));
	if (!arr)
		return (0);
	for (stride = *head; i < (len / 2); i++)
	{
		arr[((len / 2) - 1) - i] = stride;
		stride = stride->next;
	}
	if (len % 2 != 0)
		stride = stride->next;
	for (i = 0 ; i < (len / 2); i++)
	{
		if (arr[i]->n != stride->n)
		{
			free(arr);
			return (0);
		}
		stride = stride->next;
	}
	free(arr);
	return (1);
}
