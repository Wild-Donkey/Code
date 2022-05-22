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
#define Lbt(x) (((~(x))+1)&(x)) 
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
unsigned a[1000005], Tr[1000005], n;
unsigned long long Fac(1), Ans(1);
inline void Add(unsigned x) {while(x <= n) ++Tr[x], x += Lbt(x);}
inline unsigned Qry(unsigned x) {
  unsigned Rt(0);
  while (x) Rt += Tr[x], x -= Lbt(x);
  return Rt;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(n), j(1); i; --i, ++j)
    Ans = (Ans + Qry(a[i]) * Fac) % Mod, Add(a[i]), Fac = Fac * j % Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

