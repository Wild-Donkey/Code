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
unsigned B, W, n;
unsigned A, C, D, t;
unsigned Cnt(0), Ans(0);
struct Node;
struct Edge {
  Node* To;
  unsigned long long Val;
};
struct Node {
  vector<Edge> E;
  Node* Fa;
  unsigned long long f[2005];
  unsigned Size;
}N[2005];
inline void DFS(Node* x) {
  x->Size = 1;
  for (auto i:x->E) if(x->Fa != i.To) {
    i.To->Fa = x, DFS(i.To);
    for (unsigned j(x->Size + i.To->Size); ~j; --j) {
      unsigned long long Tmpg(0), Tmpf(0);
      for (unsigned k(min(j, i.To->Size)); (k + x->Size >= j) && (~k); --k) {
        unsigned long long WB(i.Val * (((B - k) * k) + ((W - i.To->Size + k) * (i.To->Size - k))));
        if(Tmpf < x->f[j - k] + i.To->f[k] + WB) Tmpf = x->f[j - k] + i.To->f[k] + WB;
      }
      x->f[j] = Tmpf;
    }
    x->Size += i.To->Size;
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), W = n - (B = RD());
  for (unsigned i(1); i < n; ++i) {
    A = RD(), D = RD(), C = RD();
    N[A].E.push_back((Edge){N + D, C});
    N[D].E.push_back((Edge){N + A, C});
  }
  DFS(N + 1);
  printf("%llu\n", N[1].f[B]);
//  }
  return Wild_Donkey;
}

