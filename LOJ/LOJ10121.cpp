#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[200005], f[200005][20], Log[200005], Bin[20], m, n, A, B, L, R, Mid, t, Ans(0), Tmp(0);
char Cnt[2000005];
inline void Clr() {}
inline unsigned Qry(unsigned x, unsigned y) {
  register unsigned Tmp(Log[y - x + 1]);
  return max(f[x][Tmp], f[y - Bin[Tmp] + 1][Tmp]);
}
inline char Judge(unsigned x) {
  return (Qry(A, B - x + 1) >= x);
}
int main() {
//  freopen("LOJ10121_1.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(); 
  for (register unsigned i(1); i <= n; ++i)
    a[i] = RDsg() + 1000000;
  for (register unsigned i(1), j(1); i <= n; ++i) {
    while (!Cnt[a[j]]) ++Cnt[a[j++]];
    f[i][0] = j - i; 
    --Cnt[a[i]];
  }
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j) 
    Log[i] = j, Bin[j] = i;
  for (register unsigned i(3); i <= n; ++i)
    Log[i] = max(Log[i], Log[i - 1]);
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j)
    for (register unsigned k(1); k + (i << 1) <= n + 1; ++k)
      f[k][j + 1] = max(f[k][j], f[k + i][j]);
  for (register unsigned i(1); i <= m; ++i) {
    A = RD() + 1, B = RD() + 1;
    L = 1, R = B - A + 1;
    while (L ^ R) {
      Mid = ((L + R + 1) >> 1);
      if(Judge(Mid)) L = Mid;
      else R = Mid - 1;
    }
    printf("%u\n", L);
  }
  return Wild_Donkey;
}

