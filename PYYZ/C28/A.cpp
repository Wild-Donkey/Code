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
unsigned long long Ans(0);
unsigned z[10000005], m, n(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char a[10000005];
//  inline void Clr() {}
signed main() {
  freopen("A.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 10000002, stdin);
  while (a[n + 1] >= 'a') ++n;
  // printf("%u %s", n, a + 1);
  z[1] = n;
  for (unsigned i(2), j(1), k(0); i <= n; ++i) {
    if (i >= j + k) {
      j = i, k = 0;
      while (a[k + 1] == a[j + k]) ++k;
      z[i] = k; continue;
    }
    unsigned To(i - j + 1);
    if (To + z[To] - 1 < k) { z[i] = z[To]; continue; }
    j = i, k = k - To + 1;
    while (a[k + 1] == a[j + k]) ++k;
    z[i] = k;
  }
  for (unsigned i(1); i <= n; ++i) Ans += z[i];
  // for (unsigned i(1); i <= n; ++i) printf("%u ", z[i]); putchar(0x0A);
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}