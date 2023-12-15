#include "monty.h"
/**
 * f_pall - prints the stack
 * @stack_head: pointer to the stack
 * @opcode_counter: shows the line number in the file
 * Return: no return
*/
void f_pall(stack_t **stack_head, unsigned int opcode_counter)
{
	stack_t *h;

	(void)opcode_counter; /*Void parameter*/

	h = *head;

	if (h == NULL)

		return;

	while (h)
	{
		printf("%d\n", h->n);

		h = h->next;
	}
}

#include "monty.h"
/**
 * f_push - add node to the stack
 * @stack_head: pointer to the stack
 * @opcode_counter: shows the line number in the file
 * Return: no return
*/
void f_push(stack_t **stack_head, unsigned int opcode_counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", opcode_counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", opcode_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
