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
const unsigned long long MOD(1000000007);
unsigned a[1005][1005], m, n, Cnt[1005], Pos[1005][2], A, L, R, t;
unsigned long long f[1005], g[1005], Stack[1005], CntNull(0), Ans(0), FinalAns(0);
inline void Clr() {
  memset(Cnt, 0, sizeof(Cnt));
  memset(a, 0, sizeof(a));
  memset(f, 0, sizeof(f));
  n = RD(), m = RD(), A = RD(), L = RD(), R = RD();
  CntNull = FinalAns = 0;
  Ans = 1;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      for (register unsigned j(1); j <= m; ++j) {
        ++Cnt[a[i][j] = RD()];
        Pos[a[i][j]][0] = i;
        Pos[a[i][j]][1] = j;
      }
    }
    while (!Cnt[A--]);
    ++A;
    g[A + 1] = 0;
    for (register unsigned i(A), x, y, z; i; --i) {
      g[i] = g[i + 1];
      if(!Cnt[i]) continue;
      x = Pos[i][0], y = Pos[i][1], z = 0;
      if(a[x - 1][y] > i) ++z;
      if(a[x][y - 1] > i) ++z;
      if(a[x + 1][y] > i) ++z;
      if(a[x][y + 1] > i) ++z;
      if(Cnt[i] == 2) {
        ++g[i];
        if(a[x - 1][y] == i) {
          x = x - 1;
          if(a[x - 1][y] > i) ++g[i];
          if(a[x][y - 1] > i) ++g[i];
          if(a[x][y + 1] > i) ++g[i];
        } else {
          y = y - 1;
          if(a[x - 1][y] > i) ++g[i];
          if(a[x][y - 1] > i) ++g[i];
          if(a[x + 1][y] > i) ++g[i];
        }
      }
      g[i] += z;
      if(Cnt[i] == 1) {
        Ans = (unsigned long long)Ans * z % MOD;
      }
    }
    for (register unsigned i(1); i <= A; ++i) {
      if(!Cnt[i]) Stack[++CntNull] = g[i];
    }
    R = min(A, R);
    L -= A - CntNull, R -= A - CntNull;
    if(L > 0x3f3f3f3f) L = 0;
    f[0] = 1;
    for (register unsigned i(1); i <= CntNull; ++i)
      for (register unsigned j(min(R, i)); j; --j)
        f[j] = (f[j] + f[j - 1] * Stack[i]) % MOD;
    for (register unsigned i(L); i <= R; ++i) {
      FinalAns += f[i];
      if(FinalAns >= MOD) FinalAns -= MOD;
    }
    FinalAns = FinalAns * Ans % MOD;
    printf("%u\n", FinalAns);
  }
  return Wild_Donkey;
}
/*
2 2 4 2 4
1 2
3 3
*/
