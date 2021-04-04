#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
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
int n, p, k, t, ans, b, c, tmp, f[100005] /*f[i] 表示删除l块, l % k = i 时的*/;
char S[100005];
bool a[100005];
void Clr() {  //初始化变量和数组
  n = RD();   //读入优化已省略
  p = RD();
  k = RD();
  gets(S);
  b = RD();
  c = RD();
  for (register int i(0); i < n; ++i) {
    a[i + 1] = S[i] - '0';  //将字串转化为 bool 数组, 存某一位上是否有平台
  }
  memset(f, 0, sizeof(f));
  ans = 0x7f3f3f3f;
  return;
}
int main() {
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    for (register int i(0); i < k; ++i) {  //枚举符合 0 <= l < k 的 l
      for (register int j(p + i); j <= n; j += k) {  //模拟弹跳
        if (!a[j]) {                                 //无平台
          f[i] += b;                                 //加平台
        }
      }
    }
    for (register int i(0); i <= n - p; ++i) {  //枚举每个方案中的 l
      tmp = c * i;                              //删除 i 块需要的花费
      if (i >= k) {
        if (!a[i + p - k]) {  // f[i % k]中计算了给 i + p - k 加平台的花费
          f[i % k] -= b;  //不用给已经删掉的块加平台
        }
      }
      tmp += f[i % k];  //删除 i 块的花费 + 加平台的花费 = 总花费
      ans = min(ans, tmp);  //更新最优方案
    }
    printf("%d\n", ans);
  }
  return 0;
}