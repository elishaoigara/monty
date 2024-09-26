#include "monty.h"

/**
 * push - Push an element to the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the bytecode file.
 * @value: The value to push to the stack.
 */
void push(stack_t **stack, unsigned int line_number, char *value)
{
    stack_t *new_node;
    int num;

    if (!value || (num = atoi(value)) == 0 && value[0] != '0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

/**
 * pall - Prints all values on the stack from top to bottom.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;  /* Unused parameter */

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

