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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
struct Node;
struct Edge {
  Node* To;
  unsigned long long Val;
};
struct Node {
  vector<Edge> E;
  Node* Fa;
  unsigned long long Sum, Dep, f[2005], g[2005];
  unsigned Size;
}N[2005];
inline void DFS(Node* x) {
  x->Size = 1;
  for (auto i:x->E) if(x->Fa != i.To) {
    i.To->Fa = x, i.To->Dep = x->Dep + i.Val, DFS(i.To);
//    printf("From %u to %u\n", x - N, i.To - N);
    for (unsigned j(x->Size + i.To->Size); ~j; --j) {
      unsigned long long Tmpg(0), Tmpf(0); 
      for (unsigned k(min(j, i.To->Size)); (k + x->Size >= j) && (~k); --k) {
        unsigned long long TmpB((j - k) * (i.To->g[k] + i.Val * k) + k * x->g[j - k]);
        unsigned Wk(i.To->Size - k), Wjk(x->Size - j + k);
        unsigned long long Wg(i.To->Sum - i.To->g[k]), Wxg(x->Sum - x->g[j - k]);
        unsigned long long TmpW(Wjk * (Wg + i.Val * Wk) + Wk * Wxg);
//        printf("j %u, k %u, %llu %llu %u %u %llu %llu\n", j, k, TmpB, TmpW, Wk, Wjk, Wg, Wxg);
//        printf("xg %llu ig %llu\n", x->g[j - k], i.To->g[k]);
        if(Tmpf < x->f[j - k] + i.To->f[k] + TmpB + TmpW) {
          Tmpf = x->f[j - k] + i.To->f[k] + TmpB + TmpW;
          Tmpg = x->g[j - k] + i.To->g[k] + i.Val * k;
        }
      }
      x->g[j] = Tmpg, x->f[j] = Tmpf;
//      printf("Node %u Black %u f%llu g%llu\n", x - N, j, x->f[j], x->g[j]);
    }
    x->Size += i.To->Size, x->Sum += i.To->Sum + i.To->Size * i.Val;
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].E.push_back((Edge){N + B, C});
    N[B].E.push_back((Edge){N + A, C});
  }
  DFS(N + 1);
  printf("%llu\n", N[1].f[m]);
//  }
  return Wild_Donkey;
}

