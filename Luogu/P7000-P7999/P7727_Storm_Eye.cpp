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
const unsigned long long Mod(998244353);
inline void Mn(unsigned& x) { x -= (x >= Mod) ? Mod : 0; }
unsigned long long Ans(1);
unsigned m, n, A, B;
struct Node {
  vector<Node*> E;
  unsigned f[4], Size;
  char Final;
}N[200005];
inline void DFS(Node* x, Node* Fa) {
  unsigned long long C1(1), C2(1), C3(1), C4(Fa->Final ^ x->Final ^ 1);
  for (auto i : x->E) if (i != Fa) {
    DFS(i, x);
    C1 = C1 * i->f[(x->Final ^ i->Final) << 1] % Mod;
    C2 = C2 * (i->f[0] + i->f[1] + i->f[2]) % Mod;
    C3 = C3 * (((i->Final == x->Final) ? i->f[0] : 0) + i->f[1] + i->f[2] + i->f[3]) % Mod;
    if (C4) C4 = C4 * ((i->Final == x->Final) ? (i->f[2] + i->f[3]) : 0) % Mod;
  }
  x->f[0] = C1;
  x->f[1] = Mod + C2 - C1, Mn(x->f[1]);
  x->f[2] = C3;
  x->f[3] = C4;
  // printf("C %llu %llu %llu %llu\n", C1, C2, C3, C4);
  // printf("f[%u] = %u %u %u %u\n", x - N, x->f[0], x->f[1], x->f[2], x->f[3]);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Final = RD();
  for (unsigned i(1); i < n; ++i)
    A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  N[0].Final = N[1].Final, DFS(N + 1, N), Ans = N[1].f[1] + N[1].f[2] + N[1].f[3];
  // printf("%llu\n", Ans);
  printf("%llu\n", Ans % Mod);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2
0 1
1 2
2
1 0
1 2
*/