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
#define INFi 0x3f3f3f3f
#define Lbt(x) ((x)&((~(x))+1))
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
bitset<40005> a, Vis;
unsigned Log[70005], Pop[70005], f[70005];
unsigned Ava[105], Di[40005], List[25], Dist[25][40005];
unsigned m, n, t, A, B, C, D;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
inline void Dij(unsigned S, unsigned* Dis) {
  // printf("Dij S%u\n", S);
  memset(Dis, 0x3f, (n + 2) << 2), Dis[S] = 0;
  priority_queue<pair<unsigned, unsigned> > Q;
  Vis = 0;
  Q.push(make_pair(INFi, S)), Dis[S] = 0;
  while (!Q.empty()) {
    unsigned Cur(Q.top().second);
    Q.pop();
    if (Vis[Cur])return;
    Vis[Cur] = 1;
    for (unsigned i(1); i <= m; ++i) {
      if ((Cur > Ava[i]) && (Dis[Cur - Ava[i]] > Dis[Cur] + 1))
        Dis[Cur - Ava[i]] = Dis[Cur] + 1, Q.push(make_pair(INFi - Dis[Cur - Ava[i]], Cur - Ava[i]));
      if ((Cur + Ava[i] <= n) && (Dis[Cur + Ava[i]] > Dis[Cur] + 1))
        Dis[Cur + Ava[i]] = Dis[Cur] + 1, Q.push(make_pair(INFi - Dis[Cur + Ava[i]], Cur + Ava[i]));
    }
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD() + 1, t = RD(), m = RD();
  memset(Di, 0x3f, sizeof(Di)), Di[0] = 0;
  memset(f, 0x3f, sizeof(f));
  for (unsigned i(1); i <= t; ++i) A = RD(), a[A] = (a[A] ^ 1), a[A + 1] = (a[A + 1] ^ 1);
  for (unsigned i(1); i <= m; ++i) Ava[i] = RD();
  for (unsigned i(1); i <= n; ++i) if (a[i]) List[++Cnt] = i, Dij(i, Dist[Cnt]);
  // for (unsigned i(1); i <= Cnt; ++i) {
  //   printf("Frm %u To:", List[i]);
    // for (unsigned j(1); j <= n; ++j) printf("%u ", Dist[i][j]);
  //   putchar(0x0A);
  // }
  n = (1 << Cnt), f[n - 1] = 0;
  for (unsigned i(0); i <= n; ++i) Pop[i] = Pop[i >> 1] + (i & 1);
  for (unsigned i(0); (1 << i) <= n; ++i) Log[1 << i] = i;
  for (unsigned i(1); i <= n; ++i) Log[i] = max(Log[i - 1], Log[i]);
  for (unsigned i(n - 1); i; --i) {
    if (Pop[i] & 1) continue;
    // printf("F%u = %u\n", i, f[i]);
    for (unsigned j(i); j; j -= Lbt(j)) {
      unsigned Frm(Log[Lbt(j)]);
      for (unsigned k(j - Lbt(j)); k; k -= Lbt(k)) {
        unsigned To(Log[Lbt(k)]), Tur(i ^ (1 << Frm) ^ (1 << To));
        // printf("%u >> %u, (%u, %u)\n", i, Tur, Frm + 1, To + 1);
        f[Tur] = min(f[Tur], f[i] + Dist[Frm + 1][List[To + 1]]);
      }
    }
  }
  printf("%u\n", f[0]);
  //  }
//  system("pause");
  return Wild_Donkey;
}