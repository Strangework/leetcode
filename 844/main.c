#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void reduceString(char* s) {
  int sNdx = 0;
  printf("%lu\n", strlen(s));
  for (int i=0; i < strlen(s); i++) {
    printf("%d : %d\n", i, sNdx);
    if (s[i] != '#') {
      s[sNdx] = s[i];
      sNdx++;
    } else {
      sNdx = sNdx-1 > 0 ? sNdx-1 : 0;
      s[sNdx] = '\0';
    }
  }
  s[sNdx] = '\0';
}

bool backspaceCompare(char* S, char *T) {
  reduceString(S);
  printf("%s\n", S);

  reduceString(T);
  printf("%s\n", T);
  
  if (strcmp(S, T) == 0) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char** argv) {
  printf(backspaceCompare(argv[1], argv[2]) ? "true\n" : "false\n");
}
