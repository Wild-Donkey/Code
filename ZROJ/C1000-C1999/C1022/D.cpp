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
unsigned long long a[200005][32];
unsigned f[32][100005][32], g[32][100005][32];
unsigned Mid(0), LLen(0), RLen(0), n, qu;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void RBd(unsigned L, unsigned R) {
//  printf ("RBd %u %u\n", L, R);
  if(L > R) {
    LLen = RLen = 0;
    return;
  }
  Mid = (L + R) >> 1;
  LLen = Mid - L;
  RLen = R - Mid + 1;
  for (unsigned i(1); i <= LLen; ++i) {
    for (unsigned Mi(1); Mi <= n; ++Mi) {
      for (unsigned Le(1); Le <= n; ++Le) { 
        g[Mi][i][Le] = (g[Mi][i - 1][Le - 1] + g[Mi][i - 1][Le] + g[Mi][i - 1][Le + 1]) * a[Mid - i][Le] % Mod;
      }
    }
  }
  for (unsigned Mi(1); Mi <= n; ++Mi) f[Mi][1][Mi] = a[Mid][Mi]; 
  for (unsigned i(2); i <= RLen; ++i) {
    for (unsigned Mi(1); Mi <= n; ++Mi) {
      for (unsigned Ri(1); Ri <= n; ++Ri) {
        f[Mi][i][Ri] = (f[Mi][i - 1][Ri - 1] + f[Mi][i - 1][Ri] + f[Mi][i - 1][Ri + 1]) * a[Mid + i - 1][Ri] % Mod;
      }
    }
  } 
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  qu = RD(), n = RD(), Mid = 100000;
  for (unsigned i(1); i <= n; ++i) g[i][0][i] = 1;
  for (unsigned i(1); i <= qu; ++i) {
    A = RD() - 1;
    if(A & 2) {
      if(A & 1) { 
        if(!RLen) RBd(Mid - LLen, Mid - 2);
        else --RLen;
      }
      else {
        if(!LLen) RBd(Mid + 1, Mid + RLen - 1);
        else --LLen;
      }
    } else {
      if(A & 1) {
        for (unsigned j(1); j <= n; ++j) a[Mid + RLen][j] = RD();
        if(!RLen) for (unsigned j(1); j <= n; ++j) f[j][1][j] = a[Mid + RLen][j];
        else {
          for (unsigned Mi(1); Mi <= n; ++Mi) {
            for (unsigned Ri(1); Ri <= n; ++Ri) {
              f[Mi][RLen + 1][Ri] = (f[Mi][RLen][Ri - 1] + f[Mi][RLen][Ri] + f[Mi][RLen][Ri + 1]) * a[Mid + RLen][Ri] % Mod;
            }
          }
        }
        ++RLen;
      } else {
        for (unsigned j(1); j <= n; ++j) a[Mid - LLen - 1][j] = RD();
        for (unsigned Mi(1); Mi <= n; ++Mi) {
          for (unsigned Le(1); Le <= n; ++Le) { 
            g[Mi][LLen + 1][Le] = (g[Mi][LLen][Le - 1] + g[Mi][LLen][Le] + g[Mi][LLen][Le + 1]) * a[Mid - LLen - 1][Le] % Mod;
          }
        }
        ++LLen;
      }
    }
    Ans = 0;
    if(!(LLen | RLen)) {printf("0\n");continue;}
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
2 1 1
3
3
1 30
1 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
*/
