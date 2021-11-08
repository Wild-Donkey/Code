#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
long long Minu, Ans(0xaf3f3f3f3f3f3f3f);
long long SumC[1005], SumR[1005], ChosC[100005], ChosR[100005];
unsigned a[1005][1005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
priority_queue<long long> Col, Row;
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD(), Minu = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) SumR[i] += a[i][j];
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) SumC[j] += a[i][j];
  for (unsigned i(1); i <= m; ++i) Col.push(SumC[i]);
  for (unsigned i(1); i <= n; ++i) Row.push(SumR[i]);
  for (unsigned i(1); i <= t; ++i) ChosC[i] = ChosC[i - 1] + Col.top(), Col.push(Col.top() - n * Minu), Col.pop();
  for (unsigned i(1); i <= t; ++i) ChosR[i] = ChosR[i - 1] + Row.top(), Row.push(Row.top() - m * Minu), Row.pop();
  for (long long i(0); i <= t; ++i) Ans = max(Ans, ChosC[i] + ChosR[t - i] - Minu * i * (t - i));
  printf("%lld\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2 2 2 2
1 3
2 4
2 2 5 2
1 3
2 4
*/
