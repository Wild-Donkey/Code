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
const unsigned long long Mod(19901013);
inline void Mn(unsigned& x){x -= (x >= Mod) ? Mod : 0;}
unsigned long long Ans(0);
unsigned Range[16][16][16][16];
unsigned m, n, N;
unsigned A, B, C, D, t;
unsigned Cnt(0);
char a[17][16];
inline void Calc(unsigned U, unsigned L, unsigned R) {
//  printf("Calc [%u, n] [%u, %u]\n", U, L, R);
  unsigned Lim(R - L + 1), Con(1 << Lim);
  unsigned f[2][Con], *Cur(f[0]), *To(f[1]);
  memset(Cur, 0, Con << 2); 
  Cur[0] = 1;
  for (unsigned i(U); i <= n; ++i) {
    for (unsigned j(L), J(0); j <= R; ++j, ++J) {
//      printf("Now %u %u\n", i , j);
//      for (unsigned k(0); k < Con; ++k) printf("%u ", Cur[k]); putchar(0x0A);
      if(!a[i][j]) continue;
      memset(To, 0, Con << 2);
      for (unsigned k(0); k < Con; ++k) if(Cur[k]) {
        if((k >> J) & 1) To[k ^ (1 << J)] += Cur[k], Mn(To[k ^ (1 << J)]);
        else {
          if(a[i][j + 1] && (j < R) && (!((k >> J) & 3))) To[k ^ (2 << J)] += Cur[k], Mn(To[k ^ (2 << J)]);
          if(a[i + 1][j]) To[k ^ (1 << J)] += Cur[k], Mn(To[k ^ (1 << J)]);
          To[k] += Cur[k], Mn(To[k]);
        }
      }
      swap(Cur, To);
    }
    Range[U][i][L][R] = Cur[0];
  }
}
unsigned long long Belt(unsigned *Ls, unsigned Cn, unsigned L, unsigned R) {
  unsigned long long Rt(1);
  for (unsigned Lst(0), i(0); i < Cn; ++i) Rt = Rt * Range[L][R][Lst][Ls[i]] % Mod, Lst = Ls[i] + 1;
  return Rt;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), N = (1 << ((m = RD()) - 1));
  for (unsigned i(1); i <= n; ++i) scanf("%s", a[i]);
  for (unsigned i(0); i <= 16; ++i) for (unsigned j(0); j <= 15; ++j) a[i][j] = (a[i][j] == '.');
  for (unsigned i(1); i <= n; ++i) for (unsigned j(0); j < m; ++j) for (unsigned k(j); k < m; ++k) Calc(i, j, k);
//  for (unsigned i(1); i <= n; ++i) for (unsigned j(0); j < m; ++j) for (unsigned k(j); k < m; ++k) for (unsigned l(i); l <= n; ++l) printf("[%u,%u][%u,%u] %u\n", i, l, j, k, Range[i][l][j][k]);
  for (unsigned i(0); i < N; ++i) {
    unsigned long long Pref[16];
    unsigned Cut[m], CntC(0);
    for (unsigned j(0); j < m - 1; ++j) if((i >> j) & 1) Cut[CntC++] = j;
    Cut[CntC++] = m - 1;
//    printf("List: %u\n", i);
//    for (unsigned j(0); j < CntC; ++j) printf("%u ", Cut[j]); putchar(0x0A); 
    for (unsigned j(1); j <= n; ++j) {
      Pref[j] = Belt(Cut, CntC, 1, j);
      for (unsigned k(1); k < j; ++k)
        Pref[j] = (Pref[j] + (Mod - Pref[k]) * Belt(Cut, CntC, k + 1, j)) % Mod;
    }
    Ans += ((CntC & 1) ? Pref[n] : Mod - Pref[n]);
//    printf("%u %u\n", Pref[n], i);
  }
  printf("%llu\n", Ans % Mod);
//  }
//  system("pause");
  return Wild_Donkey;
}
/*
3 3
...
...
...
*/
