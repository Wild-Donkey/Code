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
#define up 1000000000000000
using namespace std;
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long Bin[10005], m, n1, n2, Lg(1), A;
unsigned Cnt(0), Ans(0), Tmp(0);
char a1[20005], a2[20005];
signed main() {
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n1 = RD(), n2 = RD(), m = RD(), Bin[0] = n1 + n2;
  scanf("%s%s", a1 + 1, a1 + n1 + 1);
  for (unsigned i(1); i <= n2; ++i) a2[i] = a1[n1 + i];
  for (unsigned i(1); i <= n1; ++i) a2[n2 + i] = a1[i];
//  for (unsigned i(0); i <= n1 + n2; ++i) putchar(a[i]);
//  putchar(0x0A);
  for (; Bin[Lg - 1] < up; ++Lg) Bin[Lg] = Bin[Lg - 1] << 1; --Lg;
//  for (unsigned i(0); i <= Lg; ++i) printf("Bin%u %llu\n", i, Bin[i]);
  for (; m; --m) {
    A = RD(), Cnt = 0;
    for (unsigned i(Lg); ~i; --i) if(A > Bin[i]) A -= Bin[i], ++Cnt;
    putchar((Cnt & 1) ? a2[A] : a1[A]), putchar(0x0A);
  }
//  }
  return Wild_Donkey;
}

