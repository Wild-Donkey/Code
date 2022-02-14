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
const unsigned Mod(1000000007);
unsigned f[1005][1005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char a[1005], IO[4];
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(2); i <= n; ++i) scanf("%s", IO), a[i] = (IO[0] == '<');
  f[1][0] = 1;
  for (unsigned i(2); i <= n; ++i) {
    unsigned Tmp(0);
    if (a[i]) for (unsigned j(i - 2); ~j; --j) Tmp += f[i - 1][j], Mn(Tmp), f[i][j] += Tmp, Mn(f[i][j]);
    else for (unsigned j(1); j < i; ++j) Tmp += f[i - 1][j - 1], Mn(Tmp), f[i][j] += Tmp, Mn(f[i][j]);
    // printf("%u\n", Tmp);
  }
  for (unsigned i(0); i < n; ++i) Ans += f[n][i], Mn(Ans);
  printf("%u\n", Ans);
  //  }
  system("pause");
  return Wild_Donkey;
}