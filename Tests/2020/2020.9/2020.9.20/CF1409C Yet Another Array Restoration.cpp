#include <cstdio>
using namespace std;
int m, n, a, b, len, ans(0), d, dfr;
int main() {
  scanf("%d", &n);
  for (register int T(1); T <= n; ++T) {
    scanf("%d%d%d", &len, &a, &b);
    dfr = (b - a);                                //差
    d = (dfr + len - 2) / (len - 1);              //公差
    for (register int i(len - 1); i >= 1; --i) {  // a, b间的间隔数
      if (!(dfr % i)) {
        d = dfr / i;  //整除
        break;
      }
    }
    for (register int j(0); j >= 0; ++j) {  // a, b之间
      if (a + j * d <= b) {
        printf("%d ", a + j * d);
      } else {
        len -= j;
        break;
      }
    }
    for (register int j(1); (j <= len && a - j * d > 0); ++j) {  // a前
      printf("%d ", a - j * d);
    }
    len -= (a - 1) / d;
    for (register int j(1); j <= len; ++j) {  // b后
      printf("%d ", b + j * d);
    }
    printf("\n");
  }
  return 0;
}