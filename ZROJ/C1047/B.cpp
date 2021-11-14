#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
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
const unsigned long long Mod(1000000007);
unsigned long long Inv[2005], Sum(0), Tmp(0), Row[1005], Col[1005];
unsigned a[1005][1005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
signed main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
  n = RD(), m = RD();
  Inv[0] = Inv[1] = 1;
  for (unsigned i(2); i <= n + m; ++i) Inv[i] = ((Mod - ((Mod / i) * Inv[Mod % i]) % Mod)) % Mod;
//  for (unsigned i(1); i <= n + m; ++i) printf("Inv %u = %llu\n", i, Inv[i]);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j) {
      Sum += (a[i][j] = RD());
    }
  }
  Sum = (Sum % Mod) * Inv[n + m - 1] % Mod;
  if(n == 1) {
    for (unsigned i(2); i <= m; ++i) if(a[1][i] ^ a[1][i - 1]) {printf("-1\n");return 0;}
    printf("1\n");
    for (unsigned i(1); i < m; ++i) putchar('0'), putchar(' ');
    printf("%u\n", Sum);
    return 0;
  }
  if(m == 1) {
    for (unsigned i(2); i <= n; ++i) if(a[i][1] ^ a[i - 1][1]) {printf("-1\n");return 0;}
    printf("1\n");
    for (unsigned i(1); i < n; ++i) putchar('0'), putchar(0x0A);
    printf("%u\n", Sum);
    return 0;
  }
  for (unsigned i(1); i <= n; ++i) {
    Tmp = 0;
    for (unsigned j(1); j <= m; ++j) Tmp += a[i][j];
    Tmp = Tmp + Mod - Sum;
    Row[i] = (Tmp % Mod) * Inv[m - 1] % Mod;
  }
  for (unsigned i(1); i <= m; ++i) {
    Tmp = 0;
    for (unsigned j(1); j <= n; ++j) Tmp += a[j][i];
    Tmp = Tmp + Mod - Sum;
    Col[i] = (Tmp % Mod) * Inv[n - 1] % Mod;
  }
  putchar('1'), putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j) printf("%llu ", (Mod + Row[i] + Col[j] - a[i][j]) % Mod);
    putchar(0x0A);
  }
  return Wild_Donkey;
}
/*
2 6
17 25 17 25 24 17
30 30 33 34 30 33
*/
