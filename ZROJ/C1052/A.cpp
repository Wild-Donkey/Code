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
const unsigned long long Mod(998244353), Per(804434861);
const unsigned char Ara[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
bitset<81> a, Ava[50000];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char IO[12];
inline void Clr() {
  Ans = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  for (unsigned i1(0); i1 < 6; ++i1) {
    for (unsigned i2(0); i2 < 6; ++i2) {
      for (unsigned i3(0); i3 < 6; ++i3) {
        for (unsigned j1(0); j1 < 6; ++j1) {
          for (unsigned j2(0); j2 < 6; ++j2) {
            for (unsigned j3(0); j3 < 6; ++j3) {
              unsigned Num(i1 * 7776 + i2 * 1296 + i3 * 216 + j1 * 36 + j2 * 6 + j3);
//              printf("%u:\n", Num);
              Ava[Num][Ara[i1][0] * 9 + Ara[j1][0]] = 1;
              Ava[Num][Ara[i1][1] * 9 + 3 + Ara[j2][0]] = 1;
              Ava[Num][Ara[i1][2] * 9 + 6 + Ara[j3][0]] = 1;
              Ava[Num][(3 + Ara[i2][0]) * 9 + Ara[j1][1]] = 1;
              Ava[Num][(3 + Ara[i2][1]) * 9 + 3 + Ara[j2][1]] = 1;
              Ava[Num][(3 + Ara[i2][2]) * 9 + 6 + Ara[j3][1]] = 1;
              Ava[Num][(6 + Ara[i3][0]) * 9 + Ara[j1][2]] = 1;
              Ava[Num][(6 + Ara[i3][1]) * 9 + 3 + Ara[j2][2]] = 1;
              Ava[Num][(6 + Ara[i3][2]) * 9 + 6 + Ara[j3][2]] = 1;
//              for (unsigned i(0); i < 9; ++i) {
//                for (unsigned j(0); j < 9; ++j) putchar('0' + Ava[Num][i * 9 + j]);
//                putchar(0x0A);
//              }
            }
          }
        }
      }
    }
  }
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(0); i < 9; ++i) {
      scanf("%s", IO);
      for (unsigned j(0); j < 9; ++j) a[i * 9 + j] = IO[j] - '0';
    }
    for (unsigned i(0); i < 46656; ++i) if(!((a & Ava[i]).any())) ++Ans;
    printf("%llu\n", Ans * Per % Mod);
  }
  return Wild_Donkey;
}

