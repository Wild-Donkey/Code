#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
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
inline long long Gcd(long long x, long long y) {
  long long TmpG;
  while (y) TmpG = x, x = y, y = TmpG % y;
  return (x < 0) ? (-x) : x;
}
const unsigned long long Mod1(20000003), Mod2(10000079), Base1(998244353), Base2(1000000007);
unsigned Stack1[2505], Stack2[2505];
unsigned short Table1[20000050], Table2[10000100];
unsigned long long Ans, n;
unsigned short STop(0), Sa(0);
unsigned A, B, C, D, t;
unsigned Tmp(0);
struct Vec {
  long long Va[3];
  inline void Dec () {
    long long GD(Gcd(Va[2], Gcd(Va[0], Va[1])));
    if(GD ^ 1) {
      Va[0] /= GD;
      Va[1] /= GD;
      Va[2] /= GD;
    }
    if(Va[0] == 0) {
      if(Va[1] == 0) {if(Va[2] < 0) Va[0] = -Va[0], Va[1] = -Va[1], Va[2] = -Va[2];}
      else if(Va[1] < 0) Va[0] = -Va[0], Va[1] = -Va[1], Va[2] = -Va[2];
    } else if(Va[0] < 0) Va[0] = -Va[0], Va[1] = -Va[1], Va[2] = -Va[2];
  }
  inline unsigned long long Hash1 () {
    unsigned long long TmpH(Va[0]);
    TmpH = TmpH * Base1 + Va[1];
    TmpH = TmpH * Base1 + Va[2];
    return TmpH % Mod1;
  }
  inline unsigned long long Hash2 () {
    unsigned long long TmpH(Va[0]);
    TmpH = TmpH * Base2 + Va[1];
    TmpH = TmpH * Base2 + Va[2];
    return TmpH % Mod2;
  }
  inline void FindInsert () {
    ++STop, Tmp += min(Table1[Stack1[STop] = Hash1()]++, Table2[Stack2[STop] = Hash2()]++) + Sa;
  }
  inline Vec operator * (const Vec& x) {
    Vec TmpT;
    TmpT.Va[0] = Va[1] * x.Va[2] - Va[2] * x.Va[1];
    TmpT.Va[1] = Va[0] * x.Va[2] - Va[2] * x.Va[0];
    TmpT.Va[2] = Va[0] * x.Va[1] - Va[1] * x.Va[0];
    return TmpT;
  }
}V[2505];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Ans = n * (n - 1) * (n - 2) / 6;
  for (unsigned short i(1); i <= n; ++i) {
    V[i].Va[0] = RDsg();
    V[i].Va[1] = RDsg();
    V[i].Va[2] = RDsg();
    V[i].Dec();
  }
  for (unsigned short i(1); i <= n; ++i) {
//    printf("%u (%d, %d, %d)\n", i, V[i].Va[0], V[i].Va[1], V[i].Va[2]);
    Vec Crs;
    while (STop) Table1[Stack1[STop]] = Table2[Stack2[STop--]] = 0;
//    Law.clear();
    Sa = Tmp = 0;
    for (unsigned short j(i + 1); j <= n; ++j) {
      Crs = V[i] * V[j];
//      printf("%u %u (%d, %d, %d)\n", i, j, Crs.Va[0], Crs.Va[1], Crs.Va[2]);
      if (Crs.Va[0] | Crs.Va[1] | Crs.Va[2]) Crs.Dec(), Crs.FindInsert();
      else Tmp += j - i - 1, ++Sa;
    }
//    printf("Cnt %u\n", Tmp);
    Ans -= Tmp;
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

