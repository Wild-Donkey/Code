  #include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
unsigned a[100005], m, n;
unsigned Fa[100005], Stack[100005], STop(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Col[100005], Ava[100005];
inline unsigned long long GCD(unsigned long long x, unsigned long long y) {
  unsigned long long TmpD;
  while (y) TmpD = x, x = y, y = TmpD % y;
  return x;
}
inline unsigned Find (unsigned x) {
  char TmpC(0);
  while (Fa[x] ^ x) Stack[++STop] = x, x = Fa[x];
  while (STop) TmpC ^= Col[Stack[STop]], Col[Stack[STop]] = TmpC, Fa[Stack[STop--]] = x;
  return x;
}
inline void Link (unsigned x, unsigned y) {
  if(Find(x) ^ Find(y)) Col[Fa[x]] = (1 ^ (Col[x] ^ Col[y])), Ava[Fa[y]] |= Ava[Fa[x]], Fa[Fa[x]] = Fa[y];
  else if(Col[x] == Col[y]) Ava[Fa[x]] = 1;// printf("%u %u Col %u\n", x, y, Col[x]);
}
inline void Calc (unsigned x, unsigned y, unsigned long long z) {
  if(Find(x) ^ Find(y)) {printf("0\n"); return;}
//  printf("%u Fa %u Col %u, %u Fa %u Col %u\n", x, Fa[x], Col[x], y, Fa[y], Col[y]);
  if(Ava[Fa[x]]) {printf("0\n"); return;}
  if(Col[x] ^ Col[y]) putchar('-');
  unsigned long long TmpV(a[x] * z), TmpI(a[y]), TmpG(GCD(TmpV, TmpI));
  TmpV /= TmpG, TmpI /= TmpG;
  printf("%llu/%llu\n", TmpV, TmpI);
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) Fa[i] = i;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    switch (A) {
      case (1) : {
        a[B] = C;
        break;
      }
      case (2) : {
        if(B ^ C) Link(B, C);
        break;
      }
      case (3) : {
        D = RD();
        Calc(B, C, D);
        break;
      }
    }
//    printf("Col\n");
//    for (unsigned i(1); i <= n; ++i) printf("%u ", Col[i]);
//    putchar(0x0A);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
4 6
2 6 5 3
2 1 2
2 3 4
2 1 3
2 2 4
3 1 3 3
3 1 4 2
*/
