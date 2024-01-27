#include <stdio.h>
#include "inputs.h"

int inputInt(int bufsize){
    char buf[bufsize];
    int a;
    int ret;
    fgets(buf, bufsize, stdin);

    ret = sscanf(buf, "%d", &a);

    if (ret != 1) {
        fprintf(stderr, "Ce n'est pas un nombre.\n");
        return 1;
    }
    return ret;
}

int inputStr(int bufsize){
    char buf[bufsize];
    int ret;
    char word[bufsize];
    fgets(buf, bufsize, stdin);

    ret = sscanf(buf, "%s", word);
    if (ret != 1) {
        fprintf(stderr, "Ce n'est pas une chaine.\n");
        return 1;
    }

    printf("You entered %s\n", word);
    return ret;
}