#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point for Monty Interp
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
    FILE *script_fd = NULL;
    int exit_code = EXIT_SUCCESS;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    script_fd = fopen(argv[1], "r");
    if (script_fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    exit_code = run_monty(script_fd);

    fclose(script_fd);
    return exit_code;
}
