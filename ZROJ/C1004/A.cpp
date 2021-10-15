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
unsigned a[100005], b[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline char Judge () {
  memcpy(a, b, (n + 2) << 2);
  for (unsigned i(2); i < n; ++i) {
    if(a[i] > C) Tmp = a[i] - C, a[i] = C, a[i - 1] += Tmp, a[i + 1] += Tmp;
    if(a[i - 1] > C) return 0;
  }
  if(a[n] > C) return 0;
  return 1;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) b[i] = RD();
  A = 0, B = 1000000000;
  while (A ^ B) {
    C = (A + B) >> 1;
    if (Judge()) B = C;
    else A = C + 1; 
  }
  printf("%u\n", A);
//  }
  return Wild_Donkey;
}

