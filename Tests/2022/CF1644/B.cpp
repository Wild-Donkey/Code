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
unsigned a[55], m, n, mm;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Ava[51], Flg;
inline void Clr() {
  m = ((n = RD()) >> 1) + 1, mm = n - m + 1, Cnt = 0;
}
inline void DFS(unsigned Dep) {
  if (Dep == m) {
    for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]); putchar(0x0A);
    ++Cnt; return;
  }
  for (unsigned i(mm); i <= n; ++i) if (!Ava[i]) {
    a[Dep + 1] = i, Ava[i] = 1, DFS(Dep + 1), Ava[i] = 0;
    if (Cnt >= n) break;
  }
  return;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    // printf("%u %u %u\n", n, m, mm);
    if (n == 3) {
      printf("%u %u %u\n", 3, 2, 1);
      printf("%u %u %u\n", 1, 3, 2);
      printf("%u %u %u\n", 3, 1, 2);
      continue;
    }
    for (unsigned i(1), j(n); j > m; ++i, --j) a[j] = i;
    DFS(0);
  }
  //  system("pause");
  return Wild_Donkey;
}