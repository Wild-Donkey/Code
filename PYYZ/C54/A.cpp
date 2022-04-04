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
#include <set>
#include <string>
#include <unordered_map>
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
bitset<100005> No;
unsigned Pri[10005], Cnt[100005], a[100005], Add[100005], CntP(0), m, n;
unsigned long long Ans(0);
unsigned A, B, C, D, t;
unsigned Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Cnt[1] = 0;
  for (unsigned i(2); i <= 100000; ++i) {
    if(!No[i]) Pri[++CntP] = i, Cnt[i] = 1;
    for (unsigned j(1), k(i << 1); (k <= 100000) && (j <= CntP); ++j, k = Pri[j] * i) {
      No[k] = 1, Cnt[k] = Cnt[i] + 1;
      if(!(i % Pri[j])) Cnt[k] = 0x3f3f3f3f;
    }
  }
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", Pri[i]); putchar(0x0A);
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", Cnt[i]); putchar(0x0A);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD();
    if(B % m) {printf("%llu\n", Ans); continue;}
    B /= m;
    if(!A) { if(Add[B]) --Add[B]; else {printf("%llu\n", Ans); continue;} }
    else ++Add[B];
    for (unsigned j(sqrt(B)); j; --j) if(!(B % j)) {
      if(Cnt[j] < 0x3f3f3f3f) {
        if(!A) --a[j];
        if((Cnt[j] & 1) ^ A) Ans += a[j]; else Ans -= a[j];
        if(A) ++a[j];
      }
      if(((j * j) ^ B) && (Cnt[B / j] < 0x3f3f3f3f)) {
        if(!A) --a[B / j];
        if((Cnt[B / j] & 1) ^ A) Ans += a[B / j]; else Ans -= a[B / j];
        if(A) ++a[B / j];
      }
    }
    printf("%llu\n", Ans);
  }
//  }
  return Wild_Donkey;
}

