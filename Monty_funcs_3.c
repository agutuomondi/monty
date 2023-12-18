#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_print(stack_t **stack, unsigned int line_number, int is_char);

/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * monty_print - Prints the character or string in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * @is_char: Flag indicating whether to treat the value as a character.
 */
void monty_print(stack_t **stack, unsigned int line_number, int is_char)
{
    stack_t *tmp = (*stack)->next;

    if (tmp == NULL)
    {
        set_op_tok_error(is_char ? pchar_error(line_number, "stack empty") :
                                   pchar_error(line_number, "stack empty"));
        return;
    }

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        if (is_char)
            printf("%c\n", tmp->n);
        else
            printf("%c", tmp->n);

        tmp = tmp->next;
    }

    if (!is_char)
        printf("\n");

    (void)line_number;
}

/**
 * monty_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
    monty_print(stack, line_number, 1);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
    monty_print(stack, line_number, 0);
}
