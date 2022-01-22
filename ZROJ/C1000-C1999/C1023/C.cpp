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
const unsigned long long Mod(998244353);
unsigned long long Ans[3005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned long long f[3005], g[3005];
  unsigned Size;
}N[3005];
inline void DFSF(Node* x) {
//  printf("DFSF %u\n", x - N);
  x->Size = 1;
  for (auto i:x->To) if(i != x->Fa){
    i->Fa = x, DFSF(i), x->Size += i->Size;
    for (unsigned k(x->Size); k; --k) {
      for (unsigned j(min(k - 1, i->Size)); j; --j) {
        x->f[k] = (x->f[k] + x->f[k - j] * i->f[j]) % Mod;
      }
    }
  }
}
inline void DFSG(Node* x) {
//  printf("DFSG %u\n", x - N);
  x->g[0] = 1;
  if(x->Fa) {
    x->g[1] = x->Fa->f[1];
    for (unsigned i(2); i < m; ++i) x->g[i] = x->Fa->g[i - 1];
    for (auto i:x->Fa->To) if((i != x->Fa->Fa) && (i != x)) {
      for (unsigned j(m); j > 1; --j) {
        for (unsigned k(min(j - 1, i->Size)); k; --k) {
//          printf("jk %u %u x %u i %u g %llu f %llu\n", j, k, x - N, i - N, x->g[j - k], i->f[k]);
          x->g[j] = (x->g[j] + x->g[j - k] * i->f[k]) % Mod;
        }
      }
    }
//    for (unsigned i(0); i < m; ++i) {
//      printf("G%u = %llu\n", i, x->g[i]);
//    }
  }
  for (auto i:x->To) if(i != x->Fa) DFSG(i);
  for (unsigned Si(1); Si <= m; ++Si) {
    for (unsigned i(min(Si, x->Size)); i; --i) {
//      printf("Calc %u %u %llu\n", Si, i, x->f[i] * x->g[Si - i]);
      Ans[x - N] = (Ans[x - N] + x->f[i] * x->g[Si - i]) % Mod;
    }
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) N[i].f[1] = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  DFSF(N + 1), DFSG(N + 1);
  for (unsigned i(1); i <= n; ++i)printf("%llu ", Ans[i]);
//  }
  return Wild_Donkey;
}

