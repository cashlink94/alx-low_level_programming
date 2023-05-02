#include "lists.h"

/**
 * reverses_listint - reverses a linked list on this project
 * @head: pointer to the first node in the list linked
 *
 * Return: pointer to the first node in the new list linked
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}

