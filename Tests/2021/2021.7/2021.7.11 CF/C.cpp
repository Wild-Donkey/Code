#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
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
unsigned a[100005], b[100005], m, n, A, B, C, D, t, Ans(0), Tmp(0), Cnt[100005][2];
char Flg;
inline void Clr() {
  n = RD(), Flg = 0;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      b[i] = a[i] = RD();
    }
    sort(a + 1, a + n + 1);
    for (register unsigned i(1); i <= n; ++i) {
      Tmp = upper_bound(a + 1, a + n + 1, a[i]) - lower_bound(a + 1, a + n + 1, a[i]);
      Cnt[a[i]][i & 1] = ((Tmp + 1) >> 1);
      Cnt[a[i]][(i & 1) ^ 1] = Tmp >> 1;
//      printf("Lower %u %u %u\n", i, a[i], Tmp);
    }
    for (register unsigned i(1); i <= n; ++i) {
      if(Cnt[b[i]][i & 1]) {
        --Cnt[b[i]][i & 1];
      } else {
        Flg = 1;
      }
    }
    for (register unsigned i(1); i <= n; ++i) {
      Cnt[b[i]][0] = Cnt[b[i]][1] = 0;
    }
    printf(Flg ? "NO\n" : "YES\n");
  }
  return Wild_Donkey;
}

