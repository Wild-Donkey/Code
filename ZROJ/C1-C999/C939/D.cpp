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
unsigned Now(0), Ways(0), Q[1500005], Dist[1500005], Hd(0), Tl(0), m, N, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char Faq[104];
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD() - 1, m = RD(), N = (1 << m);
  memset(Dist, 0x3f, ((N + 1) << 2));
  for (register unsigned i(1), Tmpi(0); i <= n; ++i) {
    scanf("%s", Faq);
    Tmpi = 0;
    for (register unsigned j(0); j < m; ++j) {
      Tmpi <<= 1, Tmpi += Faq[j] - '0';
    }
    Dist[Q[++Tl] = Tmpi] = 0;
  }
  while (Hd < Tl) {
    Now = Q[++Hd];
    for (register unsigned i(0), Nowi(0); i < m; ++i) {
      Nowi = Now ^ (1 << i);
      if(Dist[Nowi] >= 0x3f3f3f3f) {
        Dist[Nowi] = Dist[Now] + 1;
        Q[++Tl] = Nowi;
        if(Dist[Nowi] > Ans) {
          Ans = Dist[Nowi];
          Ways = 1;
        } else {
          ++Ways;
        }
      }
    }
  }
  printf("%u %u\n", m - Ans, Ways);
//  }
  return Wild_Donkey;
}
/*
3 3
101
000

5 3
111
101
010
000

5 5
11001
10101
01010
10010
*/
