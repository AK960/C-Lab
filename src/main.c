#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Bitte gebe zwei Zahlen ein...\n");
  int a, b;

  scanf("%d %d", &a, &b);
  printf("Das Ergebnis ist: %d\n", a + b);

  return 0;
};