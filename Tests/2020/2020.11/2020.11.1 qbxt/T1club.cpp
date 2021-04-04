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
long long n, m, ans1(0), ans2(0), ans3(0);
int main() {
  /*while (1) {
    printf("%d\n", RD());
  }*/
  // n = RD();
  for (n = 7699; n <= (100000); ++n) {
    // n^3 Force 30 pts
    /*ans1 = 0;
    for (register int i(1); i <= n; ++i) {
      for (register int j(1); j <= n; ++j) {
        for (register int k(1); k <= n; ++k) {
          if (i * j < k) {
            ++ans1;
          }
        }
      }
    }*/
    // printf("%lld -> %lld  %lld\n", n, ans, n * n * n - ans);

    // n ^ 2 force 60 pts
    ans2 = 0;
    for (register int k(2); k <= n; ++k) {
      for (register int j(1); j < k; ++j) {
        ans2 += (k - 1) / j;
      }
    }
    // printf("%lld -> %lld  %lld\n", n, ans, n * n * n - ans);

    // n ^ (3/2) 100 pts
    ans3 = 0;
    for (register int i(1); i <= n; ++i) {
      for (register int j(1); j * i <= n; ++j) {
        ans3 += n - i * j;
      }
    }
    if (/*ans1 == ans2 && */ ans2 == ans3) {
      printf("AC %lld %lld\n", n, n * n * n - ans2);
    } else {
      printf("WA %lld %lld %lld", n, /* n * n * n - ans1,*/ n * n * n - ans2,
             n * n * n - ans2);
      break;
    }
  }
  /*
  for (register int i(1); i <= n; ++i) {
    for (register int j(1); j * i <= n; ++j) {
      ans += n - i * j;
    }
  }*/
  // printf("%lld\n", n * n * n - ans);
  system("pause");
  return 0;
}