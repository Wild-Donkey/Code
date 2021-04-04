#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline long long RD() {
  long long intmp(0), insi(1);
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
bool flg(0);
int n, ans(0), tmp(0);
int a[3000005];
int dfrlt[3000005];
int lst[3000005];
int main() {
  /*while (1) {
    printf("%d\n", RD());
  }*/
  n = RD();
  lst[0] = 0;
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  if (n > 10000) {
    for (register int i(1); i <= n; ++i) {
      ++dfrlt[i + 1];
      --dfrlt[min(i + a[i] + 1, n)];
      lst[i] = lst[i - 1] + dfrlt[i];
      // printf("%d -- %d\n", i, lst[i]);
      tmp = 0;
      for (register int j(max(1, i - a[i])); j < i - 1; ++j) {
        tmp = max(lst[j], tmp);
      }
      ans ^= tmp;
      // printf("%d %d\n", i, tmp);
    }
    printf("%d\n", ans);
    // system("pause");
    return 0;
  }
  ans = 0;
  for (register int k(1); k <= n; ++k) {
    tmp = 0;
    for (register int i(1); i < k - 1; ++i) {
      for (register int j((k + i + 1) >> 1); j < k; ++j) {
        if (j <= i + a[i] && j >= k - a[k]) {
          ++tmp;
          break;
        }
      }
    }
    printf("%d %d\n", k, tmp);
    ans ^= tmp;
  }
  printf("%d\n", ans);
  system("pause");
  return 0;
}