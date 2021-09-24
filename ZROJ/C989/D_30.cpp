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
const unsigned long long Mod(998244353);
unsigned Mx[3005][3005], Mn[3005][3005], f[3005];
unsigned m, n, Pos, Cnt(0);
unsigned A, B, C, D, t;
char flg(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) Mx[i][i] = Mn[i][i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(i + 1); j <= n; ++j) {
      Mx[i][j] = max(Mx[i][j - 1], Mx[j][j]);
      Mn[i][j] = min(Mn[i][j - 1], Mn[j][j]);
    }
  }
  f[0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= i; ++j) {
      flg = 0;
      for (unsigned k(j); k < i; ++k) {
        if(Mx[j][k] < Mn[k + 1][i]) {flg = 1; break;}
      }
      if(!flg) {f[i] += f[j - 1];if(f[i] >= Mod) f[i] -= Mod;}
    }
  }
  printf("%llu\n", f[n]);
  //  }
  // system("pause");
  return Wild_Donkey;
}
