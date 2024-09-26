#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * execute_instruction - Executes the opcode.
 * @opcode: The opcode to execute.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number.
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    int i = 0;
    while (instructions[i].opcode != NULL)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
    FILE *file;
    char line[1024];
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \t\n");

        if (opcode != NULL && opcode[0] != '#') /* Ignore empty lines and comments */
            execute_instruction(opcode, &stack, line_number);
    }

    fclose(file);
    return (EXIT_SUCCESS);
}

