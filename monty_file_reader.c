#include "monty.h"

/**
  * file_reader - Used to read a file and perform operations based on
  * data found in a monty file.
  * @filename: name or path to file.
  * Return: void.
  */
void file_reader(char **argv)
{
	FILE *ptr;
	char *filename, string[255];
	int i = 1;
	stack_t *stack;

	stack = NULL;
	filename = *(argv + 1);
	ptr = fopen(filename, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(string, 255, ptr) != NULL)
	{
		string_reader(string, i, &stack);
		i++;
	}
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
		if ((str[i] == 'p') && (str[(i + 1)] == 'u') && (str[(i + 2)] == 's') && (str[(i + 3)] == 'h')) 
		{
			i = i + 4;
			while (str[i] == 32)
				i++;
			while ((str[i] != '\0'))
			{
				if ((str[i] >= '0') && (str[i] <= '9'))
				{
					code[x] = str[i];
					x++;
				}
				else
				{
					if ((str[i] != '\n') && (str[i] != '\t') && (str[i] != '\v'))
					{
						while ((str[i] != 32) && (str[i] != '\n') && (str[i] != '\t') && (str[i] != '\v'))
						{
							code[x] = str[i];
							x++;
							i++;
						}
						code[x] = '\0';
						printf("code: %s\n", code);
						printf("L%d: usage: push integer\n", line_number);
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
			x = 0;
		}
		else if ((str[i] == 'p') && (str[i + 1] == 'a') && (str[i + 2] == 'l') && (str[i + 3] == 'l'))
		{
			i = i + 3;
			opcode_function_caller("pall", &(*stack), atoi(code));
		}
		i++;
	}
}

/**
  * opcode_function_caller - This function is used to call another specific
  * function.
  * @opcode: The opcode.
  * @stack: doubly linked list head pointer.
  * @code: The code to be added to the stack.
  * Return: void.
  */
void opcode_function_caller(char *opcode, stack_t **stack, unsigned int code)
{
	unsigned int i;
	instruction_t opcodes[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (opcodes[i].opcode == opcode)
			(*opcodes[i].f)(&(*stack), code);
		i++;
	}
}
