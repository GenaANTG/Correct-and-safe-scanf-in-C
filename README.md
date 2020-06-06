# A [scanf] function in C

An example how to properly and safe you can use a **[scanf]** function to reading **7/8-bit ASCII** characters in **C** language.

## Compile

You can add **-D DEBUG_ENABLED** flag for your GCC compiler to display **[stdin]** flushing process.

`
$ gcc antg_safe_scanf.c -o safe_scanf -std=c11 -Wall -Wextra -Wpedantic -D DEBUG_ENABLED
`

## Run

```bash
$ ./safe_scanf
Provide some char: abc
Char is: [a]
[DEBUG]: Flushing [stdin]...
Provide some char: bca
Char is: [b]
[DEBUG]: Flushing [stdin]...
Provide some char: cab
Char is: [c]
$ echo $?
0
$
```

&copy; 2020 by Gena ANTG <antg.production@gmail.com>
