#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned m, n, t, Ans(0), f[2505], dp[55][55][2];
char Inch, a[55];
int main() {
  srand(time(0));
  n = RD(), m = RD(), t = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while ((Inch ^ '0') && (Inch ^ '1')) Inch = getchar();
    for (register unsigned j(1); j <= m; ++j) {
      a[j] = Inch - '0', Inch = getchar();
    }
    for (register unsigned j(1); j <= m; ++j) {
      for (register unsigned k(1); k <= m; ++k) {
        dp[j][k][a[j]] = max(dp[j - 1][k][a[j]], dp[j - 1][k - 1][a[j] ^ 1]) + 1;
        dp[j][k][a[j] ^ 1] = max(dp[j - 1][k][a[j] ^ 1], dp[j - 1][k - 1][a[j]]);
      }
    }
    for (register unsigned j(min(t, m * i)); j < 0x3f3f3f3f; --j) {
      for (register unsigned k(1); k <= min(m, j); ++k) {
        f[j] = max(f[j], f[j - k] + max(dp[m][k][0], dp[m][k][1]));
      }
    }
  }
  if(t >= n * m) Ans = n * m;
  else Ans = f[t];
  printf("%u\n", Ans);
  return Wild_Donkey;
}
