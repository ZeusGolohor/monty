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
  * @str: The current string been read from the monty bytecode txt.
  * @code: The current opcode been read from the monty bytecode txt.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void pint_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, unsigned int i, unsigned int x)
{
	i = i + 4;
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32) && (str[i] != '\n'))
		{
			code[x] = str[i];
			x++;
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction pint%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	else if (*(stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout, "%d\n", (*stack)->n);
	}
}

/**
  * pop_stack_algo - Used to remove the top element of te stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line number been read from the monty bytecode txt
  * file.
  * @str: The current string been read from the monty bytecode txt.
  * @code: The current opcode been read from the monty bytecode txt.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */ 
void pop_stack_algo(stack_t **stack, unsigned int line_number, char *str, char *code, int i, int x)
{
	i = i + 3;
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			code[x] = str[i];
			x++;
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction pop%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	/**opcode_function_caller("pop", &(*stack), line_number);*/
	remove_top_of_stack(&(*stack), line_number);
}
