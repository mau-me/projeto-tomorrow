#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1;
  int* p_num1;

  num1 = 10;
  p_num1 = &num1;

  printf("O valor de num1 é: %d\n", num1);
  // printf("O endereço de num1 é: %p\n", &num1);
  // printf("O valor de p_num1 é: %p\n", p_num1);
  // printf("O valor de num1 pela variável p_num1 é: %d\n", *p_num1);

  *p_num1 = 20;
  printf("O valor de num1 é: %d\n", num1);
}