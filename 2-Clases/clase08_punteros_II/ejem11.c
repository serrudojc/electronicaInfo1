#include <stdio.h>

int main(int argc, char **argv, char **arge){
  int i = 0;

  puts("\narge ---");
  while(arge[i]){
    printf("%s\n", arge[i]);
    i++;
  }

  return 0;
}


