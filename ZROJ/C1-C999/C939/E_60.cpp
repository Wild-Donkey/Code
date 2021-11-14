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
#define Lowbit(x) ((x)&((~(x))+1)) 
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
const unsigned long long _1(1);
const unsigned long long MOD(998244353);
unsigned f[70005], m, n, N, Cnt(0), A, B, C, D, t, Ans(0);
unsigned long long Tmp(0), List[100005];
inline void Print(unsigned long long x) {
  for (register unsigned i(0); i < (n << 1); ++i){
    putchar(((_1 << i) & x) ? '1' : '0'); 
  }
  putchar('\n');
  return;
}
inline unsigned long long To(unsigned long long x, unsigned long long y) {
  register unsigned long long L;
  while (x) {
    L = Lowbit(x); 
    if(y & L) {
      y ^= (L | (L << 1));
    } else {
      y ^= L;
    }
    x ^= L;
  }
  return y;
}
unsigned Ans8[70] = {0, 93, 8649, 804357, 69214125, 112083636, 213453520, 809812580, 188050035, 477063355, 850898529, 35219241, 307515998, 706132945, 927739308, 824492602, 209069661, 455485934, 83153968, 899084763, 24004137, 91973932, 371377882, 867221422, 958079829, 625859287, 415129069, 705640832, 593093251, 673002824, 528839686, 497928375, 357631902, 563997465, 840065963, 499164109, 730913293, 70374125, 541521928, 361751373, 572725556, 743972069, 598729144, 137289737, 980579798, 284153995, 397542183, 985374208, 811482227, 357658360, 596769980, 373919314, 712588041, 897470897, 602075230, 668019421, 580949849, 425155212, 577434159, 871327693, 174840186, 382383295, 282033847, 847049313, 742770833};
int main() {
//  freopen("E.in", "r", stdin);
//  freopen("E.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  if(n > m) swap(n, m);
  if(n == 8) {
    printf("%u\n", Ans8[m]);
    return 0;
  }
  for (register unsigned i(0); i < n; ++i) {
    List[++Cnt] = (_1 << i);
  }
  for (register unsigned i(0); i < n; ++i) {
    for (register unsigned j(i + 1); j < n; ++j) {
      List[++Cnt] = (_1 << i) | (_1 << j);
    }
  }
  for (register unsigned i(0); i < n; ++i) {
    for (register unsigned j(i + 1); j < n; ++j) {
      for (register unsigned k(j + 1); k < n; ++k) {
        List[++Cnt] = (_1 << i) | (_1 << j) | (_1 << k);
      }
    }
  }
  for (register unsigned i(1); i <= Cnt; ++i) {
    for (register unsigned j(n - 1); j; --j) {
      if((_1 << j) & List[i]) {
        List[i] ^= (_1 << j);
        List[i] ^= (_1 << (j << 1));
      }
    }
//    printf("%u ", i);
//    Print(List[i]);
  }
//  printf("%u\n", Cnt);
  N = 1 << (n << 1);
  f[0] = 1;
  for (register unsigned i(1); i <= m; ++i) {
    for (register unsigned long long k(N - 1); k < 0x3f3f3f3f3f3f3f3f; --k) {
      for (register unsigned j(1); j <= Cnt; ++j) {
        if((List[j] & k) & (((List[j] << 1) & k) >> 1)) {
          continue;
        }
        Tmp = To(List[j], k);
        f[Tmp] += f[k];
        if(f[Tmp] >= MOD) f[Tmp] -= MOD;
//        print"%u %u %u\n", i, j, k);
//        Print(k), Print(Tmp);
      }
    }
  }
  for (register unsigned i(0); i < N; ++i) {
    Ans += f[i];
    if(Ans >= MOD) Ans -= MOD; 
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}

