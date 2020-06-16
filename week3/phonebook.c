#include <cs50.h>
#include <stdio.h>
#include <string.h>

// added person struct to create phonebook

typedef struct {
  /* data */
  string name;
  string number;
}
person;

int main(void) {
  string names[4] = {"ARCHER", "LANA", "CARTMENT", "KENNY"};
  string numbers[4] = {"555-420-1200", "555-420-1210", "555-420-1220", "555-420-1230"};

  for (int i = 0; i < 4; i++) {
    if (strcmp(names[i], "KENNY") == 0) {
      printf("%s Phone #: %s\n", names[i], numbers[i]);
      return 0;
    }
  }
  printf("Not Found\n");
  return 1;
}
