#include <stdio.h>


int main(int argc, char **argv){
    int i;

    printf("argc=%d\n", argc);

    puts("\nargv ===========================");

    for(i=0; i<argc; i++)
        printf("%s\n", argv[i]);

    return 0;
}


