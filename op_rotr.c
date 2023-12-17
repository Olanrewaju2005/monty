#include "monty.h"
/**
  * op_rotr - implements the rotr opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_rotr(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	(void)line_no;
	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (temp->next)
		temp = temp->next;

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
