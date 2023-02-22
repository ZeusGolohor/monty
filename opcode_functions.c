#include "monty.h"

/**
  * add_to_stack - Used to add to the stack.
  * @stack: head to doubly linked list.
  * @code: value to be added to the stack.
  * Return: void.
  */
void add_to_stack(__attribute__((unused)) stack_t **stack,
				__attribute__((unused)) unsigned int code)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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

/**
  * print_stack - Used to [rint the stack.
  * @stack: head to doubly linked list.
  * @code: value to be added to the stack.
  * Return: void.
  */
void print_stack(__attribute__((unused)) stack_t **stack,
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
  * remove_top_of_stack - Used to remove the top element in a stack.
  * @stack: Pointer to the head of the stack.
  * @line_number: The current line been read from the monty bytecode txt file.
  * Return: void.
  */
void remove_top_of_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		printf("removing top1\n");
		head = *stack;
		temp = (*stack)->next;
		temp->prev = NULL;
		free(head);
		*stack = temp;
	}
	else if (((*stack)->next == NULL) && ((*stack)->prev == NULL))
	{
		printf("removing top2\n");
		temp = *stack;
		free(temp);
		*stack = NULL;
	}
}
