#include <stdio.h>
char Read(char (*x)[105]) {
  unsigned i = 9;
  while (~i) scanf("%s", x[i--]);
}
char Prt(char (*x)[105]) {
  unsigned i = 0;
  while (i < 10) printf("%s\n", x[i++]);
}
unsigned Len(char *x) {
  unsigned i = 0;
  while (x[i]) ++i;
  return i;
}
char Less(char *x, char *y) {
  unsigned i = 0;
  while (x[i] == y[i] && x[i]) ++i;
  return x[i] < y[i];
}
char Intg(char *x, char *y) {
  if (Len(x) ^ Len(y)) return Len(x) < Len(y);
  return Less(x, y);
}
char (*Comp[2])(char *, char *) = {&Intg, &Less};
char Swap(char *x, char *y) {
  unsigned i = 0;
  while (x[i] | y[i]) x[i] ^= y[i], y[i] ^= x[i], x[i] ^= y[i], ++i;
}
char Sort(char (*x)[105], unsigned Op) {
  unsigned i, j;
  for (i = 9; i; --i)
    for (j = 0; j < i; ++j)
      if ((*Comp[Op])(x + j + 1, x + j)) Swap(x + j, x + j + 1);
}
void main() {
  char Str[10][105];
  unsigned Op;
  scanf("%u", &Op);
  Read(Str);
  Sort(Str, Op);
  Prt(Str);
}
/*
1
sdfg
fd
gs
g
df
dfg
23df
gdf
gsdf
sdf
0
876
456
4
6345
6
54
463
54646
54
56
*/