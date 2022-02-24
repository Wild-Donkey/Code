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
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned long long Mod(10000007);
unsigned long long Ans(1), C[105][105], n;
unsigned m(0), Cnt(0), Tmp(0);
unsigned long long Pow(unsigned long long x, unsigned long long y) {
  unsigned long long Pns(1);
  while (y) {
    if (y & 1) Pns = Pns * x % Mod;
    y >>= 1, x = x * x % Mod;
  }
  return Pns;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  while (n >> m) ++m; --m;
  for (unsigned i(0); i <= m; ++i) {
    C[i][0] = 1;
    for (unsigned j(1); j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  for (unsigned i(m); ~i; --i) {
    // printf("Do %u th\n", i);
    if (!((n >> i) & 1)) continue;
    for (unsigned j(0); j <= i; ++j) {
      if (!(j + Cnt)) continue;
      Ans = Ans * Pow(j + Cnt, C[i][j]) % Mod;
    }
    ++Cnt;
  }
  Ans = Ans * Cnt % Mod;
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
0 1 1 2 1 2 2 3: 24
1 2 2 3 2 3 3 4: 864
1 2 2 3 2 3 3 4: 864
2 3 3 4 3 4 4 5:
*/