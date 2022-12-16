#include "monty.h"

/**
 * _isdigit - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 */

int _isdigit(char *c)
{
	char *tem = c;

	if (c == NULL)
		return (0);
	if (*tem == '-')
		tem++;

	for (; *tem != '\0'; tem++)
	{
		if ((*tem < '0' || *tem > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * cleanStack - Frees mallocs and close the files
 * @stack: Stack
 */

void cleanStack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
	fclose(global.fd);
	free(global.line);
}
