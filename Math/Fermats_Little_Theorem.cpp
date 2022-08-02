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
unsigned long long Mod;
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Phi(0);
char Flg(0);
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
//  printf("%llu\n", Rt);
  return Rt;
}
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned Tmp;
  while (y) Tmp = x, x = y, y = Tmp % y;
  return x;
}
inline void Clr(unsigned x) {
  Mod = n = x, Phi = 0, Flg = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(2); T <= t; ++T){
    Clr(T);
    for (unsigned i(1); i < n; ++i) {
      if(Gcd(i, n) ^ 1) continue;
      ++Phi;
      if(Pow(i, n - 1) ^ 1) {Flg = 1; break;}
    }
    if(Flg) continue;          // a Exist 
    if(Phi == n - 1) continue; // Prime
    if(!Flg) printf("Fuck %u\n", n); // Strong Fake Prime
  }
  return Wild_Donkey;
}

