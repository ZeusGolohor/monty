#include "monty.h"

/**
  * add_to_stack - Used to add to the stack.
  * @stack: head to doubly linked list.
  * @code: value to be added to the stack.
  * Return: void.
  */
void add_to_stack(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int code)
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
void print_stack(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int code)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		while (head)
		{
			printf("%d\n", head->n);
			head = head->next;
		}
	}
}
