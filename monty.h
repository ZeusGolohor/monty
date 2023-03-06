#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **, unsigned int);
} instruction_t;
void file_reader(char **);
void string_reader(char *, unsigned int, stack_t **);
void opcode_function_caller(char *, stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void free_stack(stack_t **);
void push_to_stack_algo(char *, int, int, char *, unsigned int, stack_t **);
void pint_stack_algo(stack_t **, unsigned int, char *, char *,
unsigned int, unsigned int);
void pop_stack(stack_t **, unsigned int);
void pop_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void pall_stack_algo(stack_t **, int);
void swap_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void swap_stack(stack_t **, unsigned int);
void add_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void add_stack(stack_t **, unsigned int);
void nop_stack_algo(unsigned int, char *, char *, int, int);
void sub_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void sub_stack(stack_t **, unsigned int);
void div_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void div_stack(stack_t **, unsigned int);
void mul_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void mul_stack(stack_t **, unsigned int);
void mod_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void mod_stack(stack_t **, unsigned int);
void pchar_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void pchar_stack(stack_t **, unsigned int);
void pstr_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void pstr_stack(stack_t **, unsigned int);
void rotl_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void rotl_stack(stack_t **, unsigned int);
void rotr_stack_algo(stack_t **, unsigned int, char *, char *, int, int);
void rotr_stack(stack_t **, unsigned int);
#endif
