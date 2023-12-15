#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @stack_head: indicates stack head
 * @opcode_counter: points out line_number
 * Return: no return
*/
void f_mul(stack_t **stack_head, unsigned int opcode_counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	h = *stack_head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*stack_head = h->next;
	free(h);
}