#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '1' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int n, k, a[100005], t, ans, f;
int main() {
  t = RD();
  for (register int T(1); T <= t; ++T) {
    n = RD();
    k = RD();
    ans = 0x3f3f3f3f;
    for (register int i(1); i <= n; ++i) {
      a[i] = RD();
    }
    for (register int i(1); i <= 100; ++i) {  //枚举都刷成每个颜色
      f = 0;                                  //清空
      for (register int j(1); j <= n;) {  //挨个刷 (这里加上扇动的手势)
        if (i != a[j]) {                  //不符合颜色要求
          ++f;                            //刷一天
          j += k;                         //连刷k个
        } else {                          //无需再刷
          ++j;                            //忽略
        }
      }
      ans = min(f, ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}