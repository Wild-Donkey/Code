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
const unsigned long long Mod(1000000007);
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
unsigned n;
char a[1005][1005];
unsigned Nm[1005][1005], Cnt[1005][1005];
unsigned long long N(0), Ans1(0), Ans2(0);
unsigned Low[1005], Stack[1005], *Top(Stack);
unsigned long long Calc() {
  unsigned long long Rt(0);
  memset(Low, 0, (n + 1) << 2);
  for (unsigned i(1); i <= n; ++i) {
    Top = Stack;
    for (unsigned j(1); j <= n; ++j) {
      if (!a[i][j]) {
        Low[j] = i, Cnt[i][j] = 0;
        while (Top > Stack) --Top;
        *(++Top) = j;
        // printf("%u ", Cnt[i][j]);
        continue;
      }
      while (Top > Stack && Low[j] > Low[*Top]) --Top;
      if (Top > Stack)
        Cnt[i][j] = Cnt[i][*Top] + (i - Low[j]) * (j - *Top);
      else
        Cnt[i][j] = j * (i - Low[j]);
      *(++Top) = j;
      Rt += Cnt[i][j];
      // printf("%u ", Cnt[i][j]);
    }
    // putchar(0x0A);
  }
  // printf("Calc %llu\n", Rt);
  return Rt % Mod;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  N = ((n * (n + 1)) >> 1), N = N * N % Mod;
  // printf("%llu\n", N);
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(1); j <= n; ++j) Nm[i][j] = RD();
  for (unsigned K(31), k(1); K; --K, k <<= 1) {
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(1); j <= n; ++j) a[i][j] = (Nm[i][j] & 1), Nm[i][j] >>= 1;
    Ans1 = (Ans1 + k * Calc()) % Mod;
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(1); j <= n; ++j) a[i][j] ^= 1;
    Ans2 = (Ans2 + (N + Mod - Calc()) * k) % Mod;
  }
  printf("%llu %llu\n", Ans1, Ans2);
  //  }
  //  system("pause");
  return Wild_Donkey;
}