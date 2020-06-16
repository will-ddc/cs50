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

  person people[4];
  people[0].name = "ARCHER";
  people[0].number = "555-420-1200";

  people[1].name = "LANA";
  people[1].number = "555-420-1210";

  people[2].name = "CARTMEN";
  people[2].number = "555-420-1220";
  
  people[3].name = "KENNY";
  people[3].number = "555-420-1230";

  for (int i = 0; i < 4; i++) {
    if (strcmp(names[i], "KENNY") == 0) {
      printf("%s Phone #: %s\n", names[i], numbers[i]);
      return 0;
    }
  }
  printf("Not Found\n");
  return 1;
}
