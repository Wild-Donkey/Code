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
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned Mod(1000000007);
unsigned long long Ans(0), n, f[1000005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpT(1);
  while (y) {
    TmpT = x, x = y, y = TmpT % x; 
  }
  return x;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    f[i] = 1;
    for (unsigned j(1); j <= i; ++j) {
      if(Gcd(i, j) == 1) f[i] = f[i] * j % i;
    }
    Ans += f[i];
    if(Ans >= Mod) Ans -= Mod; 
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
