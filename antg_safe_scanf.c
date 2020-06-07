/**
 * Example how to properly and safely reading the 7/8-bit characters from a [stdin] stream with a [scanf] function in C.
 * Example how to properly flushing the [stdin] stream in C (don't use fflush(stdin)!).
 * Note: You can remove [#ifdef] blocks.
 * 
 * Copyright (c) 2020 Gena ANTG <antg.production@gmail.com>
 * License: GNU GPL
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Define a function for debugging
 * if a [-D DEBUG_ENABLED] flag is enabled for a GCC compiler
 */
#ifdef DEBUG_ENABLED
static inline void debug(char *msg) { printf("[DEBUG]: %s\n", msg); }
#endif

/**
 * A proper way to the flushing [stdin] stream
 * ! Important: You should use this function after every [scanf] calling!
 */
void stdin_flushing(void)
{
    #ifdef DEBUG_ENABLED
        debug("Flushing [stdin]...");
    #endif
    int chr = 0;
    while ((chr = getchar()) != '\0' && chr != '\n' && chr != '\r' && chr != EOF);
}

/**
 * A proper and safe way to reading a 7/8-bit (ASCII) character from the [stdin] stream
 * @param chr 7/8 bit (ASCII) character
 * @return chr
 */
char safe_read_char(char chr)
{
    int filled = scanf("%1c", &chr);
    if (filled != 1)
    {
        fprintf(stderr, "[E] Reading error\n");
        exit(EXIT_FAILURE);
    }
    /**
     * Return a first occurred LF symbol
     * But still catch the LF symbols in the [stdin] stream (line 32)
     */
    if (chr != '\n') {
        stdin_flushing();
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
    chr = safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    printf("Provide some char: ");
    chr = safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    printf("Provide some char: ");
    chr = safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    return EXIT_SUCCESS;
}
