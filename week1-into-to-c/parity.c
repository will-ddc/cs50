#include <cs50.h>
#include <stdio.h>

int main(void) {
  // prompt user to input a number

  int n = get_int("Input a number\n");
  /*
  loop to check if input number is even or odd
   */
  if (n % 2 == 0)
  {
    printf("%i is even\n", n);
  }
  else
  {
    printf("%i is odd\n", n);
  }
}
