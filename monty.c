#include "monty.h"

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    
    int i = 0;
    
    while (instructions[i].opcode)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL, *opcode = NULL, *value = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        value = strtok(NULL, " \t\n");

        if (opcode && opcode[0] != '#')  /* Ignore comments and empty lines */
            execute_instruction(opcode, &stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return 0;
}

