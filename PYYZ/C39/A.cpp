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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned Calc(int x, int y) {
  x = (x < 0) ? (-x) : x;
  y = (y < 0) ? (-y) : y;
  if (x > y) swap(x, y);
  // printf("Calc %u %u\n", x, y);
  if ((x << 1) > y) return ((x + y) % 3) ? 0x3f3f3f3f : ((x + y) / 3);
  return (y & 1) ? 0x3f3f3f3f : (((x & 1) ^ ((y >> 1) & 1)) ? 0x3f3f3f3f : (y >> 1));
}
inline void DFS(int x, int y, unsigned Dep) {
  unsigned Cur(Calc(x, y));
  if (Cur < 0x3f3f3f3f) { Ans = min(Ans, Dep + Cur); return; }
  if (Dep > 3) return;
  DFS(x + 1, y + 2, Dep + 1);
  DFS(x + 2, y + 1, Dep + 1);
  DFS(x + 1, y - 2, Dep + 1);
  DFS(x + 2, y - 1, Dep + 1);
  DFS(x - 1, y + 2, Dep + 1);
  DFS(x - 2, y + 1, Dep + 1);
  DFS(x - 1, y - 2, Dep + 1);
  DFS(x - 2, y - 1, Dep + 1);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD(), Ans = 0x3f3f3f3f;
    if (A > B) swap(A, B);
    DFS(A, B, 0);
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}