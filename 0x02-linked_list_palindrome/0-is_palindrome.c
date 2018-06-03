#include "lists.h"

/**
 * reverse_listint - reverses a listint list
 * @head: head of linked list
 * Return: pointer to the head of the list
*/
listint_t *reverse_listint(listint_t *head)
{
	listint_t *ptr = head, *tmp = NULL;

	if (head)
	{
		while (ptr->next)
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			tmp->next = head;
			head = tmp;
		}
	}
	return (tmp ? tmp : ptr);
}

/**
 * is_palindrome - determines if a linked list is a palindrome
 * @head: pointer to linked-list head
 * Return: boolean value
 */
int is_palindrome(listint_t **head)
{
	listint_t *stride = *head, *tmp;
	unsigned int len = 0, i = 0;

	if (!*head)
		return (1);
	for (; stride ; len += 1)
		stride = stride->next;

	for (stride = *head; i < (len / 2); i++)
		stride = stride->next;

	if (len % 2 != 0)
		stride = stride->next;
	stride = reverse_listint(stride);
	for (i = 0, tmp = *head ; i < (len / 2); i++)
	{
		if (tmp->n != stride->n)
			return (0);
		stride = stride->next;
		tmp = tmp->next;
	}
	return (1);
}
