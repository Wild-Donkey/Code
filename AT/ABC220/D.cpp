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
const unsigned Mod(998244353);
unsigned f[100005][10], a[100005], To[15][15][2], n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(0); i < 10; ++i) 
    for (unsigned j(0); j < 10; ++j)
      To[i][j][0] = (i + j) % 10, To[i][j][1] = (i * j) % 10;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  f[1][a[1]] = 1;
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(0); j < 10; ++j) {
      f[i][To[j][a[i]][0]] += f[i - 1][j];
      f[i][To[j][a[i]][1]] += f[i - 1][j];
      if(f[i][To[j][a[i]][0]] >= Mod) f[i][To[j][a[i]][0]] -= Mod;
      if(f[i][To[j][a[i]][1]] >= Mod) f[i][To[j][a[i]][1]] -= Mod;
    }
//    for (unsigned j(0); j < 10; ++j) printf("f[%u][%u] = %u\n", i, j, f[i][j]);
  }
  for (unsigned i(0); i < 10; ++i) printf("%u\n", f[n][i]);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

