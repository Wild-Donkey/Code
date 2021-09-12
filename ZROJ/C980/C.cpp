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
unsigned a[10005], m, n;
unsigned A, B, C, D, t, MOD(10000019);
unsigned Cnt(0), Tmp(0);
unsigned List[505], Hash[10000500][2];
void Insert(unsigned x) {
  unsigned TmpI(x % MOD);
  while (Hash[TmpI][0] && (Hash[TmpI][1] ^ x)) ++TmpI;
  ++Hash[TmpI][0], Hash[TmpI][1] = x;
}
unsigned Find(unsigned x) {
  unsigned TmpI(x % MOD);
  while (Hash[TmpI][0] && (Hash[TmpI][1] ^ x)) ++TmpI;
  return Hash[TmpI][0];
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(0); i < 29; ++i)
    for (unsigned j(i + 1); j <= 29; ++j)
      List[++Cnt] = (1 << i) | (1 << j);
  for (unsigned i(1); i <= n; ++i) Insert(RD());
  for (unsigned i(1); i <= m; ++i)
    for (unsigned j(1), k(RD()); j <= Cnt; ++j)
      Ans += Find(k ^ List[j]);
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}