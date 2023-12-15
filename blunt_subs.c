#include "monty.h"
/**
  *f_sub- sustration
  *@stuck_head: Begins the stack head
  *@opcode_counter:Points the line number
  *Return: no return
 */
void f_sub(stack_t **stack_head, unsigned int opcode_counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *stack_head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = *stack_head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*stack_head = aux->next;
	free(aux);
}
