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
struct Factory {
  long long x, p, c, sump, sumpx, K, f;
}F[1000005]; // 工厂属性 
struct Hull {
  long long x, y;
  unsigned Ad;
}H[1000005], Then;  // 凸壳 
unsigned a[10005], now, n, l(1), r(1);
bool b[10005];
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    F[i].x = RD();
    F[i].p = RD();
    F[i].c = RD();
    F[i].sump = F[i - 1].sump + F[i].p;
    F[i].sumpx = F[i - 1].sumpx + F[i].p * F[i].x;
    F[i].K = F[i].sumpx - F[i].sump * F[i].x - F[i].c;
  } // 各种预处理
  for (register unsigned i(1); i <= n; ++i) {
    while (l < r && ((H[l + 1].y - H[l].y) < (F[i].x) * (H[l + 1].x - H[l].x))) {
      ++l;  // 弹出无用节点 
    }
    now = H[l].Ad;
    F[i].f = F[now].f + F[i].c + (F[i].sump - F[now].sump) * F[i].x - F[i].sumpx + F[now].sumpx;  // 转移 
    Then.Ad = i;
    Then.x = F[i].sump;
    Then.y = F[i].f + F[i].sumpx;
    while (l < r && ((Then.y - H[r].y) * (H[r].x - H[r - 1].x) < (H[r].y - H[r - 1].y) * (Then.x - H[r].x))) {
      --r;  // 删除上凸节点 
    }
    H[++r] = Then;
  }
  printf("%lld\n", F[n].f);
  return Wild_Donkey;
}
