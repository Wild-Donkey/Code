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
struct Pnt {
  long long x, y, ad;
}Hull[50005], now;
unsigned n, Cnt(0), l(1), r(1); 
long long a[50005], f[50005], L, Ans(0), Tmp(0), b[50005], c[50005], d[50005], sum[50005];
inline void Clr() {}
int main() {
  n = RD();
  L = RD(); 
  sum[0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
    sum[i] = sum[i - 1] + a[i];
    b[i] = sum[i] + i - L - 1;  //处理 t[i] 
    c[i] = sum[i] + i;          //处理 k[i] 
  }
  f[0] = 0;
  Hull[1].x = 0;
  Hull[1].y = 0;
  Hull[1].ad = 0;   //管他有没有必要的初始化 
  for (register unsigned i(1); i <= n; ++i) {
    while (l < r && (Hull[l + 1].y - Hull[l].y < ((b[i] * (Hull[l + 1].x - Hull[l].x)) << 1))) {
      ++l;  //将左端过气决策点 (斜率过小) 踢出凸壳 
    }
    f[i] = f[Hull[l].ad] + (b[i] - c[Hull[l].ad]) * (b[i] - c[Hull[l].ad]);
    now.x = c[i];
    now.y = c[i] * c[i] + f[i];     //转移 
    while (l < r && ((Hull[r].y - Hull[r - 1].y) * (now.x - Hull[r].x) > (Hull[r].x - Hull[r - 1].x) * (now.y - Hull[r].y))){
      --r;   //入队前维护下凸性 (单调性)
    }
    Hull[++r].x = now.x;
    Hull[r].y = now.y;
    Hull[r].ad = i;   //入队 
  }
  printf("%lld\n", f[n]);
  return Wild_Donkey;
}
