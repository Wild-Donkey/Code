#include <stdio.h>
void main() {
  char c;
  scanf("%c", &c);
  printf("%4c\t%c\n", c, c);
  printf("%2c\t%c\t%3c\t%c\n", c, c, c, c);
  printf("%c\t%c\t%5c\t%c\n", c, c, c, c);
  printf("%c\t%c\t%5c\t%c\n", c, c, c, c);
  printf("%2c\t%5c\n", c, c, c, c);
  printf("%3c\t%c\n", c, c, c, c);
  printf("%2c\t%5c\n", c, c, c, c);
  printf("%c\t%c\t%5c\t%c\n", c, c, c, c);
  printf("%c\t%c\t%5c\t%c\n", c, c, c, c);
  printf("%2c\t%c\t%3c\t%c\n", c, c, c, c);
  printf("%4c\t%c\n", c, c);
}

/*
   c    c
 c      c         c     c
c       c           c   c
c       c           c   c
 c          c
  c     c
 c          c
c       c           c   c
c       c           c   c
 c      c         c     c
   c    c
*/