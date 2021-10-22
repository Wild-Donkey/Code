#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <bitset>
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
bitset<1000005> a; 
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
//  if(n * m <= 50000000) {
    for(unsigned i(1); i <= m; ++i) {
      for (unsigned j(Tmp + 1); j <= n; ++j) if(a[j]) ++Tmp; else break;
      for (unsigned j(Tmp + 2); j <= n; ++j)
        if((!a[j - 1]) && (a[j])) a[j - 1] = 1, a[j++] = 0;
    }
    for (unsigned i(1); i <= n; ++i) printf("%u ", (unsigned)a[i]);
    putchar(0x0A);
    return 0;
//  }
//  for (unsigned i(1); i <= n; ++i) Cnt += (a[i] ? 1 : 0);
//  for (unsigned i(1); i <= Cnt; ++i) printf("%u ", 1);
//  for (unsigned i(Cnt + 1); i <= n; ++i) printf("%u ", 0);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

