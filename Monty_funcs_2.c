Copy code
#include "monty.h"

typedef void (*operation_func_t)(stack_t **stack, unsigned int line_number);

void perform_operation(stack_t **stack, unsigned int line_number, operation_func_t operation);
void binary_operation(stack_t **stack, unsigned int line_number, char *op);

/**
 * perform_operation - Executes the specified operation on the stack.
 */
void perform_operation(stack_t **stack, unsigned int line_number, operation_func_t operation)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, op_to_string(operation)));
        return;
    }

    operation(stack, line_number);
}

/**
 * binary_operation - Generic function for binary operations (add, sub, div, mul, mod).
 */
void binary_operation(stack_t **stack, unsigned int line_number, char *op)
{
    int a = (*stack)->next->n;
    int b = (*stack)->next->next->n;

    if (strcmp(op, "div") == 0 && b == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    if (strcmp(op, "mod") == 0 && b == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    if (strcmp(op, "add") == 0)
        (*stack)->next->next->n = b + a;
    else if (strcmp(op, "sub") == 0)
        (*stack)->next->next->n = b - a;
    else if (strcmp(op, "div") == 0)
        (*stack)->next->next->n = b / a;
    else if (strcmp(op, "mul") == 0)
        (*stack)->next->next->n = b * a;
    else if (strcmp(op, "mod") == 0)
        (*stack)->next->next->n = b % a;

    monty_pop(stack, line_number);
}

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
    perform_operation(stack, line_number, binary_operation);
}

/**
 * monty_sub - Subtracts the second value from the top of a stack_t linked list
 * by the top value.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
    perform_operation(stack, line_number, binary_operation);
}

/**
 * monty_div - Divides the second value from the top of a stack_t linked list
 * by the top value.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
    perform_operation(stack, line_number, binary_operation);
}

/**
 * monty_mul - Multiplies the second value from the top of a stack_t linked list
 * by the top value.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
    perform_operation(stack, line_number, binary_operation);
}

/**
 * monty_mod - Computes the modulus of the second value from the top of a
 * stack_t linked list by the top value.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
    perform_operation(stack, line_number, binary_operation);
}
