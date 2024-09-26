#include "monty.h"

/**
 * free_stack - Frees the entire stack.
 * @stack: Pointer to the stack to free.
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

