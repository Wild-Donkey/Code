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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
void Udt(unsigned char &x, unsigned char y) { x = max(x, y); }
unsigned a[35], m, n, N;
unsigned long long Sum[35];
unsigned char Ans(255);
map<unsigned, unsigned char> Lef, Rig;
//  inline void Clr() {}
// inline void DFS()
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), N = min(n, (n >> 1)), m = (RD() << 1);
  for (unsigned i(1); i <= n; ++i) a[i] = (RD() << 1);
  sort(a + 1, a + n + 1);
  for (unsigned i(1); (i << 1) <= n; ++i) swap(a[i], a[n - i + 1]);
  for (unsigned i(n); i; --i) Sum[i] = Sum[i + 1] + a[i];
  Lef[m] = 31, Rig[m] = 31, Sum[0] = Sum[1] - Sum[N + 1];
  for (unsigned i(1); i <= N; ++i) {
    for (auto j : Lef) {
      if (31 - j.second >= Ans && (m - j.first) > Sum[i]) continue;
      if (j.first < (a[i] >> 1)) continue;
      unsigned Cur(j.first - (a[i] >> 1));
      if (31 - j.second < Ans - 1) Udt(Lef[Cur], j.second - 1);
      if (j.first < a[i]) continue;
      Cur = j.first - a[i];
      Udt(Lef[Cur], j.second);
    }
    Ans = min((unsigned)Ans, (unsigned)31 - Lef[0]);
  }
  for (unsigned i(N + 1); i <= n; ++i) {
    for (auto j : Rig) {
      if (31 - j.second >= Ans && m - j.first > Sum[i] + Sum[0]) continue;
      if (j.first < (a[i] >> 1)) continue;
      unsigned Cur(j.first - (a[i] >> 1));
      if (31 - j.second < Ans - 1) Udt(Rig[Cur], j.second - 1);
      if (j.first < a[i]) continue;
      Cur = j.first - a[i];
      Udt(Rig[Cur], j.second);
    }
    Ans = min((unsigned)Ans, (unsigned)31 - Rig[0]);
  }
  for (auto i : Lef)
    Ans = min((unsigned)Ans, (unsigned)62 - i.second - Rig[m - i.first]);
  if (Ans <= 30)
    printf("%u\n", Ans);
  else
    printf("-1\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}