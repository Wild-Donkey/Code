#include <stdio.h>
int main() {
  unsigned char a[4] = {0xaa, 0xab};
  char *d;
  short *b;
  unsigned short *c;
  d = (char *)a;
  b = (short *)a;
  c = (unsigned short *)a;
  printf(" d=%d\n b=%d\n c=%u\n", *d, *b, *c);
}