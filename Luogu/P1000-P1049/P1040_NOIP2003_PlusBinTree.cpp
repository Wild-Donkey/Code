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
unsigned long long f[33][33], Choi[33][33], Tmp;
unsigned m, n;
unsigned Cnt(0), Ans(0);
//  inline void Clr() {}
inline void DFS(unsigned x, unsigned y) {
  if (y < 1) return;
  printf("%u ", Choi[x][y]);
  // printf("%u %u : %u\n", x, y, Choi[x][y]);
  unsigned A(Choi[x][y] - x);
  DFS(x, A);
  DFS(Choi[x][y] + 1, y - A - 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) f[i][1] = RD(), Choi[i][1] = i, f[i][0] = 1;
  for (unsigned Len(2); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      for (unsigned len(Len - 1); ~len; --len) {
        Tmp = f[i][len] * f[i + len + 1][Len - len - 1] + f[i + len][1];
        if (f[i][Len] < Tmp) {
          f[i][Len] = Tmp, Choi[i][Len] = i + len;
        }
      }
    }
  }
  printf("%llu\n", f[1][n]);
  DFS(1, n);
  //  }
  // system("pause");
  return Wild_Donkey;
}