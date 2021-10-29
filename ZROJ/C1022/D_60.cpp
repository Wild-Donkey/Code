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
const unsigned long long Mod(998244353);
unsigned long long Ans, TmpL, TmpR;
unsigned long long a[32];
unsigned f[32][100005][32], g[32][100005][32];
unsigned LLen(0), RLen(0), n, qu;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  qu = RD(), n = RD();
  for (unsigned i(1); i <= n; ++i) g[i][0][i] = 1;
  for (unsigned i(1); i <= qu; ++i) {
    A = RD() - 1;
    if(A & 2) {
      if(A & 1) --RLen;
      else --LLen;
    } else {
      for (unsigned j(1); j <= n; ++j) a[j] = RD();
      if(A & 1) {
        if(!RLen) for (unsigned j(1); j <= n; ++j) f[j][1][j] = a[j];
        else {
          for (unsigned Mi(1); Mi <= n; ++Mi) {
            for (unsigned Ri(1); Ri <= n; ++Ri) {
              f[Mi][RLen + 1][Ri] = (f[Mi][RLen][Ri - 1] + f[Mi][RLen][Ri] + f[Mi][RLen][Ri + 1]) * a[Ri] % Mod;
            }
          }
        }
        ++RLen;
      } else {
        for (unsigned Mi(1); Mi <= n; ++Mi) {
          for (unsigned Le(1); Le <= n; ++Le) {  
            g[Mi][LLen + 1][Le] = (g[Mi][LLen][Le - 1] + g[Mi][LLen][Le] + g[Mi][LLen][Le + 1]) * a[Le] % Mod;
          }
        }
        ++LLen;
      }
    }
    Ans = 0;
    if(!(LLen | RLen)) continue;
    if(!RLen) {
      for (unsigned Mi((n % 3) ? 1 : 2); Mi <= n; Mi += 3) for (unsigned Le(1); Le <= n; ++Le) 
        {Ans += g[Mi][LLen][Le]; if(Ans >= Mod) Ans -= Mod;}
      printf("%llu\n", Ans);
      continue;
    }
    for (unsigned Mi(1); Mi <= n; ++Mi) {
      TmpL = TmpR = 0;
      for (unsigned Ri(1); Ri <= n; ++Ri) {TmpR += f[Mi][RLen][Ri]; if(TmpR >= Mod) TmpR -= Mod;}
      if(LLen) {
        for (unsigned Le(1); Le <= n; ++Le) {TmpL += g[Mi][LLen][Le]; if(TmpL >= Mod) TmpL -= Mod;}
      }
      else TmpL = 1;
//      printf("Mi %u TmpL %llu TmpR %llu\n", Mi, TmpL, TmpR);
      Ans = (Ans + TmpL * TmpR) % Mod;
    }
    printf("%llu\n", Ans);
  }
//  }
  return Wild_Donkey;
}
/*
5 2
2 1 1
2 1 1
1 1 1
4
3
1 30
1 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
*/
