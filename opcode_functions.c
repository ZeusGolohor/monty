#include "monty.h"

/**
  * push_stack - Used to add to the stack.
  * @stack: head to doubly linked list.
  * @code: value to be added to the stack.
  * Return: void.
  */
void push_stack(stack_t **stack,
				__attribute__((unused)) unsigned int code)
{
	stack_t *newnode;
	stack_t *temp;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (FORMAT == 0)
	{
		if (*stack == NULL)
		{
			newnode->n = code;
			newnode->prev = NULL;
			newnode->next = NULL;
			*stack = newnode;
		}
		else if ((*stack != NULL) && ((*stack)->prev == NULL))
		{
			newnode->n = code;
			newnode->prev = NULL;
			newnode->next = *stack;
			(*stack)->prev = newnode;
			*stack = newnode;
		}
	}
	else if (FORMAT == 1)
	{
		if (*stack != NULL)
		{
			temp = *stack;
			while (temp)
			{
				if (temp->next == NULL)
				{
					newnode->n = code;
					newnode->next = NULL;
					newnode->prev = temp;
					temp->next = newnode;
					break;
				}
				temp = temp->next;
			}
		}
		else if (*stack == NULL)
		{
			newnode->n = code;
			newnode->prev = NULL;
			newnode->next = NULL;
			*stack = newnode;
		}
	}
}

/**
  * pall_stack - Used to [rint the stack.
  * @stack: head to doubly linked list.
  * @code: value to be added to the stack.
  * Return: void.
  */
void pall_stack(stack_t **stack,
				__attribute__((unused)) unsigned int code)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		while (head)
		{
			fprintf(stdout, "%d\n", head->n);
			head = head->next;
		}
	}
}

/**
  * pop_stack - Used to remove the top element in a stack.
  * @stack: Pointer to the head of the stack.
  * @line_number: The current line been read from the monty bytecode txt file.
  * Return: void.
  */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		head = *stack;
		temp = (*stack)->next;
		temp->prev = NULL;
		free(head);
		*stack = temp;
	}
	else if (((*stack)->next == NULL) && ((*stack)->prev == NULL))
	{
		temp = *stack;
		free(temp);
		*stack = NULL;
	}
}

/**
  * swap_stack - Used to swap the two elements of a stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode txt file.
  * Return: void.
  */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	(*stack)->n = second;
	(*stack)->next->n = first;
}

/**
  * add_stack - Used to add the top two elements of a stack, store the
  * result in the second, the pop the top of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void add_stack(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	(*stack)->next->n = (first + second);
	opcode_function_caller("pop", &(*stack), line_number);
}

/**
  * sub_stack - Used to subtract the top two element of the stack, store the
  * result in the second element, then pop the first.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void sub_stack(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	(*stack)->next->n = (second - first);
	opcode_function_caller("pop", &(*stack), line_number);
}

/**
  * div_stack - Used to divide the second top element of the stack by
  * the top element of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	if (first == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (second / first);
	opcode_function_caller("pop", &(*stack), line_number);
}

/**
  * mul_stack - Used to multiple the second top element of the
  * stack with the top element of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	(*stack)->next->n = (second * first);
	opcode_function_caller("pop", &(*stack), line_number);
}

/**
  * mod_stack - Used to compute the rest of the division of the second
  * top element of the stack by the top element of the stack.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	if (first == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (second % first);
	opcode_function_caller("pop", &(*stack), line_number);
}

/**
  * pchar_stack - This is used to print the char at the top of
  * the stack, followed by a new line.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void pchar_stack(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n >= 0) && ((*stack)->n <= 127))
	{
		fprintf(stdout, "%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * pstr_stack - This used to print string starting at the top
  * of the stack, followed by a new line.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void pstr_stack(stack_t **stack,
				__attribute((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stdout, "\n");
	}
	while (temp)
	{
		if ((temp->n == 0) || !((temp->n >= 0) && (temp->n <= 127)))
			break;
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	if (*stack != NULL)
		fprintf(stdout, "\n");
}

/**
  * rotl_stack - This is user to rotate the stack to the top.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int top_n;
	stack_t *newnode;

	if (*stack != NULL)
	{
		top_n = temp->n;
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		while (temp)
		{
			if (temp->next == NULL)
			{
				newnode->n = top_n;
				newnode->prev = temp;
				newnode->next = NULL;
				temp->next = newnode;
				break;
			}
			temp = temp->next;
		}
		opcode_function_caller("pop", &(*stack), line_number);
	}
}

/**
  * rotr_stack - This rotates the stack to the bottom.
  * @stack: Head pointer to the stack.
  * @line_number: The current line been read from the monty bytecode file.
  * Return: void.
  */
void rotr_stack(stack_t **stack, __attribute((unused))
				unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack != NULL)
	{
		while (temp)
		{
			if (temp->next == NULL)
			{
				opcode_function_caller("push", &(*stack), temp->n);
				temp->prev->next = NULL;
				free(temp);
				break;
			}
			temp = temp->next;
		}
	}
}

