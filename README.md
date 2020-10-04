# How to properly and safely use a scanf function in C

An example how to properly and safely you can use a **[scanf]** function to reading **7/8-bit ASCII** characters in **C** language.

## 🚀 Build and run

### Check the GCC compiler version first

```!
$ gcc --version
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### 🚀 Build

You can add a **[-D DEBUG_ENABLED]** flag for your GCC compiler to display the **[stdin]** flushing process.

```bash
gcc antg_safe_scanf.c -o safe_scanf -std=c11 -Wall -Wextra -Wpedantic -D DEBUG_ENABLED
```

### 🚀 Run

```bash
$ ./safe_scanf
Provide some char: abc
[DEBUG]: Flushing [stdin]...
Char is: [a]
Provide some char: bcd
[DEBUG]: Flushing [stdin]...
Char is: [b]
Provide some char: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
[DEBUG]: Flushing [stdin]...
Char is: [a]
$ echo $?
0
```

Output when a **[Enter] (LF)** has occurred:

```bash
$ ./safe_scanf
Provide some char:
Char is: [
]
Provide some char:
Char is: [
]
Provide some char:
Char is: [
]
$ echo $?
0
```

&copy; 2020 Gena ANTG
