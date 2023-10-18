# Monty Bytecode Interpreter

## Documentation

Monty is a programming language that uses a stack data structure. This repository contains an implementation of the Monty language in C.

## Getting Started

To get started with Monty, you can clone this repository:

`$ git clone https://github.com/ZeusGolohor/monty.git`

## Usage

To run a Monty program, you can pass the name of the Monty program file as a command-line argument to the `monty` executable:

`$ ./monty bytecodes/myprogram.m`

This will execute the Monty program in the `myprogram.m` file.

## Monty Language

The Monty language is a simple programming language that uses a stack data structure. Monty programs consist of a series of commands, each of which performs a specific operation on the stack. The Monty language supports the following commands:

- `push`: pushes a value onto the stack
- `pall`: prints all values on the stack
- `pint`: prints the value at the top of the stack
- `pop`: removes the top value from the stack
- `swap`: swaps the top two values on the stack
- `add`: adds the top two values on the stack
- `nop`: does nothing
- `sub`: subtracts the top element of the stack from the second top element of the stack.
- `div`: divides the second top element of the stack by the top element of the stack.
- `mul`: multiplies the second top element of the stack with the top element of the stack.
- `mod`: computes the rest of the division of the second top element of the stack by the top element of the stack.
- `#`: every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).
- `pchar`: prints the char at the top of the stack, followed by a new line.
- `pchar`: prints the char at the top of the stack, followed by a new line.
- `rotl`: rotates the stack to the top.
- `rotr`: rotates the stack to the bottom.
- `stack`: sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- `queue`: sets the format of the data to a queue (FIFO).

## Author
Golohor Ufuoma Emmanuel Zeus
