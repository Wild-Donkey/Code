#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
} 
const unsigned long long Mod(1000000007);
unsigned long long a[100005], f[100005], Ans(0);
unsigned m, n, t, Dec, Tmp;
inline void Clr() {
  f[Dec = n = RD()] = 0, memset(f, 0x3f, n << 3);
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (unsigned i(n); i; --i) a[i] += a[i + 1];
    for (unsigned i(n); i; --i) {
      if((i << 1) < Dec) Dec = (i << 1);
      for (unsigned j(Dec), k((i << 1) - Dec + 1); j > i; --j, ++k) {
        if(f[i] > f[j] + a[k]) f[i] = f[j] + a[k] , Dec = j;
      }
    }
    printf("%llu\n", f[1]);
  }
  return Wild_Donkey;
}
/*
3
3
1 1 1
10
7227 5733 5653 3470 2497 2027 1196 773 461 31
10
9910 9481 7965 7089 2039 1897 1795 970 714 97
*/
