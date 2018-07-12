#include <stdlib.h>
#include <stdio.h>

int reverse(int x) {
    // [-2^31, 2^31-1] -> [-32768, 32767]
    char str[6];
    char rev[6];
    sprintf(str, "%d", x);
    for (int i=0; i<5; i++) {
      rev[4-i] = str[i]; 
    }
    printf("%s\n", rev);
    return atoi(rev);
}

int main(int argc, char** argv) {
  printf("%d\n", reverse(atoi(argv[1])));
}
