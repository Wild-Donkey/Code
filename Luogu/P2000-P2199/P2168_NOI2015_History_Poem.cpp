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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
const unsigned long long INF(0x7f7f7f7f7f7f7f7f);
unsigned m, n;
unsigned long long Ans(0), Cur(0), Tmp(0);
priority_queue<pair<unsigned long long, unsigned long long> > Q;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) Q.push({INF - RD(), INF});
  if (m ^ 2)
    while (n % (m - 1) != 1) Q.push({INF, INF}), ++n;
  // printf("%u\n", n);
  for (int i(n); i >= m; i -= (m - 1)) {
    Tmp = INF, Cur = 0;
    // printf("i = %u Ans %llu\n", i, Ans);
    for (unsigned j(m); j; --j)
      Cur += INF - Q.top().first, Tmp = min(Tmp, Q.top().second), Q.pop();
    Q.push({INF - Cur, Tmp - 1}), Ans += Cur;
  }
  printf("%llu\n%llu\n", Ans, INF - Q.top().second);
  //  }
  //  system("pause");
  return Wild_Donkey;
}