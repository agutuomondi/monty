#include <stdlib.h>
#include <string.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Splits a string into words.
 *
 * @str: String to separate into words.
 * @delims: Delimiters to use to split words.
 *
 * Return: 2D array of pointers to each word.
 */
char **strtow(char *str, char *delims)
{
    if (str == NULL || !*str)
        return NULL;

    int wc = get_word_count(str, delims);

    if (wc == 0)
        return NULL;

    char **words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    int i = 0;
    while (i < wc)
    {
        if (is_delim(*str, delims))
        {
            str = get_next_word(str, delims);
            continue;
        }

        int wordLen = get_word_length(str, delims);

        words[i] = malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
                free(words[i--]);
            free(words);
            return NULL;
        }

        strncpy(words[i], str, wordLen);
        words[i][wordLen] = '\0'; /* Set end of string */
        str = get_next_word(str, delims);
        i++;
    }

    words[i] = NULL; /* Last element is null for iteration */
    return words;
}

/**
 * is_delim - Checks if a character is a delimiter.
 *
 * @ch: Character to check.
 * @delims: Pointer to a null-terminated array of delimiters.
 *
 * Return: 1 (success) or 0 (failure).
 */
int is_delim(char ch, char *delims)
{
    while (*delims)
    {
        if (*delims == ch)
            return 1;
        delims++;
    }
    return 0;
}

/**
 * get_word_length - Gets the length of the current word in a string.
 *
 * @str: String to get the word length from.
 * @delims: Delimiters to use to delimit words.
 *
 * Return: Word length of the current word.
 */
int get_word_length(char *str, char *delims)
{
    int wLen = 0;
    int pending = 1;

    while (*str)
    {
        if (is_delim(*str, delims))
            pending = 1;
        else if (pending)
            wLen++;

        if (wLen > 0 && is_delim(*str, delims))
            break;

        str++;
    }

    return wLen;
}

/**
 * get_word_count - Gets the word count of a string.
 *
 * @str: String to get the word count from.
 * @delims: Delimiters to use to delimit words.
 *
 * Return: The word count of the string.
 */
int get_word_count(char *str, char *delims)
{
    int wc = 0;
    int pending = 1;

    while (*str)
    {
        if (is_delim(*str, delims))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            wc++;
        }
        str++;
    }

    return wc;
}

/**
 * get_next_word - Gets a pointer to the first character of the next word in a string.
 *
 * @str: String to get the next word from.
 * @delims: Delimiters to use to delimit words.
 *
 * Return: Pointer to the first character of the next word.
 */
char *get_next_word(char *str, char *delims)
{
    int pending = 0;

    while (*str)
    {
        if (is_delim(*str, delims))
            pending = 1;
        else if (pending)
            break;

        str++;
    }

    return str;
}
