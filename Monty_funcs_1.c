#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Pushes a value to a stack_t linked list.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
    char *token = op_toks[1];
    stack_t *new = malloc(sizeof(stack_t));

    if (!new || !token || (!isdigit(*token) && *token != '-' && *token != '+'))
    {
        set_op_tok_error(!new ? malloc_error() : no_int_error(line_number));
        return;
    }

    new->n = atoi(token);

    if (check_mode(*stack) == STACK)
        stack_push(stack, new);
    else
        stack_enqueue(stack, new);
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
    stack_t *top = (*stack)->next;

    if (!top)
    {
        set_op_tok_error(pint_error(line_number));
        return;
    }

    printf("%d\n", top->n);
}

/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *top = stack_pop(stack);

    if (!top)
        set_op_tok_error(pop_error(line_number));
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
    if (stack_len(*stack) < 2)
    {
        set_op_tok_error(short_stack_error(line_number, "swap"));
        return;
    }

    stack_swap_top_two(stack);
}
