#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *value = strtok(NULL, " \t\n");
    int num;
    stack_t *new_node;

    if (!value || ((num = atoi(value)) == 0 && value[0] != '0'))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Create a new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;
    
    *stack = new_node;
}

/**
 * pall - Prints all values on the stack, starting from the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

