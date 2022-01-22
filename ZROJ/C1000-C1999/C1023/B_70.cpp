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
  while (y) {
    TmpG = x, x = y, y = TmpG % y;
  }
  return x;
}
const unsigned long long Mod1(20000003), Mod2(10000079), Base1(998244353), Base2(1000000007);
unsigned Stack1[3005], STop1(0), Table1[20000050];
unsigned Stack2[3005], STop2(0), Table2[10000100];
unsigned long long Ans, n;
unsigned m(0);
unsigned A, B, C, D, t;
unsigned Tmp(0), Sa(0);
inline void ClrHa () {
  while (STop1) Table1[Stack1[STop1--]] = 0;
  while (STop2) Table2[Stack2[STop2--]] = 0;
}
struct Vec {
  long long Va[3];
  inline void Inv () {
    Va[0] = -Va[0];
    Va[1] = -Va[1];
    Va[2] = -Va[2];
  }
  inline void Dec () {
    if(Va[0] == 0) {
      if(Va[1] == 0) {if(Va[2] < 0) Inv();}
      else if(Va[1] < 0) Inv();
    } else if(Va[0] < 0) Inv();
    long long GD(Gcd(Gcd(Va[0], Va[1]), Va[2]));
    Va[0] /= GD;
    Va[1] /= GD;
    Va[2] /= GD;
  }
  inline const char operator< (const Vec&x) const{
    if(Va[0] ^ x.Va[0]) return Va[0] < x.Va[0];
    if(Va[1] ^ x.Va[1]) return Va[1] < x.Va[1];
    return Va[2] < x.Va[2];
  }
  inline const char operator== (const Vec&x) const{
    return (Va[0] == x.Va[0]) && (Va[1] == x.Va[1]) && (Va[2] == x.Va[2]);
  }
  inline const char operator== (const unsigned x) const{
    return (Va[0] == x) && (Va[1] == x) && (Va[2] == x);
  }
  inline unsigned long long Hash1 () {
    unsigned long long TmpH(Va[0]);
    TmpH = (TmpH * Base1 + Va[1]) % Mod1;
    TmpH = (TmpH * Base1 + Va[2]) % Mod1;
    return TmpH % Mod1;
  }
  inline unsigned long long Hash2 () {
    unsigned long long TmpH(Va[0]);
    TmpH = (TmpH * Base2 + Va[1]) % Mod2;
    TmpH = (TmpH * Base2 + Va[2]) % Mod2;
    return TmpH % Mod2;
  }
  inline void Insert () {
    ++Table1[Stack1[++STop1] = Hash1()];
    ++Table2[Stack2[++STop2] = Hash2()];
  }
  inline void Find () {
    Tmp += min(Table1[Hash1()], Table2[Hash2()]) + Sa;
  }
  inline void operator -= (const Vec& x) {
    Va[0] -= x.Va[0];
    Va[1] -= x.Va[1];
    Va[2] -= x.Va[2];
  }
  inline void operator *= (const unsigned x) {
    Va[0] *= x;
    Va[1] *= x;
    Va[2] *= x;
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
  for (unsigned i(1); i <= n; ++i) {
    V[i].Va[0] = RDsg();
    V[i].Va[1] = RDsg();
    V[i].Va[2] = RDsg();
    V[i].Dec();
  }
  for (unsigned i(1); i <= n; ++i) {
//    printf("%u (%d, %d, %d)\n", i, V[i].Va[0], V[i].Va[1], V[i].Va[2]);
    Vec Crs;
    ClrHa();
//    Law.clear();
    Sa = Tmp = 0;
    for (unsigned j(i + 1); j <= n; ++j) {
      Crs = V[i] * V[j];
//      printf("%u %u (%d, %d, %d)\n", i, j, Crs.Va[0], Crs.Va[1], Crs.Va[2]);
      if(Crs == 0) Tmp += j - i - 1, ++Sa;
      else Crs.Dec(), Crs.Find(), Crs.Insert();
    }
//    printf("Cnt %u\n", Tmp);
    Ans -= Tmp;
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

