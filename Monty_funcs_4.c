#include "monty.h"

/**
 * rotate - Rotates the linked list according to the specified direction.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * @direction: The rotation direction (1 for left, -1 for right).
 */
void rotate(stack_t **stack, unsigned int line_number, int direction)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    stack_t *top = (*stack)->next;
    stack_t *bottom = top;

    while (bottom->next != NULL)
        bottom = bottom->next;

    if (direction == 1) { // Rotate left
        top->next->prev = *stack;
        (*stack)->next = top->next;
        bottom->next = top;
        top->next = NULL;
        top->prev = bottom;
    } else if (direction == -1) { // Rotate right
        bottom->prev->next = NULL;
        (*stack)->next = bottom;
        bottom->prev = *stack;
        bottom->next = top;
        top->prev = bottom;
    }

    (void)line_number;
}

/**
 * monty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
    rotate(stack, line_number, 1);
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
    rotate(stack, line_number, -1);
}

/**
 * monty_mode - Sets the mode of the linked list (STACK or QUEUE).
 */
void monty_mode(stack_t **stack, unsigned int line_number, int mode)
{
    (*stack)->n = mode;
    (void)line_number;
}

/**
 * monty_stack - Converts a queue to a stack.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
    monty_mode(stack, line_number, STACK);
}

/**
 * monty_queue - Converts a stack to a queue.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
    monty_mode(stack, line_number, QUEUE);
}
