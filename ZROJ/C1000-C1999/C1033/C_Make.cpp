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
long double mFl, FF[1005];
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
unsigned long long F[1005], m, n, t;
signed main() {
  freopen("C.in", "w", stdout);
  t = 100;
  printf("%llu\n", t);
  srand(time(0)); 
  FF[1] = FF[2] = F[1] = F[2] = 1;
  for (unsigned i(3); i <= 10; ++i) {
    F[i] = F[i - 1] + F[i - 2]; if(F[i] >= Mod) F[i] -= Mod;
    FF[i] = FF[i - 1] + FF[i - 2];
  }
  for (unsigned T(1); T <= t; ++T) {
//    n = 3 + (rand() % 5), m = (rand() % F[n]) + 1;
    n = 20, m = T;
    printf("%llu %llu\n", n, m);
  }
  return Wild_Donkey;
}
/*
2
4 3
5 5
*/
