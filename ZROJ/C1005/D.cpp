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
#include <string>
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
unsigned long long Sum[200005], Ten[200005], f[200005];
unsigned long long Last(0), Pre(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[200005];
inline unsigned long long Num (const unsigned L, const unsigned R) {
  unsigned long long TmpN(Sum[R] - (Sum[L - 1] * Ten[R - L + 1] % Mod) + Mod);
  if(TmpN >= Mod) TmpN -= Mod;
  return TmpN;
}
signed main() {
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  scanf("%s", a + 1), Ten[0] = 1;
  for (unsigned i(1); i <= n; ++i) Ten[i] = (Ten[i - 1] * 10) % Mod;
  for (unsigned i(1); i <= n; ++i) Sum[i] = (Sum[i - 1] * 10 + (a[i] -= '0')) % Mod;
//  for (unsigned i(1); i <= n; ++i) {
//    for (unsigned j(i); j <= n; ++j) {
//      printf("Num[%u, %u] %llu\n", i, j, Num(i, j));
//    }
//  }
  for (unsigned i(1); i <= n; ++i) {
    Last = ((Pre * a[i]) + (Last * 10)) % Mod;
    f[i] = Num(1, i) + Last;
    if(f[i] >= Mod) f[i] -= Mod;
    Pre += f[i];
    if(Pre >= Mod) Pre -= Mod;
  }
  printf("%llu\n", f[n]);
//  }
  return Wild_Donkey;
}

