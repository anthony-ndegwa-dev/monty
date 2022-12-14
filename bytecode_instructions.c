#include "monty.h"

/**
 * _push - pushes element to the stack
 * @doubly: head of the linked list
 * @cline: line number
 *
 * Return: no return
 */

void _push(stack_t **doubly, unsigned int cline)
{
	int i, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(vglo.arg);
	if (vglo.lifo == 1)
		add_dnodeint(doubly, i);
	else
		add_dnodeint_end(doubly, i);
}

/**
 * _pall - prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 * 
 * Return: no return
 */

void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->i);
		aux = aux->next;
	}
}
