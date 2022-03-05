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
unsigned m, n, A, B, C, D, t, Cnt(0);
unsigned long long Ans(0);
inline void Mn(unsigned& x) { x -= (x >= Mod) ? Mod : x; }
struct Node {
  vector<Node*> Ed;
  unsigned f[2][4005], L0, R0, L1, R1;
}N[2005];
inline void DFS(Node* x, Node* Fa) {
  // printf("DFS %u Fa %u\n", x - N, Fa - N);
  x->f[0][2000] = x->f[1][2001] = 1, x->L0 = x->R0 = 2000, x->R1 = x->L1 = 2001;
  for (auto i : x->Ed) if (i != Fa) {
    DFS(i, x);
    unsigned iL(min(i->L1, i->L0)), iR(max(i->R1, i->R0));
    unsigned TL(x->L1 + iL - 2002), Sz(x->R1 + iR - 2000 - TL + 1), Tmp[Sz];
    memset(Tmp, 0, sizeof(Tmp));
    for (unsigned j(iL); j <= iR; ++j) {
      for (unsigned k(x->L1); k <= x->R1; ++k) {
        unsigned Des(j + k - 2002 - TL);
        // printf("Do1 (%u, %u) D %u\n", j, k, Des);
        Tmp[Des] = (Tmp[Des] + ((unsigned long long)i->f[1][j] * x->f[1][k])) % Mod, Des += 2;
        Tmp[Des] = (Tmp[Des] + ((unsigned long long)i->f[0][j] * x->f[1][k])) % Mod;
      }
    }
    unsigned TL0(x->L0 + iL - 2000), Sz0(x->R0 + iR - 2000 - TL0 + 1), Tmp0[Sz0];
    memset(Tmp0, 0, sizeof(Tmp0));
    for (unsigned j(iL); j <= iR; ++j) {
      for (unsigned k(x->L0); k <= (x->R0); ++k) {
        unsigned Des(j + k - 2000 - TL0);
        // printf("Do0 (%u, %u) D %u\n", j, k, Des);
        Tmp0[Des] = (Tmp0[Des] + ((unsigned long long)i->f[0][j] * x->f[0][k])) % Mod;
        Tmp0[Des] = (Tmp0[Des] + ((unsigned long long)i->f[1][j] * x->f[0][k])) % Mod;
      }
    }
    x->L1 = min(i->L1 + x->L1 - 2002, i->L0 + x->L1 - 2000), x->R1 = max(x->R1 + i->R1 - 2002, x->R1 + i->R0 - 2000);
    x->L0 = TL0, x->R0 = TL0 + Sz0 - 1;
    memcpy(x->f[1] + TL, Tmp, Sz << 2);
    memcpy(x->f[0] + TL0, Tmp0, Sz0 << 2);
  }
  // for (unsigned i(x->L0); i <= x->R0; ++i) printf("(%u,%u) ", i, x->f[0][i]); putchar(0x0A);
  // for (unsigned i(x->L1); i <= x->R1; ++i) printf("(%u,%u) ", i, x->f[1][i]); putchar(0x0A);
  // if (x == N + 1) fprintf(stderr, "Done  %u 0[%u, %u] 1[%u, %u]\n", x - N, x->L0, x->R0, x->L1, x->R1);
  return;
}
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].Ed.clear(), memset(N[i].f, 0, sizeof(N[i].f));
  Ans = 0, n = RD();
}
signed main() {
  freopen("network4.in", "r", stdin);
  // freopen("network.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    // fprintf(stderr, "Do %u\n", T);
    Clr();
    for (unsigned i(1); i < n; ++i) {
      A = RD(), B = RD();
      N[A].Ed.push_back(N + B);
      N[B].Ed.push_back(N + A);
    }
    DFS(N + 1, NULL);
    for (unsigned i(2003); i <= N[1].R0; ++i) Ans = (Ans + (unsigned long long)N[1].f[0][i] * (i - 2002)) % Mod;
    for (unsigned i(2003); i <= N[1].R1; ++i) Ans = (Ans + (unsigned long long)N[1].f[1][i] * (i - 2002)) % Mod;
    printf("%llu\n", (Ans << 1) % Mod);
  }
  //  system("pause");
  return Wild_Donkey;
}