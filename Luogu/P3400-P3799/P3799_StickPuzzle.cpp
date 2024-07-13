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
const unsigned long long Mod(1000000007);
unsigned Cnt[5005], m, n;
unsigned A, B, C, D, t;
unsigned long long Ans(0), Sum(0);
unsigned long long Bnm(unsigned long long x) {
  return ((x * (x - 1)) >> 1) % Mod;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) ++Cnt[RD()];
  for (unsigned i(1); i <= 5000; ++i) {
    Sum = 0;
    if (!(i & 1)) Sum = Bnm(Cnt[i >> 1]);
    for (unsigned j((i - 1) >> 1); j; --j)
      Sum = (Sum + (unsigned long long)Cnt[j] * Cnt[i - j]) % Mod;
    Ans = (Ans + Bnm(Cnt[i]) * Sum) % Mod;
  }
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}