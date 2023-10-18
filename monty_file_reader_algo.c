#include "monty.h"

/**
  * push_stack_algo - The algorithm used to push new data to the stack.
  * @str: A pointer to one line of string read from the monty bytecode txt
  * file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * @code: The value to be added to the stack.
  * @line_number: The current line been read from the monty bytecode txt file.
  * @stack: Head pointer to stack.
  * Return: void.
  */
void push_stack_algo(char *str, int i, int x,
				char *code, unsigned int line_number, stack_t **stack)
{
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
	opcode_function_caller("push", &(*stack), atoi(code));
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
void pop_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, int i, int x)
{
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			if (str[i] != '\n')
				code[x] = str[i];
			x++;
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction pop%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("pop", &(*stack), line_number);
}

/**
  * pall_stack_algo - Used to print the whole stack.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void pall_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, int i, int x)
{
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			if (str[i] != '\n')
			{
				code[x] = str[i];
				x++;
			}
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction pall%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("pall", &(*stack), i);
}

/**
  * swap_stack_algo - Used to swap the top element in a stack.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void swap_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, int i, int x)
{
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			if (str[i] != '\n')
				code[x] = str[i];
			x++;
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction swap%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("swap", &(*stack), line_number);
}

/**
  * div_stack_algo - Used to divide the second top element of
  * the stack by the top element of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void div_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, int i, int x)
{
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			if (str[i] != '\n')
			{
				code[x] = str[i];
				x++;
			}
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction div%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("div", &(*stack), line_number);
}

/**
  * mul_stack_algo - Used to multiple the second top element
  * of the stack with the top element of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void mul_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, int i, int x)
{
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			if (str[i] != '\n')
			{
				code[x] = str[i];
				x++;
			}
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction mul%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("mul", &(*stack), line_number);
}

/**
  * mod_stack_algo - Used to compute the rest of the division of
  * the second top element of the stack by the top element of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void mod_stack_algo(stack_t **stack, unsigned int line_number,
				char *str, char *code, int i, int x)
{
	if ((str[i] != 32) && (str[i] != '\n'))
	{
		while ((str[i] != 32))
		{
			if (str[i] != '\n')
			{
				code[x] = str[i];
				x++;
			}
			i++;
		}
		code[x] = '\0';
		fprintf(stderr, "L%d: unknown instruction mod%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("mod", &(*stack), line_number);
}

