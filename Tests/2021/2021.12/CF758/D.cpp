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
const unsigned long long Mod(998244353);
unsigned long long Ans(1), Tmp, Fac[200005], Inv[200005], Bin[200005];
unsigned m, n, LB, LW, RB, RW;
unsigned A, B, C, D, t;
unsigned Cnt(0);
char IOT[5];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  Bin[0] = Fac[0] = 1;
  m = ((n = RD()) << 1), A = B = C = D = LB = LW = RB = RW = 0;
  for (unsigned i(1); i <= m; ++i) { Bin[i] = Bin[i - 1] << 1; if (Bin[i] >= Mod) Bin[i] -= Mod; }
  for (unsigned i(1); i <= m; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[m] = 1, A = Mod - 2, Tmp = Fac[m];
  while (A) { if (A & 1) Inv[m] = Inv[m] * Tmp % Mod; A >>= 1, Tmp = Tmp * Tmp % Mod; }
  for (unsigned i(m - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  // printf("%llu %llu %llu", Inv[1], Inv[2], Inv[3]);
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", IOT + 1);
    if (IOT[1] == '?') ++A;
    if (IOT[2] == '?') ++A;
    if (IOT[1] == 'W') ++B, ++LW;
    if (IOT[2] == 'W') ++B, ++RW;
    if (IOT[1] == 'B') ++LB;
    if (IOT[2] == 'B') ++RB;
    if (IOT[1] == IOT[2])
      if ((IOT[1] == 'W') || (IOT[1] == 'B')) ++C;
      else ++D;
  }
  if (B > n) { printf("0\n");return Wild_Donkey; }
  if (n > A + B) { printf("0\n");return Wild_Donkey; }
  Ans = (Fac[A] * Inv[n - B] % Mod) * Inv[A + B - n] % Mod;
  if (!C) {
    Ans += Mod - Bin[D];
    if (!(LW | RB)) ++Ans;
    if (!(LB | RW)) ++Ans;
    if (Ans >= Mod) Ans -= Mod;
    if (Ans >= Mod) Ans -= Mod;
  }
  printf("%llu\n", Ans);
  // system("pause");
  return Wild_Donkey;
}