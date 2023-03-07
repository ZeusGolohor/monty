#include "monty.h"

/**
  * file_reader - Used to read a file and perform operations based on
  * data found in a monty file.
  * @argv: name or path to file.
  * Return: void.
  */
void file_reader(char **argv)
{
	FILE *ptr;
	char *filename, *string;
	int i = 1;
	stack_t *stack;

	stack = NULL;
	string = calloc(255, sizeof(char));
	filename = *(argv + 1);
	ptr = fopen(filename, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	if (string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(string, 255, ptr) != NULL)
	{
		string_reader(string, i, &stack);
		i++;
	}
	free(string);
	if (stack != NULL)
		free_stack(&stack);
	fclose(ptr);
}


/**
  * string_reader - Used to read instructions from a monty file.
  * @str: monty command.
  * @line_number: monty file line number.
  * @stack: head pointer to stack.
  * Return: void.
  */
void string_reader(char *str, unsigned int line_number, stack_t **stack)
{
	int i = 0, x = 0;
	/** Used to store a single line from the monty bytecode file */
	char *code;

	code = calloc(255, sizeof(char));
	if (code == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/** Loop throught a single line from the monty bytecode file */
	while (str[i])
	{
		/** opcode push check */
		if ((str[i] == 'p') && (str[(i + 1)] == 'u') &&
						(str[(i + 2)] == 's') && (str[(i + 3)] == 'h'))
		{
			i = i + 4;
			push_stack_algo(str, i, x, code, line_number, &(*stack));
			x = 0;
		}
		/** opcode pall check */
		else if ((str[i] == 'p') && (str[i + 1] == 'a') &&
						(str[i + 2] == 'l') && (str[i + 3] == 'l'))
		{
			str[i] = '\0';
			i = i + 4;
			pall_stack_algo(&(*stack), line_number, str, code, i, x);
			break;
		}
		/** opcode pint check */
		else if ((str[i] == 'p') && (str[i + 1] == 'i') &&
						(str[i + 2] == 'n') && (str[i + 3] == 't'))
		{
			i = i + 4;
			pint_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode pop check */
		else if ((str[i] == 'p') && (str[i + 1] == 'o') && (str[i + 2] == 'p'))
		{
			i = i + 3;
			pop_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode swap check */
		else if ((str[i] == 's') && (str[i + 1] == 'w') &&
						(str[i + 2] == 'a') && (str[i + 3] == 'p'))
		{
			i = i + 4;
			swap_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode add check */
		else if ((str[i] == 'a') && (str[i + 1] == 'd') && (str[i + 2] == 'd'))
		{
			i = i + 3;
			add_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode nop check */
		else if ((str[i] == 'n') && (str[i + 1] == 'o') && (str[i + 2] == 'p'))
		{
			i = i + 3;
			nop_stack_algo(line_number, str, code, i, x);
		}
		/** opcode sub check */
		else if ((str[i] == 's') && (str[i + 1] == 'u') && (str[i + 2] == 'b'))
		{
			i = i + 3;
			sub_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode div check */
		else if ((str[i] == 'd') && (str[i + 1] == 'i') && (str[i + 2] == 'v'))
		{
			i = i + 3;
			div_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode mul check */
		else if ((str[i] == 'm') && (str[i + 1] == 'u') && (str[i + 2] == 'l'))
		{
			i = i + 3;
			mul_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode mod check */
		else if ((str[i] == 'm') && (str[i + 1] == 'o') && (str[i + 2] == 'd'))
		{
			i = i + 3;
			mod_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode #(comment) check */
		else if ((str[i] == '#'))
		{
			if (str[0] != 32)
				break;
		}
		/** opcode pchar check */
		else if ((str[i] == 'p') && (str[i + 1] == 'c') && (str[i + 2] == 'h')
						&& (str[i + 3] == 'a') && (str[i + 4] == 'r'))
		{
			i = i + 5;
			pchar_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode pstr check */
		else if ((str[i] == 'p') && (str[i + 1] == 's') &&
						(str[i + 2] == 't') && (str[i + 3] == 'r'))
		{
			i = i + 4;
			pstr_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode rotl check */
		else if ((str[i] == 'r') && (str[i + 1] == 'o') &&
						(str[i + 2] == 't') && (str[i + 3] == 'l'))
		{
			i = i + 4;
			rotl_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode rotr check */
		else if ((str[i] == 'r') && (str[i + 1] == 'o') &&
						(str[i + 2] == 't') && (str[i + 3] == 'r'))
		{
			i = i + 4;
			rotr_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		/** opcode stack check */
		else if ((str[i] == 's') && (str[i + 1] == 't') && (str[i + 2] == 'a')
						&& (str[i + 3] == 'c') && (str[i + 4] == 'k'))
		{
			i = i + 5;
			stack_algo(line_number, str, code, i, x);
		}
		/** opcode queue check */
		else if ((str[i] == 'q') && (str[i + 1] == 'u') && (str[i + 2] == 'e')
						&& (str[i + 3] == 'u') && (str[i + 4] == 'e'))
		{
			i = i + 5;
			queue_algo(line_number, str, code, i, x);
		}
		i++;
	}
	free(code);
}

/**
  * opcode_function_caller - This function is used to call another specific
  * function.
  * @opcode: The opcode.
  * @stack: doubly linked list head pointer.
  * @info: The code to be added to the stack or the current line been read from
  * the monty bytecode txt file.
  * Return: void.
  */
void opcode_function_caller(char *opcode, stack_t **stack, unsigned int info)
{
	unsigned int i;
	instruction_t opcodes[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{NULL, NULL}
	};

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			(*opcodes[i].f)(&(*stack), info);
		i++;
	}
}

/**
  * free_stack - Used to free up allocated memory.
  * @stack: head to doubly linked list.
  * Return: void.
  */
void free_stack(stack_t **stack)
{
	stack_t *head = *stack, *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
