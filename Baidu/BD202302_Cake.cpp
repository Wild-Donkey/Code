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
#define Lbt(x) (((~(x)) + 1) & (x))
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
unsigned a[20][20], Log[32768], BC[32768], m, n, N;
unsigned A, B(0), C, D, t;
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0);
//  inline void Clr() {}
inline unsigned Sum(unsigned Up, unsigned Down, unsigned Left, unsigned Right) {
  return a[Down][Right] - a[Up - 1][Right] - a[Down][Left - 1] +
         a[Up - 1][Left - 1];
}
inline char CheckLine(unsigned Cut, unsigned x) {
  for (unsigned i(1); i <= n; ++i) {
    unsigned Last(0);
    for (unsigned j(Cut), Cur; j; j -= Lbt(j)) {
      Cur = 1 + Log[Lbt(j)];
      if (Sum(i, i, Last + 1, Cur) > x) return 0;
      Last = Cur;
    }
    if (Sum(i, i, Last + 1, n) > x) return 0;
  }
  return 1;
}
inline unsigned Check(unsigned Cut, unsigned x) {
  if (!CheckLine(Cut, x)) return 0x3f3f3f3f;
  // printf("Done %u\n", x);
  unsigned VLast(0), Tot(0);
  for (unsigned i(2); i <= n; ++i) {  // Up to Down
    unsigned HLast(0);
    for (unsigned j(Cut), Cur; j; j -= Lbt(j)) {
      Cur = 1 + Log[Lbt(j)];
      // printf("j %u Cur %u VL %u\n", j, Cur, HLast);
      if ((VLast != i - 1) && (Sum(VLast + 1, i, HLast + 1, Cur) > x)) {
        ++Tot, VLast = i - 1;
        break;
      }
      HLast = Cur;
    }
    if ((VLast != i - 1) && (Sum(VLast + 1, i, HLast + 1, n) > x)) {
      ++Tot, VLast = i - 1;
    }
  }
  return Tot;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), N = (1 << (n - 1));
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(1); j <= n; ++j)
      B = max(B, A = RD()), a[i][j] = a[i][j - 1] + A;
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(1); j <= n; ++j) a[i][j] += a[i - 1][j];
  for (unsigned i(2); i < N; ++i) Log[i] = Log[i >> 1] + 1;
  for (unsigned i(0); i < N; ++i) {
    BC[i] = BC[i >> 1] + (i & 1);
    unsigned L(B), R(225000), Mid;
    while (L ^ R) {
      Mid = ((L + R) >> 1);
      if (BC[i] + Check(i, Mid) <= m)
        R = Mid;
      else
        L = Mid + 1;
    }
    // printf("Cut %u Ans %u\n", i, L);
    Ans = min(Ans, L);
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
3 1
2 2 2
1 1 1
1 1 1
3 1
1 1 2
1 1 2
1 1 2
5 4
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
5 5 5 5 5
*/