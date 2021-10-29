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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Like[1015], Anger[1015], f[1015][150][2][10];
unsigned Cant[10];
inline void Clr () {
  memset(f, 0x3f, sizeof(f));
  memset(Like, 0x3f, sizeof(Like));
  n = RD(), Ans = 0x3f3f3f3f;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  Anger[0] = 0x3f3f3f3f; 
  Cant[0] = -1;
  for (unsigned i(1); i <= 7; ++i) Cant[i] = Cant[i - 1] << 1;
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) Like[i] = RD(), Anger[i] = RD();
    f[2][0][0][1] = 0, Anger[n + 1] = 0;
    for (unsigned i(2), Now(0); i <= 8; ++i) {
      Now |= Cant[Anger[i - 1]] << (i - 1);
      if(Now & (1 << (i - 1))) break;
      f[1][1 << (i - 2)][1][i - 1] = 0;
    }
    for (unsigned i(1); i <= n + 1; ++i) {
      unsigned Mxj(1 << Anger[i]);
      for (unsigned j(0); j < Mxj; ++j) {
        unsigned Now(Cant[Anger[i]]);
        for (unsigned No(1); No <= 7; ++No)
          if(!((1 << (No - 1)) & j)) Now |= Cant[Anger[i + No]] << No;
//        printf("%u %u Now %u\n", i, j, Now);
        if(j & Now) continue;
        Now = i - 1;
        for (unsigned k(0); k < 7; ++k) if(j & (1 << k)) Now = i + k + 1;
        for (unsigned k(1); k <= 7; ++k) {
          if(i < k) break;
          if(Anger[i - k] < Now - i + k) continue;
          unsigned Des(j << k);
          Des |= (1 << (k - 1)) - 1;
          for (unsigned l(1); l <= 7; ++l) {
            if(i - k < l) break;
            f[i][j][0][k] = min(f[i][j][0][k], f[i - k][Des][0][l] + (Like[i - k - l] ^ Like[i - k]));
          }
          for (unsigned l(1); l <= 7; ++l) {
            if(k == l) continue;
            f[i][j][0][k] = min(f[i][j][0][k], f[i - k][Des][1][l] + (Like[i - k + l] ^ Like[i - k]));
          }
//          printf("f[%u, %u, %u, %u] = %u\n", i, j, 0, k, f[i][j][0][k]);
        }
        for (unsigned k(1); k <= 7; ++k) {
          if(!((1 << k) & j)) continue;
          if(Anger[i + k] < Now - i - k) continue;
          unsigned Des(j ^ (1 << (k - 1)));
          for (unsigned l(1); l <= 7; ++l) {
            if(i < l) break;
            f[i][j][1][k] = min(f[i][j][1][k], f[i][Des][0][l] + Like[i - l] ^ Like[i + k]);
          }
          for (unsigned l(1); l <= 7; ++l) {
            if(!((1 << (l - 1)) & Des)) continue;
            f[i][j][1][k] = min(f[i][j][1][k], f[i][Des][1][l] + Like[i + l] ^ Like[i + k]);
          }
//          printf("f[%u, %u, %u, %u] = %u\n", i, j, 1, k, f[i][j][1][k]);
        }
      }
    }
    for (unsigned i(1); i <= 7; ++i) Ans = min(Ans, f[n + 1][0][0][i]);
    printf("%u\n", Ans);
  }
  return Wild_Donkey;
}

