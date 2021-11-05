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
const unsigned long long Mod(258280327);
long double mFl, FF[1005], SumF[1005];
inline unsigned long long RD() {
  unsigned long long intmp(0);
  mFl = 0; 
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    mFl = mFl * 10 + rdch - '0';
    intmp = ((intmp << 3) + (intmp << 1) + rdch - '0') % Mod;
    rdch = getchar();
  }
  return intmp;
}
unsigned long long F[1005], Sum[1005], m, n;
unsigned t;
inline void Calc() {
  unsigned nn(1);
  while (SumF[nn] < mFl) ++nn;
  printf("%llu\n", ((Mod << 1) + (F[nn] - 1) + m - Sum[nn - 1] - 1) % Mod);
}
signed main() {
  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
  t = RD();
  FF[1] = FF[2] = F[1] = F[2] = 1;
  for (unsigned i(3); i <= 1000; ++i) {
    F[i] = F[i - 1] + F[i - 2]; if(F[i] >= Mod) F[i] -= Mod;
    FF[i] = FF[i - 1] + FF[i - 2];
  }
  for (unsigned i(1); i <= 999; ++i) {
    SumF[i] = SumF[i - 1] + FF[i + 1];
    Sum[i] = Sum[i - 1] + F[i + 1];
    if(Sum[i] >= Mod) Sum[i] -= Mod;
  }
  for (unsigned T(1); T <= t; ++T) {
    n = RD(), m = RD();
    if(m <= 1) {printf("0\n"); continue;}
    Calc();
  }
  return Wild_Donkey;
}
/*
2
4 3
5 5
*/
