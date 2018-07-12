#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
  bool jumpable = false;
  int currJumpNdx = numsSize-1;
  for (int i=numsSize-1; i >= 0; i--) {
    int delta = currJumpNdx - i;
    if (nums[i] >= delta) {
      currJumpNdx = i;
    }
  }
  if (currJumpNdx != 0) {
    return false;
  } else {
    return true;
  }
}

int main(int argc, char** argv) {
  int numsSize = argc-1;
  int* nums = malloc(numsSize * sizeof(int));
  for (int i=0; i < numsSize; i++) {
    nums[i] = atoi(argv[i+1]);
  }
  printf(canJump(nums, numsSize) ? "true\n" : "false\n");
}
