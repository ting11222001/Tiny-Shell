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