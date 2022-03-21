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
#define Inv(x) Pow(x,Mod-2)
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
bitset<5000000> No;
unsigned Prime[1000000], CtB[5000000], CntP(0), D[5000000], F[5000000], FL[2200], Cub[5000000], CuL[2200], Sq[5000000], SqL[2200], GL[2205];
unsigned long long Mod, m, n, p, P, Inv6, Inv4, Ans(0);
inline void Mn(unsigned& x) {x -= (x >= Mod) ? Mod : 0;}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned long long CG(unsigned long long x) {
  unsigned Rt(0);
  for (unsigned long long L, R(0), Cur, Lst(0), Tis; R < x; ) {
    L = R + 1, R = x / (Cur = x / L), Tis = ((R > m) ? CuL[n / R] : Cub[R]);
    Rt = (Rt + ((Cur > m) ? (CuL[n / Cur]) : Cub[Cur]) * (Mod + Tis - Lst)) % Mod;
    Lst = Tis;
  }
//  printf("G %llu = %llu\n", x, Rt);
  return Rt;
}
unsigned M, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  freopen("P3768_2.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Mod = RD(), n = RDll();
  if(!n) return printf("0\n"), 0;
  if(n == 1) return printf("1\n"), 0;
  if(n == 2) return printf("13\n"), 0;
//  if(n == 3) return printf("58\n"), 0;
  m = pow(n, ((double)2)/3), M = n / m, Inv6 = Inv(6), Inv4 = Inv(4);
  p = sqrt(n), P = n / p;
  while ((n / (M + 1)) > m) ++M; while ((n / M) <= m) --M;
  while ((n / (P + 1)) > p) ++P; while ((n / P) <= p) --P;
//  printf("m %llu M = %u\n", m, M);
  F[1] = 1, D[1] = 1;
  for (unsigned long long i(1); i <= m; ++i) Cub[i] = (Cub[i - 1] + (i * i % Mod) * i) % Mod;
  for (unsigned long long i(1); i <= m; ++i) Sq[i] = (Sq[i - 1] + i * i) % Mod;
  for (unsigned i(1); i <= M; ++i) {
    unsigned long long Nw((n / i) % Mod);
    CuL[i] = ((Nw * (Nw + 2) + 1) % Mod) * ((Inv4 * Nw % Mod) * Nw % Mod) % Mod;
  }
  for (unsigned i(1); i <= M; ++i) {
    unsigned long long Nw((n / i) % Mod);
    SqL[i] = (((Nw * Nw % Mod) * ((Nw << 1) + 3) % Mod) + Nw) * Inv6 % Mod;
  }
  for (unsigned i(2); i <= m; ++i) {
    if(!No[i]) Prime[++CntP] = i, F[i] = (Mod - i) * i % Mod, D[i] = 2, CtB[i] = 2;
    for (unsigned j(1), Cur(i << 1); (Cur <= m) && j <= CntP; ++j, Cur = Prime[j] * i) {
      F[Cur] = (unsigned long long)F[i] * F[Prime[j]] % Mod, D[Cur] = D[i] * D[Prime[j]], CtB[Cur] = 2, No[Cur] = 1;
//      printf("%u -> %u %u %u\n", i, Cur, CtB[i], CtB[Cur]);
      if(!(i % Prime[j])) {F[Cur] = 0, D[Cur] = (D[i] / CtB[i]) * (CtB[Cur] = CtB[i] + 1);break;}
    }
  }
//  for (unsigned i(1); i <= m; ++i) printf("%u ", CtB[i]); putchar(0x0A);
//  for (unsigned i(1); i <= m; ++i) printf("%u ", D[i]); putchar(0x0A);
//  for (unsigned i(1); i <= m; ++i) printf("%u ", F[i]); putchar(0x0A);
//  for (unsigned i(1); i <= m; ++i) printf("%llu ", PreSq(i)); putchar(0x0A);
//  for (unsigned i(1); i <= m; ++i) printf("%llu ", PreCb(i)); putchar(0x0A);
  for (unsigned long long i(1); i <= m; ++i) D[i] = (D[i - 1] + ((D[i] * i % Mod) * i % Mod) * i) % Mod;
  for (unsigned i(1); i <= m; ++i) F[i] += F[i - 1], Mn(F[i]);
  for (unsigned long long i(M), j(n / M); i; --i) {
    j = n / i, FL[i] = 1;
    for (unsigned long long L, R(1), Cur, Lst(1), Tis; R < j; ) {
      L = R + 1, R = j / (Cur = j / L), Tis = ((R > m) ? (SqL[n / R]) : Sq[R]);
      FL[i] = (FL[i] + ((Cur > m) ? FL[n / Cur] : F[Cur]) * (Mod + Lst - Tis)) % Mod;
      Lst = Tis;
    }
  }
//  for (unsigned i(1); i <= n; ++i) printf("%u ", ((i > m) ? FL[n / i] : F[i])); putchar(0x0A);
  for (unsigned i(1); i <= M; ++i) GL[i] = CG(n / i);
//  for (unsigned i(1); i <= 100; ++i) printf("%u: %u %llu\n", i, D[i], CG(i));
  for (unsigned long long L, R(0), Cur, Lst(0), Tis; R < n; ) {
    L = R + 1, R = n / (Cur = n / L), Tis = ((R > m) ? (FL[n / R]) : F[R]);
    Ans = (Ans + (((Cur <= m) ? D[Cur] : GL[n / Cur]) * (Mod + Tis - Lst))) % Mod;
//    printf("[1,%llu] = %llu\n", R, Ans);
    Lst = Tis;
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
1 -1 -1 0 -1 1
1 1  2  2 4  2
1 0  1  1 
998244353 4
998244353 2000
1000000007 9786510294
1 2 3 4 6 
1 [1,12]
2 [1,6]
3 [1,4]
4 [1,3]
5 [1,2]
6 [1,2]
7, 8, 9, 10, 11, 12
*/
