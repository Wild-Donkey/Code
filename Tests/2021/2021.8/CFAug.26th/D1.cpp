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
unsigned  m, n, Cnt(0), A, B, C, D, t, Tmp(0);
int Sum[300005], Ans;
char a[300005];
inline void Clr() {
  n = RD(), m = RD(), Sum[0] = 0;
  scanf("%s", a + 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      // printf("A %u = %d\n", i, ((a[i] == '+') ? (1) : (-1)));
      Sum[i] = Sum[i - 1] + ((a[i] == '+') ? (1) : (-1)) * ((i & 1) ? (1) : (-1));
      // printf("Sum %u = %d\n", i, Sum[i]);
    }
    for (register unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD(), Ans = Sum[B] - Sum[A - 1];
      if ((B - A) & 1) printf("%d\n", (Ans ^ 0) ? (2) : (0));
      else  printf("1\n");
    }
  }
  // system("pause");
  return Wild_Donkey;
}