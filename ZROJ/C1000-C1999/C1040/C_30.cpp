#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
unsigned f[105][105], Ans[105], m, n, Size(1);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Clr() {
  memset(f, 0x3f, sizeof(f));
  n = RD(), m = RD();
}
inline void Prog(unsigned x, unsigned y) {
  if(!x) return;
  Ans[x] = f[x][y], Prog(x - 1, y / (f[x][y] - x + 1));
}
signed main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    f[0][1] = 0;
    for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j)
      for (unsigned k(1); k <= j; ++k) if((!(j % k)) && ((i + (j / k) - 1) >= f[i - 1][k]))
        f[i][j] = min(f[i][j], i + (j / k) - 1);
//    for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) printf("f %u %u = %u\n", i, j, f[i][j]);
    Prog(n, m);
    for (unsigned i(1); i < n; ++i) printf("%u ", Ans[i]);
    printf("%u\n", Ans[n]);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2 5
1 2
01
10
100

*/
