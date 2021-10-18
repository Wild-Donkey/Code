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
unsigned a[2000005], m, n, n2;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  
  n2 = (((n = RD()) + 1) >> 1), m = RD();
  if (n + (n >> 1) <= m) {printf("-1\n"); return 0;}
  if(!m) {printf("-1\n");return 0;}
  for (unsigned i(0); i < n2; ++i) a[i + 1] = a[((n ^ 1) & 1) + n + n2 + i] = (i << 1) ^ 1;
  for (unsigned i(n >> 1); i; --i) a[n2 + (i << 1)] = a[n2 + (i << 1) - 1] = (i << 1);
  for (unsigned i(n << 1); i; --i) printf("%u ", a[i]);
  putchar(0x0A);
//  }
  return Wild_Donkey;
}

