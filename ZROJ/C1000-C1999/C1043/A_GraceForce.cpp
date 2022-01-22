#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
map<pair<unsigned, unsigned>, unsigned> List;
unsigned m, n, Now;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline char Judge (unsigned x, unsigned L, unsigned R) {
//  printf("Judge [%u, %u] as %u\n", L, R, x);
  if(R > x) return 0;
  if((!L) && (R == x)) return 1;
  if(L > (x >> 1)) return Judge((x - 1) >> 1, L - (x >> 1) - 1, R - (x >> 1) - 1);
  if(R <= (x >> 1)) return Judge(x >> 1, L, R);
  return 0;
}
inline void Calc(unsigned L, unsigned R) {
//  printf("Calc [%u, %u]\n", L, R);
  unsigned Top(min(n, ((L - 1) << 1) + 1));
  for (unsigned i(R); i <= Top; ++i) {
    if(Judge(i, L, R)) {Ans = i; return;}
  }
}
signed main() {
//  freopen("A4.in", "r", stdin);
//  freopen("A.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//    A = RD(), B = RD(), n = RD(), Calc(0, A, B);
//    if((!Flg) || (Ans >= n)) printf("-1\n");
//    else printf("%u\n", Ans);
//  }
  n = 2000000000;
  for (unsigned i(0); i <= 10; ++i) {
    for (unsigned j(1); j <= 10; ++j)
      Ans = 0, Calc(i * 10000000, i * 10000000 + j * 1000000), printf("%u ", Ans);
    putchar(0x0A);
  }
  return Wild_Donkey;
}
/*
2
0 5 10
6 7 10
*/
