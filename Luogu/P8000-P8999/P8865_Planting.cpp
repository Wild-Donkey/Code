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
#define foreplay for
#define wild while
using namespace std;
const unsigned long long Mod(998244353);
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
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
char a[1005][1005];
unsigned Len[1005], m, n;
unsigned A, B, t, c, f;
unsigned Cnt(0), Tmp(0);
unsigned long long C(0), F(0);
inline void Clr() {
  n = RD(), m = RD(), c = RD(), f = RD();
  C = F = 0;
  memset(Len, 0, sizeof(Len));
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD(), RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      scanf("%s", a[i] + 1);
      for (unsigned j(m); j; --j) a[i][j] -= '0';
    }
    for (unsigned j(m); j; --j) {
      unsigned long long SumC(0), SumF(0);
      unsigned TmpC(0), TmpF(0), Dep(0);
      for (unsigned i(n); i; --i) {
        if (a[i][j]) {
          Len[i] = Dep = TmpC = TmpF = 0, SumC = SumF = 0;
          continue;
        }
        Len[i] = Len[i] + 1;
        Dep = Dep + 1;
        if (Len[i] > 1) {
          C = (C + (Len[i] - 1) * SumC) % Mod;
          F = (F + (Len[i] - 1) * SumF) % Mod;
        }
        Mn(SumC += TmpC), TmpC = 0;
        Mn(SumF += TmpF), TmpF = 0;
        if (Len[i] > 1) {
          TmpC = Len[i] - 1;
          TmpF = (Len[i] - 1) * (Dep - 1);
        }
      }
      // printf("%llu %llu\n", F, C);
    }
    printf("%llu %llu\n", c ? C : 0, f ? F : 0);
  }
  //  system("pause");
  return Wild_Donkey;
}