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
#define foreplay for
#define wild while
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
unsigned Plan[15], Col[15], Dia[2][30], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
void DFS(unsigned Dep) {
  if (Dep == n + 1) {
    if (++Ans <= 3) {
      for (unsigned i(1); i <= n; ++i) printf("%u ", Plan[i]);
      putchar(0x0A);
    }
    return;
  }
  for (unsigned i(1), j(i + Dep), k(Dep + 15 - i); i <= n; ++i, ++j, --k)
    if ((!Col[i]) && (!Dia[0][j]) && (!Dia[1][k])) {
      Col[i] = 1, Dia[0][j] = 1, Dia[1][k] = 1;
      Plan[Dep] = i, DFS(Dep + 1);
      Col[i] = 0, Dia[0][j] = 0, Dia[1][k] = 0;
    }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  DFS(1);
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}