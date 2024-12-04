#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>

#define MAXGR 10

int main(int argc, char *argv[]) {
    int errcode;
    char msgbuf[100];
    regex_t regex;
    regmatch_t bags[MAXGR];

    char *regexp = argv[1];
    char *substitution = argv[2];
    char *string = argv[3];

    if (argc != 4) {
    	fprintf(stderr, "Wrong number of arguments, need exactly 3\n");
    	exit(1);
    }


    return 0;
}