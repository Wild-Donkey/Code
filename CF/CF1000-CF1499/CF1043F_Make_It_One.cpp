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
const unsigned long long Mod(998244353);
bitset<300005> No;
unsigned a[300005], b[300005], Fac[300005], Inv[300005], Mu[300005];
unsigned Pri[50005], CntP(0);
unsigned A, B(0), D, t, n;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpG;
  while (y) { TmpG = x, x = y, y = TmpG % y; }
  return x;
}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned C (unsigned x, unsigned y) {
  if(y > x) return 0;
  return ((unsigned long long)Fac[x] * Inv[y] % Mod) * Inv[x - y] % Mod;
}
//  inline void Clr() {}
signed main() {
//  freopen("A4.in", "r", stdin);
//  freopen("My.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Mu[1] = Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) B = Gcd(a[i] = RD(), B);
  if(B ^ 1) {printf("-1\n"); return 0;}
  for (unsigned i(1); i <= n; ++i) b[a[i]] = 1;
  for (unsigned i(2); i <= 300000; ++i) {
    if(!No[i]) Mu[Pri[++CntP] = i] = 998244352;
    for (unsigned j(1), k(2); (k * i <= 300000) && (j <= CntP); k = Pri[++j]) {
      No[k * i] = 1;
      if(!(i % k)) {Mu[k * i] = 0; break;}
      Mu[k * i] = (unsigned long long)Mu[k] * Mu[i] % Mod;
    }
  }
  for (unsigned long long i(1); i <= 300000; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[300000] = Pow(Fac[300000], 998244351);
  for (unsigned long long i(300000); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  for (unsigned i(1); i <= 150000; ++i)
    for (unsigned j(300000 / i); j > 1; --j) b[i] += b[i * j];
  for (unsigned i(1); i <= 6; ++i) {
    Ans = 0;
    for (unsigned j(1); j <= 300000; ++j) Ans = (Ans + (unsigned long long)Mu[j] * C(b[j], i)) % Mod;
    if(Ans ^ 0) {printf("%u\n", i); return 0;}
  }
  printf("7\n");
//  }
  return Wild_Donkey;
}

