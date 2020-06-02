#include <stdio.h>

// List of Functions used in app

void cough(void);

// Main App

int main(void) {
  // for loop to print cough 3 times
  for (int i = 0; i < 3; i++) {
    cough();
  }
}

// custom function to print cough

void cough(void) {
  printf("cough\n");
}
