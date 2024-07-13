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
unsigned m, n, t, Cnt(0);
long long A, B, C;
long long Global(0);
priority_queue<long long> PQ;
long long Cut(long long x) {
  return (x * B) / C;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), A = RD(), B = RD(), C = RD(), t = RD();
  for (unsigned i(1); i <= n; ++i)
    PQ.push(RD());
  for (unsigned i(1); i <= m; ++i) {
    long long Cur((PQ.top()) + Global), Cuted;
    PQ.pop();
    if (!(i % t)) printf("%lld ", Cur);
    Cuted = Cut(Cur);
    Global += A;
    PQ.push(Cuted - Global);
    PQ.push(Cur - Cuted - Global);
  }
  putchar(0x0A);
  while (PQ.size()) {
    if (!((++Cnt) % t)) printf("%lld ", PQ.top() + Global);
    PQ.pop();
  }
  putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}