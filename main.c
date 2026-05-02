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
    // char *v[NV];          // array of pointers, each holding a pointer to one word e.g. v[0]="ls" v[1]="-la"
    // char *sep = " \t\n";  // the characters used to split input: space, tab, newline
    // int i;                // counter used in the token loop

    // while (1) {           // run forever until exit() or Ctrl+C
    //     prompt();
    //     fgets(line, NL, stdin);  // reads up to 100 characters from input into line[]
    //     if (feof(stdin)) exit(0);  // if input is closed (Ctrl+D), exit cleanly
    //     if (line[0] == '\n' || line[0] == '\000') continue;  // ignore blank input, go back to prompt

    //     v[0] = strtok(line, sep);       // strtok cuts the line into words. It gets the first word, e.g. "ls"
    //     for (i = 1; i < NV; i++) {
    //         v[i] = strtok(NULL, sep);     // get each next word
    //         if (v[i] == NULL) break;      // stop when there are no more words
    //     }
    //     // after this loop, i = total number of words

    //     printf("you typed: %s\n", v[0]);  // just to confirm input works
    // }

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

        for (int j = 0; j < i; j++) {
            printf("v[%d] = %s\n", j, v[j]);
        }
    }
}
