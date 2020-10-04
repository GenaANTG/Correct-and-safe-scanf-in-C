/**
 * Proper and safe way to read the 7/8-bit characters from the [stdin] stream with a [scanf] function in C.
 * Proper way to flush the [stdin] stream in C. (don't use the fflush(stdin), cuz it's wrong!).
 * Note: You can remove [#ifdef] blocks.
 * Copyright (c) 2020 Gena ANTG <antg.production@gmail.com>
 * License: GNU GPL
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef EMPTY_STRING
#define EMPTY_STRING ""
#endif

#ifndef LF
#define LF '\n'
#endif

#ifndef LE
#define LE '\0'
#endif

/**
 * Define a function for debugging
 * if a [-D DEBUG_ENABLED] flag is enabled for a GCC compiler
 */
#ifdef DEBUG_ENABLED
static inline void debug(char *msg) { printf("[DEBUG]: %s\n", msg); }
#endif

/**
 * A proper way to flush the [stdin] stream
 */
void flush_stdin(void)
{
#ifdef DEBUG_ENABLED
    debug("Flushing [stdin]...");
#endif
    int chr = 0;

    while ((chr = getchar()) != LE && chr != LF)
    {
        if (chr == EOF)
        {
            puts(EMPTY_STRING);
            exit(EXIT_SUCCESS);
        }
    }
}

/**
 * A proper and safe way to read a 7/8-bit (ASCII) character from the [stdin] stream
 * @param chr 7/8 bit (ASCII) character
 * @return chr
 */
char antg_safe_read_char(char chr)
{
    int filled = scanf("%1c", &chr);
    if (filled == -1)
    {
        puts(EMPTY_STRING);
        exit(EXIT_SUCCESS);
    }
    if (filled != 1)
    {
        fprintf(stderr, "[E] Reading error\n");
        exit(EXIT_FAILURE);
    }
    /**
     * Return first occurred [\n] symbol
     * But still catch other [\n] symbols in [stdin] stream
     */
    if (chr != '\n')
    {
        flush_stdin();
    }

    return chr;
}

/**
 * Run It
 */
int main(void)
{
    char chr = '\0';

    printf("Provide some char: ");
    chr = antg_safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    printf("Provide some char: ");
    chr = antg_safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    printf("Provide some char: ");
    chr = antg_safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    return EXIT_SUCCESS;
}
