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
unsigned long long n, m;
unsigned Cnt(0), Ans[1000005];
inline void Solve(unsigned x, unsigned y) {
  for (unsigned i(1); i < x; ++i) Ans[i] = i + 1;
  Ans[x] = 1;
  if(y) {
    if(y == 1) {
      if(x & 1) swap(Ans[1], Ans[x]), swap(Ans[1], Ans[2]);
      else swap(Ans[1], Ans[x]);
    } else swap(Ans[y], Ans[y - 1]);
  }
  for (unsigned i(1); i <= x; ++i) printf("%u\n", Ans[i]);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  if((n * (n - 1)) >> 1 < m) {printf("SPFA is dead!\n"); return 0;}
  if(!m) {
    for (unsigned i(1); i <= n; ++i) printf("%u\n", i);
    return 0;
  }
  if(m == 1) {
    printf("2\n1\n");
    for (unsigned i(3); i <= n; ++i) printf("%u\n", i);
    return 0;
  }
  if(m == 2) {
    printf("3\n1\n2\n");
    for (unsigned i(4); i <= n; ++i) printf("%u\n", i);
    return 0;
  }
  if(n == 3) {printf("1\n3\n2\n");return 0;}
  for (unsigned long long i(1); i <= n; ++i) {
    if(((i * (i - 1)) >> 1) >= m) {
      Solve(i, (((i - 1) * i) >> 1) - m);
      for (unsigned j(i + 1); j <= n; ++j) printf("%u\n", j);
      return 0;
    }
  }
//  }
  return Wild_Donkey;
}

