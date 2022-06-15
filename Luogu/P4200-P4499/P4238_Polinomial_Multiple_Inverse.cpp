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
unsigned a[262150], b[262150], Two[20], m(1), n, Lgn(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void DIT(unsigned* f, unsigned Lg, unsigned long long w) {
  unsigned Len(Two[Lg]);
  unsigned long long Curw(1);
  for (unsigned i(1), j(2); i < Lg; ++i, j << 1) {
    for (unsigned k(0); k < Len; ++k, Curw = Curw * w % Mod) if (!(k & j)) {
      unsigned long long TmA(f[k]), TmB(f[k ^ j]);
      f[k] = TmA;
    }
  }
}
inline void DIF() {

}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Two[0] = 1;
  for (unsigned i(1); i < 20; ++i) Two[i] = (Two[i - 1] << 1);
  while (m < n) {

  }
  for (unsigned i(0); i < n; ++i) a[i] = RD();
  //  }
  //  system("pause");
  return Wild_Donkey;
}