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
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long Bin[1005], Tri[1005], n;
unsigned long long Ans[1005];
unsigned Now2, Now3;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Clr() {
  Cnt = Now2 = 0, Now3 = 40;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  Bin[0] = Tri[0] = 1;
  for (unsigned i(1); i <= 1000; ++i) Bin[i] = Bin[i - 1] << 1;
  for (unsigned i(1); i <= 1000; ++i) Tri[i] = Tri[i - 1] * 3;
//  for (unsigned i(1); i <= 1000; ++i) printf("3^%u = %llu\n", i, Tri[i]);
//  t = 100;
//  for (unsigned T(1); T <= t; ++T){
    Clr(), n = RD();
    while (n) {
//      printf("N %llu 2^%u 3^%u\n", n, Now2, Now3);
      while (!(n & 1)) n >>= 1, ++Now2;
      while(n < Tri[Now3]) --Now3;
      n -= Tri[Now3], Ans[++Cnt] = Bin[Now2] * Tri[Now3];
    }
    printf("%u\n", Cnt);
    for (unsigned i(1); i <= Cnt; ++i) printf("%llu ", Ans[i]);
    putchar(0x0A);
//  }
  return Wild_Donkey;
}
/*
1000000000000000000
*/
