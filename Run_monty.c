#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int execute_line(FILE *script_fd, stack_t **stack, char *line, size_t len, unsigned int *line_number);
int process_file(FILE *script_fd);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *script_fd = fopen(argv[1], "r");
    if (script_fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int exit_code = process_file(script_fd);

    fclose(script_fd);
    return exit_code;
}

int process_file(FILE *script_fd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    int exit_status = EXIT_SUCCESS;

    if (init_stack(&stack) == EXIT_FAILURE)
        return EXIT_FAILURE;

    while (getline(&line, &len, script_fd) != -1)
    {
        line_number++;
        exit_status = execute_line(script_fd, &stack, line, len, &line_number);
        if (exit_status != EXIT_SUCCESS)
            break;
    }

    free_stack(&stack);
    free(line);

    return exit_status;
}

int execute_line(FILE *script_fd, stack_t **stack, char *line, size_t len, unsigned int *line_number)
{
    void (*op_func)(stack_t**, unsigned int);
    int exit_status = EXIT_SUCCESS;

    op_toks = strtow(line, DELIMS);
    if (op_toks == NULL)
    {
        if (is_empty_line(line, DELIMS))
            goto cleanup;
        free_stack(stack);
        return malloc_error();
    }
    else if (op_toks[0][0] == '#') /* comment line */
    {
        free_tokens();
        goto cleanup;
    }

    op_func = get_op_func(op_toks[0]);
    if (op_func == NULL)
    {
        free_stack(stack);
        exit_status = unknown_op_error(op_toks[0], *line_number);
        free_tokens();
        goto cleanup;
    }

    unsigned int prev_tok_len = token_arr_len();
    op_func(stack, *line_number);

    if (token_arr_len() != prev_tok_len)
    {
        if (op_toks && op_toks[prev_tok_len])
            exit_status = atoi(op_toks[prev_tok_len]);
        else
            exit_status = EXIT_FAILURE;
        free_tokens();
        goto cleanup;
    }

    free_tokens();

cleanup:
    return exit_status;
}
