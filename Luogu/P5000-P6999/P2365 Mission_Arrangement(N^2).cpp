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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
struct Ms {
  long long C, T, SumC, SumT, f;
}M[5005]; // 任务属性 
struct Hull {
  long long x, y;
  unsigned Ad;
}H[5005], *Now, Then; // 下凸壳 
unsigned n, l(1), r(1);
long long S, Cst; 
int main() {
  n = RD();
  S = RD();
  M[0].SumT = S;
  for (register unsigned i(1); i <= n; ++i) {
    M[i].T = RD();
    M[i].C = RD();
    M[i].SumT = M[i - 1].SumT + M[i].T;
    M[i].SumC = M[i - 1].SumC + M[i].C; //预处理 
  }
  Cst = S * M[n].SumC;  // 截距中的一项常数 
  for (register unsigned i(1); i <= n; ++i) {
    while (l < r && ((H[l + 1].y - H[l].y) < M[i].SumT * (H[l + 1].x - H[l].x))) {
      ++l; // 弹出过气决策点 
    }
    M[i].f = M[H[l].Ad].f + (M[i].SumC - M[H[l].Ad].SumC) * M[i].SumT + Cst - M[i].SumC * S; // 转移 
    Then.Ad = i;
    Then.x = M[i].SumC;
    Then.y = M[i].f;    // 求新点坐标 
    while (l < r && ((Then.y - H[r].y) * (H[r].x - H[r - 1].x) <= (H[r].y - H[r - 1].y) * (Then.x - H[r].x))) {
      --r; // 维护下凸 
    }
    H[++r] = Then;      // 入队 
  }
  printf("%lld\n", M[n].f);
  return Wild_Donkey;
}



