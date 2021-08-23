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
#define lowbit(x) (x)&(~((x) - 1))
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
unsigned Log[4500000], N, c[105][105], f[4500000], m, n, Cnt(0), A, B, C, D, t, Ans(0x3f3f3f3f), Tmp(0);
char Flg(0);
inline void Clr() {}
inline unsigned Count (unsigned x) {
  register unsigned y(0);
  while (x) {
    x ^= lowbit(x), ++y;
  }
  return y;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = n - RD(), N = (1 << n) - 1; 
  for (register unsigned i(0); i < n; ++i) {
    for (register unsigned j(0); j < n; ++j) {
      c[i][j] = RD();
    }
  }
  for (register unsigned i(1), j(0); j <= n; ++j, i <<= 1) {
    Log[i] = j;
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (register unsigned i(1), Tmp, Lbt; i <= N; ++i) {
    Tmp = i, Lbt = lowbit(Tmp);
    while (Tmp) {
      register unsigned j(i ^ Lbt), Tmpj((j ^ N) ^ Lbt), Lbtj = lowbit(Tmpj), Min(0x3f3f3f3f);
//      printf("i = %u j = %u\n", i, Tmpj);
      while (Tmpj) {
//        printf("Li %u Lj %u\n", Lbt, Lbtj);
        Min = min(Min, c[Log[Lbt]][Log[Lbtj]]);
        Tmpj ^= Lbtj, Lbtj = lowbit(Tmpj);
      }
      f[i] = min(f[i], f[j] + Min);
      Tmp ^= Lbt, Lbt = lowbit(Tmp);
    }
//    printf("f[%u] = %u\n", i, f[i]);
  }
  for (register unsigned i(0); i <= N; ++i) {
//    printf("Cnt(%u) = %u\n", i, Count(i));
    if(Count(i) == m) {
//      printf("f[%u] = %u\n", i, f[i]);
      Ans = min(Ans, f[i]);
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

