#include "lists.h"

/**
 * add_nodeint - add node at the start of a linked list in this project
 * @head: pointer to the first node in the list you are working on 
 * @m: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int m)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->m = m;
	new->next = *head;
	*head = new;

	return (new);
}

