#include "monty.h"
/**
  * add_queue - addsnew node via fifo format
  * @head: first node
  * @i: new_value
  *
  * Return: void
  */
void add_queue(stack_t **head, int i)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node =  malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = i;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
