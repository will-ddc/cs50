#include <cs50.h>
#include <stdio.h>

int main(void) {
  float price = get_float("What is the price?\n");
  printf("The total with tax is %f\n", price * 1.0625);
}
