#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 * @head: pointer to head node
 * Return: pointer to looping node or null if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *stride = head->next;
	listint_t *walk = head;

	if (!head || !head->next)
		return (NULL);
	for (; walk && stride; walk = walk->next)
	{
		if (stride == head || stride == walk)
			return (stride);
		if (stride->next && (stride->next == head || stride->next == walk))
			return (stride->next);
		stride = stride->next ?
					stride->next->next ?
						stride->next->next : stride->next :
					NULL;
	}
	return (NULL);
}
