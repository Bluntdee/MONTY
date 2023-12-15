#include "monty.h"
/**
 * f_pint - prints the top
 * @stack_head: beginning of stack head
 * @opcode_counter: shows the line number in the file
 * Return: no return
*/
void f_pint(stack_t **stack_head, unsigned int opcode_counter)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
