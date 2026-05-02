# NOTES

## Just compile

Check if compile:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NL 100
#define NV 20

char line[NL];

int main(void) {
    return 0;
}
```

Run:
```
gcc main.c -o shell && echo "compiled ok"
```

output:
```
compiled ok
```

## Test the prompt

Check:
```
#include <stdio.h>    // printf, fgets, fflush
#include <stdlib.h>   // exit()
#include <string.h>   // strtok, strcmp

#define NL 100        // #define creates a named number. It's max characters per input line
#define NV 20         // max number of words in one command

char line[NL];        // creates a box that holds up to 100 characters

void prompt(void) {
  printf("tiny-sh> ");   // print the prompt text
  fflush(stdout);        // force it to appear immediately, before waiting for input
}

int main(void) {
    prompt();
    printf("\n");
    return 0;
}
```

Run:
```
gcc main.c -o shell && ./shell
```

Output:
```
tiny-sh> 
```

## Test fgets

Check:
```
#include <stdio.h>    // printf, fgets, fflush
#include <stdlib.h>   // exit()
#include <string.h>   // strtok, strcmp

#define NL 100        // #define creates a named number. It's max characters per input line
#define NV 20         // max number of words in one command

char line[NL];        // creates a box that holds up to 100 characters

void prompt(void) {
  printf("tiny-sh> ");   // print the prompt text
  fflush(stdout);        // force it to appear immediately, before waiting for input
}

int main(void) {
    while (1) {
        prompt();
        fgets(line, NL, stdin);
        if (feof(stdin)) exit(0);
        printf("raw input: [%s]\n", line);
    }
}
```

Run:
```
gcc main.c -o shell && ./shell
```

Type `hello there`:
```
tiny-sh> hello there
```

Output:
```
raw input: [hello there
]
```

## Test the blank line

Check:
```
#include <stdio.h>    // printf, fgets, fflush
#include <stdlib.h>   // exit()
#include <string.h>   // strtok, strcmp

#define NL 100        // #define creates a named number. It's max characters per input line
#define NV 20         // max number of words in one command

char line[NL];        // creates a box that holds up to 100 characters

void prompt(void) {
  printf("tiny-sh> ");   // print the prompt text
  fflush(stdout);        // force it to appear immediately, before waiting for input
}


int main(void) {

    while (1) {
        prompt();
        fgets(line, NL, stdin);
        if (feof(stdin)) exit(0);

        if (line[0] == '\n') continue; // When press Enter alone, line[0] is '\n', so the continue fires and skips printf
        
        printf("raw input: [%s]\n", line);
    }
}

Run:
```
gcc main.c -o shell && ./shell
```

Type `hello` and Output:
```
tiny-sh> hello
raw input: [hello
]
```

If then hit enters like for 3 times, then it shows empty:
```
tiny-sh> hello
raw input: [hello
]
tiny-sh> 
tiny-sh> 
tiny-sh> 
```

## Test strtok

Add the tokeniser and print each word.

Check:
```
#include <stdio.h>    // printf, fgets, fflush
#include <stdlib.h>   // exit()
#include <string.h>   // strtok, strcmp

#define NL 100        // #define creates a named number. It's max characters per input line
#define NV 20         // max number of words in one command

char line[NL];        // creates a box that holds up to 100 characters

void prompt(void) {
  printf("tiny-sh> ");   // print the prompt text
  fflush(stdout);        // force it to appear immediately, before waiting for input
}


int main(void) {
    char *v[NV];
    char *sep = " \t\n";
    int i;

    while (1) {
        prompt();
        fgets(line, NL, stdin);
        if (feof(stdin)) exit(0);

        if (line[0] == '\n') continue; // When press Enter alone, line[0] is '\n', so the continue fires and skips printf
        

        v[0] = strtok(line, sep);
        for (i = 1; i < NV; i++) {
            v[i] = strtok(NULL, sep);
            if (v[i] == NULL) break;
        }
        // after this loop, i = total number of words

        for (int j = 0; j < i; j++) {
            printf("v[%d] = %s\n", j, v[j]);
        }
    }
}
```

Run:
```
gcc main.c -o shell && ./shell
```

Type `ls -la /home` and output:
```
tiny-sh> ls -la /home
v[0] = ls
v[1] = -la
v[2] = /home
```

Note that `strtok` uses `char *sep = " \t\n";` to split the input line. 

You need all three because:
- " " (space): handles ls -la where words are separated by spaces
- "\t" (tab): handles input where someone presses Tab between words
- "\n" (newline): removes the newline that fgets leaves at the end of the line