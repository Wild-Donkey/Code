#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), Flg, A, B, C, D, t, Ans(0), Tmp(0);
char a[100005];
inline void Clr() {
  n = RD(), Flg = 0;
  scanf("%s", a + 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    // printf("n = %u\n", n);
    for (register unsigned i((n >> 1) + 1); i <= n; ++i) {
      if (a[i] == '0') {
        Flg = i;
        break;
      }
    }
    // printf("Flg = %u\n", Flg);
    if (Flg) {
      printf("1 %u 1 %u\n", Flg, Flg - 1);
      continue;
    }
    for (register unsigned i(1); i <= (n >> 1); ++i) {
      if (a[i] == '0') {
        Flg = i;
        break;
      }
    }
    if (Flg) {
      // printf("Flg = %u\n", Flg);
      printf("%u %u %u %u\n", Flg, n, Flg + 1, n);
      continue;
    }
    printf("%u %u %u %u\n", 1, n - 1, 2, n);
  }
  // system("pause");
  return Wild_Donkey;
}