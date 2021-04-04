#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline long long RD() {
  long long intmp(0), insi(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && rdch != '-') {
    rdch = getchar();
  }
  if (rdch == '-') {
    insi = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insi;
}
int n, m, k, l, t;
int p;
long long a, b;
bool f[505][505][25], flg(0);  // i 到 j 有 %p=k 的路径
int ksm(int x, long long y) {
  if (y == 0) {
    return 1;
  }
  if (y == 1) {
    return x;
  }
  int tmp = ksm(x, y >> 1);
  tmp = (long long)tmp * tmp % p;
  if (y % 2) {
    return (int)((long long)(x)*tmp % p);
  }
  return tmp;
}
int main() {
  /*while (1) {
    printf("%d\n", RD());
  }*/
  /*p = 0x3f3f3f3f;
  while (1) {
    a = RD();
    b = RD();
    printf("%d\n", ksm((int)(a % p), b));
  }*/
  a = RD();
  p = RD();
  for (register long long i(1); i <= 1005; ++i) {
    if (ksm(int(a % p), i) == ksm(int(i % p), a) && (i != a)) {
      printf("%lld\n", i);
      // break;
    }
  }
  system("pause");
  return 0;
}