#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
    char *exit_str = get_int(error_code);
    
    if (!exit_str)
    {
        malloc_error();
        return;
    }

    free_tokens();  // Free the existing op_toks

    op_toks = malloc(sizeof(char *) * 2);  // Allocate memory for op_toks
    if (!op_toks)
    {
        free(exit_str);
        malloc_error();
        return;
    }

    op_toks[0] = exit_str;
    op_toks[1] = NULL;
}
