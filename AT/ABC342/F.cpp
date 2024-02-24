#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned n, l, d;
inline void Calc(double* x, unsigned L, unsigned R) {
  double Cur(x[0] = 1);
  for (unsigned i(1); i <= R; ++i) {
    if (i > d) Cur -= x[i - d - 1];
    x[i] += Cur / d;
    if (i < L) Cur += x[i];
  }
  for (unsigned i(0); i < L; ++i) x[i] = 0;
}
double Prob[400005], Suf[200005], Ans[200005], Tmp(0);
signed main() {
  n = RD(), l = RD(), d = RD();
  Calc(Prob, l, l + d - 1);
  for (unsigned i(n + 1); i < l + d; ++i) Tmp += Prob[i], Prob[i] = 0;
  for (unsigned i(l); i <= n; ++i) Prob[i] += Prob[i - 1];
  Ans[n] = Suf[n] = Prob[n - 1] + Tmp;
  for (unsigned i(n - 1); i; --i)
    Ans[i] = max(Prob[i - 1] + Tmp, Suf[i + 1] / d),
    Suf[i] = Ans[i] + Suf[i + 1] - Ans[(i + d > n) ? n + 1 : i + d];
  printf("%.10lf\n", Suf[1] / d);
  return Wild_Donkey;
}
/*
3 2 3
*/