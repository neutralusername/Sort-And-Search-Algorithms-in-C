#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "exercises.h"

int main(int argc, char *args[])
{
    srand(time(NULL)); // seeding rand innitially

    if (argc >= 2)
    {
        if (!strcmp(args[1], "-1.1"))
        {
            execute_1_1();
        }
        else if (!strcmp(args[1], "-1.2"))
        {
            execute_1_2();
        }
        else if (!strcmp(args[1], "-1.3"))
        {
            execute_1_3();
        }
        else if (!strcmp(args[1], "-1.4"))
        {
            execute_1_4();
        }
        else
        {
            fprintf(stderr, "invalid argument. valid arguments are \"-1.1\", \"-1.2\", \"-1.3\", \"-1.4\"");
        }
    }
    else
    {
        fprintf(stderr, "missing argument: provide one of \"-1.1\", \"-1.2\", \"-1.3\", \"-1.4\"");
    }
    return 0;
}