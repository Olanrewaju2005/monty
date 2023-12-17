#include "monty.h"
/**
  * op_rotl - implements the rotl opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_rotl(stack_t **head, unsigned int line_no)
{
	stack_t *temp, *aux;

	(void)line_no;
	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	aux = (*head)->next;
	aux->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) =aux;
}
