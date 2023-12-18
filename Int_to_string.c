#include <stdlib.h>

char *get_int(int num);

char *get_int(int num)
{
    // Handle special case for 0
    if (num == 0)
    {
        char *result = malloc(2);
        if (result == NULL)
            return NULL;
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Determine the length of the string
    unsigned int temp = _abs(num);
    int length = num < 0 ? get_numbase_len(temp, 10) + 1 : get_numbase_len(temp, 10);

    // Allocate memory for the string
    char *ret = malloc(length + 1);
    if (ret == NULL)
        return NULL;

    // Fill the buffer with the number representation
    fill_numbase_buff(temp, 10, ret, length);

    // Add the negative sign if necessary
    if (num < 0)
        ret[0] = '-';

    return ret;
}
