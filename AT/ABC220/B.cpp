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
unsigned a[10005], m, n;
unsigned long long A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp * C) + rdch - '0', rdch = getchar();
  return intmp;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  C = 10, C = RD(), A = RD(), B = RD();
  printf("%llu\n", A * B);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

