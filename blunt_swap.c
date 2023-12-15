#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @stack_head: stack head
 * @opcode_counter: line_number
 * Return: no return
*/
void f_swap(stack_t **stack_head, unsigned int opcode_counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	h = *stack_head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
