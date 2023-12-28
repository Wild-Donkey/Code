#include <stdio.h>
unsigned StrToWord(char *x, char (*y)[105]) {
  unsigned i = 0, j = 0, k = 0;
  while (x[i]) {
    k = 0;
    // printf("To %u\n", i);
    while (x[i] && x[i] < '0') ++i;
    // printf("From %u\n", i);
    if (!x[i]) break;
    while ((x[i] >= '0') && x[i]) y[j][k++] = x[i++];
    ++j;
  }
  return j;
}
unsigned Len(char *x) {
  unsigned i = 0;
  while (x[i]) ++i;
  return i;
}
char Swap(char *x, char *y) {
  unsigned i = 0;
  while (x[i] | y[i]) x[i] ^= y[i], y[i] ^= x[i], x[i] ^= y[i], ++i;
}
void Sort(char (*x)[105], unsigned y) {
  unsigned i, j;
  for (i = y - 1; i; --i) {
    for (j = 0; j < i; ++j)
      if (Len(x + j) > Len(x + j + 1)) Swap(x + j, x + j + 1);
  }
}
unsigned Connect(char *x, char (*y)[105], unsigned z) {
  unsigned i, j, k = 0;
  for (i = 0; i < z; ++i) {
    for (j = Len(y + i) - 1; ~j; --j) x[k + j] = y[i][j];
    k += Len(y + i), x[k++] = ' ';
  }
  x[k] = '\0';
  return k - 1;
}
void main() {
  char Src[10005], Word[105][105];
  unsigned CntW = 10004;
  while (~CntW) Src[CntW--] = 0;
  fgets(Src, 10005, stdin);
  CntW = StrToWord(Src, Word);
  Sort(Word, CntW);
  unsigned i = 0;
  CntW = Connect(Src, Word, CntW);
  while (i < CntW) putchar(Src[i++]);
  putchar(0x0A);
}
/*
sdkfjh kjhsd kjfsdf hdsjkf hskd fsdfksd hs kdf sdk fjsf sd
*/