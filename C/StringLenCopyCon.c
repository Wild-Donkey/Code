#include <stdio.h>
unsigned Len(char *x) {  // 求字符串 x 的长度
  unsigned i = 0;
  while (x[i]) ++i;  // x 未结束, 继续向后探查
  return i;
}
void MemCpy(char *x, char *y, unsigned Sz) {  // 将 x 的前 Sz 字节复制到位置 y
  unsigned i;
  for (i = 0; i < Sz; ++i) y[i] = x[i];
}
void Connect(char *x, char *y, unsigned Szx, unsigned Szy) {
  MemCpy(x, y + Szy, Szx);  // 将 x 的前 Szx 字节连接到 y 的 Szy 个字节后面
}
void main() {
  char A[105], B[105], C[105];
  scanf("%s%s", A, B);
  printf("Len %u %u\n", Len(A), Len(B));  // A, B 的长度
  MemCpy(A, C, Len(A));                   // 将 A 复制到 C
  printf("Copy %s\n", C);
  Connect(C, B, Len(C), Len(B));  // 将 B 连接到 C 后面
  printf("Connect %s\n", C);
}
/*
sdfgfdgsgdfdfg23df
gdfgsdfsdf
*/