#include "monty.h"
/**
 * f_div - divides the top two elements of the stack.
 * @stack_head: indicates a stack head
 * @opcode_counter: points a line number
 * Return: no return
*/
void f_div(stack_t **stack_head, unsigned int opcode_counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack_head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	h = *stack_head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*stack_head = h->next;
	free(h);
}

