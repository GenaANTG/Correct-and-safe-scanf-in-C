/**
 * Example how to properly and safely reading the 7/8-bit characters from [stdin] with a [scanf] function in C.
 * Example how to properly flushing [stdin] in C (don't use fflush(stdin)!).
 * Note: You can remove [#ifdef] blocks.
 * 
 * Copyright (c) 2020 Gena ANTG <antg.production@gmail.com>
 * License: GNU GPL
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Define a function to logging
 * if a [-D DEBUG_ENABLED] flag is enabled for a GCC compiler
 */
#ifdef DEBUG_ENABLED
static inline void debug(char *msg) { printf("[DEBUG]: %s\n", msg); }
#endif

/**
 * A correct way to flushing [stdin]
 * ! Important: You should use this function 
 * ! Important: after every a [scanf] (or event better) [safe_read_char] calling!
 */
void stdin_flushing(void)
{
    #ifdef DEBUG_ENABLED
        debug("Flushing [stdin]...");
    #endif
    int chr = 0;
    while ((chr = getchar()) && chr != '\0' && chr != '\n' && chr != EOF);
}

/**
 * A correct and safe way to reading a 7/8-bit (ASCII) character from [stdin]
 * @param chr 7/8 bit (ASCII) character
 * @return chr
 */
char safe_read_char(char chr)
{
    int readed = scanf("%1c", &chr);
    if (readed != 1)
    {
        fprintf(stderr, "[E] Reading error\n");
        exit(EXIT_FAILURE);
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

    stdin_flushing();

    printf("Provide some char: ");
    chr = safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    stdin_flushing();

    printf("Provide some char: ");
    chr = safe_read_char(chr);
    printf("Char is: [%c]\n", chr);

    return EXIT_SUCCESS;
}
