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
unsigned long long Hash[1000005], Sum[1000005], Seed(1238476);
unordered_map<unsigned long long, unsigned> Map;
unsigned Two[1000005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Mn(unsigned &x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned long long Random() {
  return Seed = Seed * 998244353 + 19260817;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Two[0] = 1;
  for (unsigned i(1); i <= 1000000; ++i) Hash[i] = Random();// printf("%llu ", Hash[i]);
  for (unsigned i(1); i <= n; ++i) Sum[i] += Hash[RD()];
  for (unsigned i(1); i <= n; ++i) Sum[i] -= Hash[RD()];
  for (unsigned i(1); i <= n; ++i) ++Map[Sum[i] += Sum[i - 1]];
  for (unsigned i(1); i <= n; ++i) Mn(Two[i] += (Two[i - 1] << 1));
  for (auto i:Map) Mn(Ans += Two[i.second]);
  Mn(Ans += (Mod - Map.size() + 1));
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

