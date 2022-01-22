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
unsigned long long List[1000005], Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Pos[500005];
char a[500005];
inline void Clr() {
  n = RD(), Ans = 0, Cnt = 0;
  scanf("%s", a + 1);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  for (unsigned i(1); i <= 1000000; ++i) List[i] = List[i - 1] + ((i + 1) >> 1);
//  for (unsigned i(1); i <= 100; ++i) printf("%u\n", List[i]);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) if(a[i] ^ '0') Pos[++Cnt] = i;
    Ans += List[(Pos[1] - 1) << 1] >> 1;
    for (unsigned i(2), j; i <= Cnt; ++i)
      j = Pos[i] - Pos[i - 1] - 1, Ans += List[j];
    Ans += List[(n - Pos[Cnt]) << 1] >> 1;
    printf("Case #%u: %llu\n", T, Ans);
  }
  return Wild_Donkey;
}

