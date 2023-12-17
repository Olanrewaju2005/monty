#include "monty.h"
/**
  * op_push - implements the push opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_push(stack_t **head, unsigned int line_no)
{
	int i, j = 0, flag = 0;

	if (term.arg)
	{
		if (term.arg[0] == '-')
			j++;
		for (; term.arg[j] != '\0'; j++)
		{
			if (term.arg[j] > 57 || term.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			fclose(term.file);
			free(term.content);
			free_vector(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: pish integer\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(term.arg);
	if (term.lifi == 0)
		add_node(head, i);
	else
		add_queue(head, i);
}
