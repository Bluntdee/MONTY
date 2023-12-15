#include "monty.h"
/**
 * f_pop - prints the top of a stack
 * @stack_head: pointer to stack head
 * @opcode_counter: line_number in stack file
 * Return: no return
*/
void f_pop(stack_t **stack_head, unsigned int opcode_counter)
{
	stack_t *h;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
