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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Have[10005][10005];
signed main() {
  freopen("B.in", "r", stdin);
  freopen("B.ans", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    for (unsigned j(0); ((A + j) <= n && (B - j)); ++j) Have[A + j][B - j] = 1;
    for (unsigned j(0); ((B + j) <= n && (A - j)); ++j) Have[A - j][B + j] = 1;
    for (unsigned j(0); ((A + j) <= n && ((B + j) <= n)); ++j) Have[A + j][B + j] = 1;
    for (unsigned j(0); ((B - j) && (A - j)); ++j) Have[A - j][B - j] = 1;
  }
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) if(!Have[i][j]) ++Ans;
//  for (unsigned i(1); i <= n; ++i) {
//    for (unsigned j(1); j <= n; ++j) putchar(Have[i][j] ? '1' : '0');
//    putchar(0x0A);
//  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

