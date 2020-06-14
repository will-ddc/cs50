#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int sides[]);

int main(void) {
  int triangle = 3;
  int sides[triangle];
  for (int i = 0; i < triangle; i++) {
    sides[i] = GetInt("Input Side %i Length: ", i + 1);
  }
  bool validate = valid_triangle(sides)
  if (validate) {
    printf("You created a triangle\n");
  } else {
    printf("That is not a triangle\n");
  }
}

bool valid_triangle(int sides[]) {
  for (int i = 0; i < 3; i++) {
    if (sides[i] <= 0) {
      return false
    }
  }
  if (sides[0] + sides[1] > sides[2]) {
    return true
  } else {
    return false
  }
}
