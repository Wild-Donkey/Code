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
unsigned long long Mod(998244353);
unsigned long long Ans(0), m, m1, m2, m3;
unsigned n, Tp;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  vector <Node*> E;
  unsigned f[36][36][3], Size;
}N[105];
inline void DFS(Node* x, Node* Fa) {
  x->Size = x->f[0][0][0] = x->f[1][0][1] = x->f[0][1][2] = 1;
  for (auto i : x->E) if (i != Fa) {
    DFS(i, x);
    unsigned To(x->Size + i->Size);
    unsigned Tmpf[min(To, Tp) + 1][36][3];
    memset(Tmpf, 0, sizeof(Tmpf));
    for (unsigned j1(min(Tp, x->Size)); ~j1; --j1) for (unsigned j2(min(Tp, x->Size)); ~j2; --j2) {
      unsigned* J(x->f[j1][j2]);
      if (!(J[0] || J[1] || J[2])) continue;
      for (unsigned k1(min(Tp, i->Size)); ~k1; --k1) for (unsigned k2(min(Tp, i->Size)); ~k2; --k2) {
        unsigned* K(i->f[k1][k2]), * T(Tmpf[min(j1 + k1, Tp)][min(j2 + k2, Tp)]);
        if (!(K[0] || K[1] || K[2])) continue;
        T[0] = (T[0] + J[0] * (K[0] * m3 % Mod + K[1] + K[2])) % Mod;
        T[1] = (T[1] + J[1] * (K[0] * m2 % Mod + K[2])) % Mod;
        T[2] = (T[2] + J[2] * (K[0] * m2 % Mod + K[1])) % Mod;
      }
    }
    memcpy(x->f, Tmpf, sizeof(Tmpf));
    x->Size = To;
  }
}
signed main() {
//  freopen("data.in", "r", stdin);
//  freopen("data.out", "w", stdout);
  n = RD(), m = RD(), Tp = (n / 3) + 2, m1 = m - 1, m2 = (m1 ? (m1 - 1) : 0), m3 = (m2 ? (m2 - 1) : 0);
  for (unsigned i(1); i < n; ++i)
    A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  DFS(N + 1, NULL);
  for (unsigned i(0); i <= Tp; ++i) for (unsigned j(0); j <= Tp; ++j) 
    Ans = (Ans + N[1].f[i][j][0] * m2 + N[1].f[i][j][1] + N[1].f[i][j][2]) % Mod;
  for (unsigned i(0); i <= Tp; ++i) Ans = (Ans + (Mod - m) * ((N[1].f[Tp][i][0] * m2 + N[1].f[Tp][i][1] + N[1].f[Tp][i][2]) % Mod)) % Mod;
  Ans = (Ans + ((N[1].f[Tp][Tp][0] * m2 + N[1].f[Tp][Tp][1] + N[1].f[Tp][Tp][2]) % Mod) * ((m * m1 >> 1) % Mod)) % Mod;
  printf("%llu\n", Ans);
  return Wild_Donkey;
}
/*
4 2
1 2
1 3
1 4
*/

