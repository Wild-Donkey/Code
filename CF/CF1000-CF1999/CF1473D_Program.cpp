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
int Fr[200005], Bc[200005], MxF[200005], MnF[200005], MxB[200005], MnB[200005];
int Mx, Mn, Mid;
unsigned  m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char IO[200005];
inline void Clr() {
  n = RD(), m = RD(), Fr[0] = MxF[0] = MnF[0] = Bc[n + 1] = MxB[n + 1] = MnB[n + 1] = 0;
  scanf("%s", IO + 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      Fr[i] = Fr[i - 1] + ((IO[i] == '+') ? 1 : -1);
      MxF[i] = max(MxF[i - 1], Fr[i]);
      MnF[i] = min(MnF[i - 1], Fr[i]);
    }
    for (unsigned i(n); i; --i) {
      Bc[i] = Bc[i + 1] + ((IO[i] == '-') ? 1 : -1);
      MxB[i] = max(MxB[i + 1], Bc[i]);
      MnB[i] = min(MnB[i + 1], Bc[i]);
    }
    for (unsigned i(1); i <= m; ++i) {
      A = RD() - 1, B = RD() + 1;
      Mx = max(MxF[A], Fr[A] + MxB[B] - Bc[B]);
      Mn = min(MnF[A], Fr[A] + MnB[B] - Bc[B]);
      // printf("[%d, %d]\n", Mn, Mx);
      // printf("%d, %d %d\n", Fr[A], MnB[B], Bc[B]);
      printf("%d\n", Mx - Mn + 1);
    }
  }
  system("pause");
  return Wild_Donkey;
}