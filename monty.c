#include "monty.h"
/** Setting stack format to default. */
int FORMAT = 0;
/**
  * main - Program entry point.
  * @argc: Number of arguements passed to the program.
  * @argv: Agruements passed to the program.
  * Return: int.
  */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_reader(argv);
	return (0);
}

