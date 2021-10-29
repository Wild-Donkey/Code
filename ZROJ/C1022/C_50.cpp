#include <algorithm>
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
#include <bitset>
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
unsigned long long Ans(0), Cced[100005];
unsigned long long Sum2[100005], Sum[100005], Cnt[100005];
unsigned a[100005], m, n;
int f[100005], Mu[100005];
unsigned CntP(0), Prime[20005];
unsigned A, B, C, D, t;
unsigned Tmp(0);
bitset<100005> Isnt;
inline void Pre () {
  Mu[1] = 1;
  for (unsigned i(2); i <= 100000; ++i) {
    if(!Isnt[i]) Prime[++CntP] = i, Mu[i] = -1;
    for (unsigned j(1); Prime[j] * i <= 100000 && j <= CntP; ++j) {
      Isnt[i * Prime[j]] = 1, Mu[i * Prime[j]] = -Mu[i];
      if(!(i % Prime[j])) {Mu[i * Prime[j]] = 0; break;}
    }
  }
  for (int i(1); i <= 100000; ++i) {
//    printf("Do %u\n", i);
    for (int j(sqrt(i)); j; --j) if(!(i % j)) {
//      printf("%u * %u = %u\n", j, (i / j),  i);
      f[i] += Mu[j] * i / j;
      if(j ^ (i / j)) f[i] += Mu[i / j] * j;
    }
//    printf("f%u = %d\n", i, f[i]);
  }
}
inline void Calc(unsigned x, unsigned Pos) {
//  printf("Calc %u %u\n", x, Pos);
  Cced[x] += Cnt[x] * (((n * n + n) >> 1) + Pos * Pos - Pos * (n + 1)) + Sum2[x] - Pos * Sum[x];
  ++Cnt[x], Sum[x] += Pos, Sum2[x] += Pos * Pos;
}
inline void Prt(){
  printf("%llu\n", Ans);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Pre();
//  for (unsigned i(1); i <= 100; ++i) printf("%d ", Mu[i]);
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(sqrt(a[i])); j; --j) if(!(a[i] % j)) {
      Calc(j, i);
      if(j ^ (a[i] / j)) Calc(a[i] / j, i);
    }
  }
  for (unsigned i(1); i <= 100000; ++i) {
    Ans += Cced[i] * f[i];
  }
  Prt();
  //  }
  //  system("pause");
  return Wild_Donkey;
}

