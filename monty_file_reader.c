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
	if ((ptr == NULL) || (string == NULL))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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
	char code[255];

	while (str[i])
	{
		if ((str[i] == 'p') && (str[(i + 1)] == 'u') &&
						(str[(i + 2)] == 's') && (str[(i + 3)] == 'h'))
		{
			i = i + 4;
			push_to_stack_algo(str, i, x, code, line_number, &(*stack));
			x = 0;
		}
		else if ((str[i] == 'p') && (str[i + 1] == 'a') &&
						(str[i + 2] == 'l') && (str[i + 3] == 'l'))
		{
			str[i] = '\0';
			i = i + 4;
			pall_stack_algo(&(*stack), i);
			break;
		}
		else if ((str[i] == 'p') && (str[i + 1] == 'i') &&
						(str[i + 2] == 'n') && (str[i + 3] == 't'))
		{
			i = i + 4;
			pint_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		else if ((str[i] == 'p') && (str[i + 1] == 'o') && (str[i + 2] == 'p'))
		{
			i = i + 3;
			pop_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		else if ((str[i] == 's') && (str[i + 1] == 'w') &&
						(str[i + 2] == 'a') && (str[i + 3] == 'p'))
		{
			i = i + 4;
			swap_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		else if ((str[i] == 'a') && (str[i + 1] == 'd') && (str[i + 2] == 'd'))
		{
			i = i + 3;
			add_stack_algo(&(*stack), line_number, str, code, i, x);
		}
		else if ((str[i] == 'n') && (str[i + 1] == 'o') && (str[i + 2] == 'p'))
		{
			i = i + 3;
			nop_stack_algo(line_number, str, code, i, x);
		}
		i++;
	}
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
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pop", remove_top_of_stack},
		{"swap", swap_stack},
		{"add", add_stack},
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
