#include "monty.h"

#define PRINT_ERROR(format, ...) do { \
    fprintf(stderr, format, ##__VA_ARGS__); \
    return EXIT_FAILURE; \
} while (0)

/**
 * pop_error - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_number)
{
    PRINT_ERROR("L%u: can't pop an empty stack\n", line_number);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_number)
{
    PRINT_ERROR("L%d: can't pint, stack empty\n", line_number);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
    PRINT_ERROR("L%u: can't %s, stack too short\n", line_number, op);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
    PRINT_ERROR("L%u: division by zero\n", line_number);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_number, char *message)
{
    PRINT_ERROR("L%u: can't pchar, %s\n", line_number, message);
}
