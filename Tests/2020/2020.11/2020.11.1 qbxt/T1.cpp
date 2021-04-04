#include <cstdio>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp(0), insi(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && rdch != '-') {
    rdch = getchar();
  }
  if (rdch == '-') {
    insi = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insi;
}
long long n, m, ans(0);
int main() {
  /*while (1) {
    printf("%d\n", RD());
  }*/
  // n = RD();
  n = 7699;
  // for (n = 1; n <= (1000); n += 11) {
  // n^3 Force 30 pts
  /*ans = 0;
  for (register int i(1); i <= n; ++i) {
    for (register int j(1); j <= n; ++j) {
      for (register int k(1); k <= n; ++k) {
        if (i * j < k) {
          ++ans;
        }
      }
    }
  }
  printf("%lld -> %lld  %lld\n", n, ans, n * n * n - ans);*/

  // n ^ 2 force 60 pts
  ans = 0;
  for (register int k(2); k <= n; ++k) {
    for (register int j(1); j < k; ++j) {
      ans += (k - 1) / j;
    }
  }
  printf("%lld -> %lld  %lld\n", n, ans, n * n * n - ans);

  // n ^ (3/2) 100 pts
  ans = 0;
  for (register int i(1); i <= n; ++i) {
    for (register int j(1); j * i <= n; ++j) {
      ans += n - i * j + 1;
    }
  }
  printf("%lld -> %lld %lld\n", n, ans, n * n * n - ans);
  //}
  /*for (register int i(1); i <= n; ++i) {
    for (register int j(1); j * i <= n; ++j) {
      ans += n - i * j;
    }
  }
  printf("%lld\n", n * n * n - ans);*/
  system("pause");
  return 0;
}