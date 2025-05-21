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
unsigned Dis[100005], V[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cur(0), Pric(0x3f3f3f3f);
unsigned long long Ans(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) Dis[i] = RD();
  for (unsigned i(1); i <= n; ++i) V[i] = RD();
  for (unsigned i(1); i < n; ++i) {
    Pric = min(Pric, V[i]);
    if (Dis[i] <= Cur) Cur -= Dis[i];
    else {
      unsigned long long Ned((Dis[i] - Cur + m - 1) / m);
      Ans += Ned * Pric;
      Cur = Cur + Ned * m - Dis[i];
    }
  }
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}