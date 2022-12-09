#include <stdio.h>
#include <string.h>
#include "exercises.h"

int main(int argc, char *args[]) {
    if (argc >= 2) {
        if (!strcmp(args[1], "-1.1")) {
            execute_11();
        }
        else if (!strcmp(args[1], "-1.2")) {
            execute_12();
        }
        else if (!strcmp(args[1], "-1.3")) {
            execute_13();
        }
        else if (!strcmp(args[1], "-1.4")) {
            execute_14();
        }
        else {
            fprintf(stderr, "invalid argument. valid arguments are \"-1.1\", \"-1.2\", \"-1.3\", \"-1.4\"");
        }
    }
    else{
        fprintf(stderr, "missing argument: provide one of \"-1.1\", \"-1.2\", \"-1.3\", \"-1.4\"");
    }
    return 0;
}