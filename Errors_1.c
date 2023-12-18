#include "monty.h"

void print_error(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

int usage_error(void)
{
    print_error("USAGE: monty file\n");
}

int malloc_error(void)
{
    print_error("Error: malloc failed\n");
}

int f_open_error(char *filename)
{
    print_error("Error: Can't open file %s\n", filename);
}

int unknown_op_error(char *opcode, unsigned int line_number)
{
    print_error("L%u: unknown instruction %s\n", line_number, opcode);
}

int no_int_error(unsigned int line_number)
{
    print_error("L%u: usage: push integer\n", line_number);
}
