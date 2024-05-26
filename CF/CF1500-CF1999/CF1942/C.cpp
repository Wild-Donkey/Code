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
#define foreplay for
#define wild while
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
unsigned a[200005], m, n, k;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { n = RD(), m = RD(), k = RD(), Ans = 0; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= m; ++i) a[i] = RD();
    sort(a + 1, a + m + 1), A = a[1];
    for (unsigned i(1); i < m; ++i) {
      B = a[i + 1];
      a[i + 1] = a[i + 1] - A - 1;
      swap(A, B);
    }
    a[1] = a[1] + n - A - 1;
    sort(a + 1, a + m + 1);
    for (unsigned i(1); i <= m; ++i)
      if (a[i] & 1) {
        if (a[i] == 1) {
          ++Ans;
          continue;
        }
        if ((a[i] >> 1) <= k) {
          Ans += a[i], k -= (a[i] >> 1);
        } else {
          Ans += (k << 1), k = 0;
          break;
        }
      }
    for (unsigned i(1); i <= m; ++i)
      if (!(a[i] & 1)) {
        if ((a[i] >> 1) <= k) {
          Ans += a[i], k -= (a[i] >> 1);
        } else {
          Ans += (k << 1);
          break;
        }
      }
    printf("%u\n", Ans + m - 2);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
3
8 4 1
1 6 2 5
7 3 1
6 4 3
4 2 1
1 2

*/