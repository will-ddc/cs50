#include <cs50.h>
#include <stdio.h>

int main(void) {
  int age = get_int("How old are you>\n");
  int days = age * 365;
  printf("You are %i days old\n", days);
}
