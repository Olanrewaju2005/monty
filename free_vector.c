#include "monty.h"
/**
  * free_vector - frees a doublt lonked list
  * @head: first node of list
  *
  * Return: void
  */
void free_vector(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
