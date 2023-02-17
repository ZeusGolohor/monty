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

	filename = *(argv + 1);
	ptr = fopen(filename, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(string, 255, ptr) != NULL)
	{
		string_reader(string, i);
		i++;
	}
	fclose(ptr);
}

/**
  * string_reader - Used to read instructions from a monty file.
  * @str: monty command.
  * @line_number: monty file line number.
  * Return: void.
  */
void string_reader(char *str, unsigned int line_number)
{
	int i = 0, x = 0;
	char opcode[255];

	/**printf("<Line %d>: %s", line_number, string);*/
	while(*(str + i))
	{
		if ((str[i] == 'p') && (str[(i + 1)] == 'u') && (str[(i + 2)] == 's') && (str[(i + 3)] == 'h'))
		{
			i = i + 4;
			while (str[i] != '\0')
			{
				if ((str[i] >= '0' && str[i] <= '9') || (str[i] == ' '))
				{
					if (str[i] != ' ')
					{
						opcode[x] = str[i];
						x++;
					}
				}
				else
				{
					if ((str[i] != '\n') && (str[i] != '\t') && (str[i] != '\v'))
					{
						fprintf(stderr, "\nL%d: usage: push integer\n", line_number);
						exit(EXIT_FAILURE);
					}
					else
					{

					}
				}
				i++;
			}
			opcode[x] = '\0';
			if (opcode[0] == '\0')
			{
				fprintf(stderr, "\nL%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);				
			}
			printf("%s\n", opcode);
		}
		else if ((str[(i)] == 'p') && (str[(i + 1)] == 'a') && (str[(i + 2)] == 'l') && (str[(i + 3)] == 'l'))
		{
			printf("pall\n");
		}
		i++;
	}
}
