#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
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
bitset<20005> E[20005], Le, Ri;
unsigned long long Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char a[20005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    scanf("%s", a + 1); 
    for (unsigned j(1); j <= n; ++j) Le[j] = ((a[j] - '0') & 1);
    for (unsigned j(1); j <= n; ++j) Ri[j] = ((a[j] - '0') & 2);
    for (unsigned j(1); j <= n; ++j) {
      if(Le[j] && Ri[j]) Le[j] = 0, Ri[j] = 0, E[j] ^= (Le | Ri);
      else {
        if(Le[j]) Le[j] = 0, E[j] ^= Ri;
        if(Ri[j]) Ri[j] = 0, E[j] ^= Le;
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) Ans += E[i].count();
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

