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
const unsigned long long Mod(100000000);
unsigned long long f[13][12][4100], Ans;
unsigned a[15], m, n, n2, Cnt(0), A, B, C, D, t, Tmp(0);
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), n2 = (1 << m); 
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      a[i] <<= 1, a[i] += RD();
    }
  }
  f[0][m - 1][0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned k(0); k < n2; ++k) {
      if(!(k & 1)) {f[i][0][k] = f[i - 1][m - 1][k ^ 1] + f[i - 1][m - 1][k]; if(f[i][0][k] >= Mod) f[i][0][k] -= Mod;}
      if(a[i] & k & 1) f[i][0][k] = f[i - 1][m - 1][k ^ 1];
//        printf("f[%u][%u][%u] = %llu\n", i, 0, k, f[i][0][k]);
    }
    for (register unsigned j(1); j < m; ++j) {
      for (register unsigned k(0); k < n2; ++k) {
        if((k & (1 << j)) && (k & (1 << (j - 1)))) continue;
        if(a[i] & k & (1 << j)) f[i][j][k] = f[i][j - 1][k ^ (1 << j)];
        if(!(k & (1 << j))) {f[i][j][k] = f[i][j - 1][k ^ (1 << j)] + f[i][j - 1][k]; if(f[i][j][k] >= Mod) f[i][j][k] -= Mod;}
//        printf("f[%u][%u][%u] = %llu\n", i, j, k, f[i][j][k]);
      }
    }
  }
  for (unsigned i(0); i < n2; ++i) Ans += f[n][m - 1][i];
  printf("%llu\n", Ans % Mod);
//  }
  return Wild_Donkey;
}

