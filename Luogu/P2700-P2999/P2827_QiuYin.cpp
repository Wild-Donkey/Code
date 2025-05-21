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
const long long INF(0x3f3f3f3f3f3f3f3f);
unsigned m, n, t, Cnt(0);
long long A, B, C;
long long Global(0);
long long Q1[10000005], Q2[10000005];
long long* H1(Q1 + 1), * T1(Q1), * H2(Q2 + 1), * T2(Q2);
priority_queue<long long> PQ;
long long Cut(long long x) {
  return (x * B) / C;
}
long long GetBig() {
  long long MxP, Mx1, Mx2;
  if (PQ.size()) MxP = PQ.top() + Global;
  else MxP = -INF;
  if (H1 <= T1) Mx1 = Global + *H1;
  else Mx1 = -INF;
  if (H2 <= T2) Mx2 = Global + *H2;
  else Mx2 = -INF;
  if (MxP >= Mx1 && MxP >= Mx2) {
    // printf("P %lld (1 %lld 2 %lld)\n", MxP, Mx1, Mx2);
    PQ.pop();
    return MxP;
  }
  if (Mx1 >= Mx2) {
    // printf("1 %lld\n", Mx1);
    ++H1; return Mx1;
  }
  // printf("2 %lld\n", Mx1);
  ++H2;
  return Mx2;
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
    long long Cur(GetBig()), Cuted;
    if (!(i % t)) printf("%lld ", Cur);
    Cuted = Cut(Cur);
    Global += A;
    *(++T1) = Cuted - Global;
    *(++T2) = Cur - Cuted - Global;
  }
  putchar(0x0A);
  for (unsigned i(n + m); i; --i) {
    if (!((++Cnt) % t)) printf("%lld ", GetBig());
    else GetBig();
  }
  putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}