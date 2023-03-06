#include "monty.h"

/**
  * add_stack_algo - Used to add the top two element of a stack then
  * store the data in the second then delete the top stack.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void add_stack_algo(stack_t **stack, unsigned int line_number,
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
		fprintf(stderr, "L%d: unknown instruction add%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("add", &(*stack), line_number);
}

/**
  * nop_stack_algo - It does nothing.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void nop_stack_algo(unsigned int line_number,
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
		fprintf(stderr, "L%d: unknown instruction nop%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
}

/**
  * sub_stack_algo - Used to subtract the top two elements of the stack,
  * store the result in the second element and then pop the first element.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void sub_stack_algo(stack_t **stack, unsigned int line_number,
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
		fprintf(stderr, "L%d: unknown instruction sub%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("sub", &(*stack), line_number);
}

/**
  * pchar_stack_algo - Used to print char at the top of the stack,
  * followed by a new line.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void pchar_stack_algo(stack_t **stack, unsigned int line_number,
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
		fprintf(stderr, "L%d: unknown instruction pchar%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("pchar", &(*stack), line_number);
}

/**
  * pstr_stack_algo - Used to print the string starting at the
  * top of the stack, followed by a new line.
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void pstr_stack_algo(stack_t **stack, unsigned int line_number,
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
		fprintf(stderr, "L%d: unknown instruction pstr%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("pstr", &(*stack), line_number);
}

/**
  * rotl_stack_algo - Used to rotate the stack to the top
  * @stack: Head pointer to the stack.
  * @line_number: The curent line been read from the monty bytecode txt file.
  * @str: The current string been read from the monty bytecode txt file.
  * @code: The current code from the monty bytecode txt file.
  * @i: Used for iteration.
  * @x: Used for iteration.
  * Return: void.
  */
void rotl_stack_algo(stack_t **stack, unsigned int line_number,
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
		fprintf(stderr, "L%d: unknown instruction rotl%s\n", line_number, code);
		exit(EXIT_FAILURE);
	}
	opcode_function_caller("rotl", &(*stack), line_number);
}
