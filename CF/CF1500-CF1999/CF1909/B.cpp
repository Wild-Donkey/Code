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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long a[105], Ans, Md[2];
unsigned m, n;
unsigned t;
inline void Clr() { n = RD(); }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (Ans = 1;; Ans <<= 1, ++Ans) {
      Md[m = 0] = (a[1] & Ans);
      char Flg(0);
      for (unsigned i(2); i <= n; ++i)
        if (Md[m] ^ (a[i] & Ans)) {
          if (m == 1) {
            if (Md[0] ^ (a[i] & Ans)) {
              Flg = 1;
              break;
            } else
              continue;
          }
          Md[++m] = (a[i] & Ans);
        }
      // printf("%llu: %llu %llu\n", Ans, Md[0], Md[1]);
      if (!Flg && m) {
        printf("%llu\n", Ans + 1);
        break;
      }
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1 3 5 7 9
3
4

*/