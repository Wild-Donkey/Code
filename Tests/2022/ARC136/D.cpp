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
unsigned a[1000005], b[1000005], m, n;
unsigned long long Ans(0);
unsigned A, B, C, D, t;
unsigned Cnt(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) ++a[b[i] = RD()];
  for (unsigned i(1); i <= 999999; ++i) if (i % 10) a[i] += a[i - 1];
  for (unsigned i(1); i <= 999999; ++i) if ((i / 10) % 10) a[i] += a[i - 10];
  for (unsigned i(1); i <= 999999; ++i) if ((i / 100) % 10) a[i] += a[i - 100];
  for (unsigned i(1); i <= 999999; ++i) if ((i / 1000) % 10) a[i] += a[i - 1000];
  for (unsigned i(1); i <= 999999; ++i) if ((i / 10000) % 10) a[i] += a[i - 10000];
  for (unsigned i(100000); i <= 999999; ++i) a[i] += a[i - 100000];
  for (unsigned i(1); i <= n; ++i) {
    // printf("%u %u\n", b[i], a[999999 - b[i]]);
    unsigned Tmp(b[i]);
    char Flg(0);
    while (Tmp) { if ((Tmp % 10) >= 5) Flg = 1; Tmp /= 10; }
    // printf("Flg %u\n", Flg);
    Ans += a[999999 - b[i]] + Flg - 1;
  }
  printf("%llu\n", Ans >> 1);
  //  }
//  system("pause");
  return Wild_Donkey;
}