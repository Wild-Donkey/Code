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
const unsigned long long Mod(998244353);
unsigned long long Ans(0), k;
unsigned a[200005], b[200005], m, n, q;
unsigned CntC, CntR, A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Flg(0);
bitset<200005> AvaR, AvaC;
inline void Clr() {
  for (unsigned i(1); i <= q; ++i) AvaR[a[i]] = AvaC[b[i]] = 0;
  memset(a, 0, (q + 1) << 2);
  memset(b, 0, (q + 1) << 2);
  n = RD(), m = RD(), k = RD(), q = RD();
  CntC = CntR = Cnt = 0;
  Ans = 1;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= q; ++i) a[i] = RD(), b[i] = RD();
    for (unsigned i(q); i; --i) {
      Flg = 0;
      if ((!AvaR[a[i]]) && (CntC ^ m)) AvaR[a[i]] = 1, ++CntR, Flg = 1;
      if ((!AvaC[b[i]]) && (CntR ^ n)) AvaC[b[i]] = 1, ++CntC, Flg = 1;
      if (Flg) ++Cnt;
    }
    while (Cnt) { if (Cnt & 1) Ans = Ans * k % Mod;  k = k * k % Mod, Cnt >>= 1; }
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}