#include <algorithm>
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
const unsigned long long Mod(1000000007);
unsigned long long m, n, Base;
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long TmpP(1); 
  while (y) {
    if(y & 1) TmpP = TmpP * x % Mod;
    y >>= 1, x = x * x % Mod;
  }
  return TmpP;
} 
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Base = RD(), m = RD();
  if(n < m) {printf("%llu\n", Pow(Base, n));return 0;}
  if(n == m) {printf("%llu\n", Pow(Base, (n + 1) >> 1)); return 0;}
  if(m == 1) {printf("%llu\n", Pow(Base, n));return 0;}
  if(m & 1) {printf("%llu\n", Base * Base);return 0;}
  printf("%llu\n", Base);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1 1 1
5 2 4
*/
