#include "monty.h"

/**
  * push_to_stack_algo - The algorithm used to push new data to the stack.
  * @str: A pointer to one line of string read from the monty bytecode txt
  * file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * @code: The value to be added to the stack.
  * @line_number: The current line been read from the monty bytecode txt file.
  * Return: void.
  */
void push_to_stack_algo(char *str, int i, int x,
				char *code, unsigned int line_number)
{
	i = i + 4;
	while (str[i] == 32)
		i++;
	while ((str[i] != '\0'))
	{
		if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == 45))
		{
			code[x] = str[i];
			x++;
		}
		else
		{
			if ((str[i] != '\n') && (str[i] != '\t') && (str[i] != '\v'))
			{
				while ((str[i] != 32) && (str[i] != '\n') &&
								(str[i] != '\t') && (str[i] != '\v'))
				{
					code[x] = str[i];
					x++;
					i++;
				}
				code[x] = '\0';
				if (str[4] != 32)
					fprintf(stderr, "L%d: unknown instruction push%s\n", line_number, code);
				else
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		i++;
		if ((str[i] == 32))
			break;
	}
	code[x] = '\0';
	if (code[0] == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * pint_stack_algo - Used to print the top of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line number been read from the monty bytecode txt
  * file.
  * Return: void.
  */
void pint_stack_algo(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", head->n);
	}
}
