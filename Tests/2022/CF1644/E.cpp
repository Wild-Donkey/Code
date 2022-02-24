#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long Ans(0);
unsigned m, n, R(0), D(0);
unsigned A, B, C, t;
unsigned Cnt(0), Tmp(0);
char a[200005];
inline void Clr() {
  memset(a, 0, m + 3);
  n = RD(), scanf("%s", a), m = strlen(a);
  // printf("m = %u\n", m);
  A = B = R = D = 0, Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    // printf("Come");
    Clr();
    for (unsigned i(0); i < m; ++i) {
      if (a[i] == 'R') {
        ++R;
        if (!D) Ans += n - 1, ++A;
        else Ans += D - B;
      }
      else {
        ++D;
        if (!R) Ans += n - 1, ++B;
        else Ans += R - A;
      }
    }
    if ((!R) || (!D)) printf("%u\n", n);
    else printf("%llu\n", (unsigned long long)n * n - Ans);
  }
  return Wild_Donkey;
}