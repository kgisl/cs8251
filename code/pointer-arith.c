#include <stdio.h>
int main() {
  int a, b;
  char ca, cb;
  int *p = &a;
  int *q = &b;
  ca = 'b';
  cb = 'f';
  char cc = (ca + cb) % 96 + 96;
  printf("Add a and b to get %c\n", cc);
  *p = 100;
  *q = 200;
  printf("value of %d\n", *p + *q);
  // p = p + q;
  return 0;
}