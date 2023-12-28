#include <stdio.h>
char Src[40], Des[23];
unsigned LenS = 0, LenD = 0;
unsigned long long Num;
void main() {
  scanf("%s", Src);
  while (Src[LenS] >= '0' && Src[LenS] <= '9')
    Num = (Num << 3) + Src[LenS++] - '0';
  if (Num == 0) Des[LenD++] = '0';
  while (Num) Des[LenD++] = '0' + Num % 10, Num /= 10;
  unsigned i, j;
  for (i = 0, j = LenD - 1; i < j; ++i, --j)
    Des[i] ^= Des[j], Des[j] ^= Des[i], Des[i] ^= Des[j];
  printf("%s", Des);
}