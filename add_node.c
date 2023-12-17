#include "monty.h"
/**
  * add_node - adds new node to top of list (or queue)
  * @head: last elemnt of list (or queue)
  * @n: int
  *
  * Return: void
  */
void add_node(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
