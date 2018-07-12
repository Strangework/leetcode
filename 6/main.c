#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* convert(char* s, int numRows) {
  if (numRows < 1) {
    printf("FUCK you\n");
    return NULL;
  }
  if (numRows == 1) {
    return s;
  }

  char* ret = malloc(strlen(s) * sizeof(char));

  int* rowNdxs = malloc(numRows * sizeof(int));
  char** rows = malloc(numRows * sizeof(int*));
  for (int i=0; i < numRows; i++) {
    rowNdxs[i] = 0;
    rows[i] = malloc(strlen(s) * sizeof(char));
  }

  int currNdx = 0;
  bool increasing = true;
  for (int i=0; i < strlen(s); i++) {
    //printf("%d : %c\n", currNdx, s[i]);

    rows[currNdx][rowNdxs[currNdx]] = s[i];
    rowNdxs[currNdx]++;
    
    if (increasing) {
      if (currNdx+1 == numRows) {
        increasing = false;
        currNdx--;
      } else {
        currNdx++;
      }
    } else {
      if (currNdx == 0) {
        increasing = true;
        currNdx++;
      } else { 
        currNdx--;
      }  
    }
  }

  int n=0;
  for (int i=0; i < numRows; i++) {
    for (int j=0; j < rowNdxs[i]; j++) {
      ret[n] = rows[i][j];
      n++;
    }
    free(rows[i]);
  }
  free(rows);
  free(rowNdxs);
  ret[n] = '\0';

  return ret;
}

int main(int argc, char **argv) {
  printf("%s\n", convert(argv[1], atoi(argv[2])));
  return 0;
}
