#include "lists.h"

/**
 * check_cycle - checks if a linked list contains a cycle
 * @list: linked list
 * Return: 0 if no cycle, 1 if cycle
*/
int check_cycle(listint_t *list)
{
	listint_t *turtle = list, *hare = NULL;

	if (!list)
		return (0);
	hare = turtle->next;
	while (hare)
	{
		if (hare == turtle || hare->next == turtle)
			return (1);
		if (hare->next)
			hare = hare->next->next;
		else
			hare = hare->next;
		turtle = turtle->next;
	}
	return (0);
}
