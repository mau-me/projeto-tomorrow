#include <stdio.h>
#include <stdlib.h>

int main() {
  char* sen;
  sen = (char*)malloc(100 * sizeof(char));

  if (sen == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("Enter a string: ");
  scanf("%[^\n]%*c", sen);

  printf("You entered: %s\n", sen);
}