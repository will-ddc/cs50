#include <stdio.h>

// custom function to print cough

void cough(void) {
  printf("cough\n");
}

int main(void) {
  /*
  for loop to print cough 3 times
  for (int i = 0; i < 3; i++) {
    printf("cough\n");
  }
  */
  cough();
  cough();
  cough();
}
