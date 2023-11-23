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
const long long Neg(-1000000000000000);
long long a[100005];
unsigned m, n;
unsigned A, B, C, D, t;
struct Arr {
  vector<long long> f;
  long long g;
  unsigned Len;
  inline void Prt() {
    unsigned Dow(0);
    for (auto i : f) printf("%llu ", i + a[Dow++] * g);
    putchar(0x0A);
  }
  inline void Init(long long x) {
    // printf("Clr\n");
    f.clear(), g = x, Len = 2;
    f.push_back(0), f.push_back(0);
  }
  inline void PsUp(long long x) { g += x; }
  inline void Update(Arr* x, int Si, int Son) {
    unsigned Sz(min(x->Len + Len - 1, m + 1));
    // printf("Sz %u Si %u Son %u\n", Sz, Si, Son);
    while (f.size() < Sz) f.push_back(Neg);
    for (unsigned i(Sz - 1); ~i; --i) {
      long long Tmp(Neg);
      unsigned SzJ(min(i + 1, x->Len));
      for (unsigned j(0); j < SzJ; ++j) {
        Tmp = max(Tmp, f[i - j] + a[i - j] * (g - Si) + x->f[j] + a[j] * x->g);
      }
      f[i] = max(f[i], Tmp - (g - Si) * a[i]);
    }
    Len = Sz;
  }
} F[100005], *CntF(F);
struct Node {
  vector<pair<Node*, unsigned> > Edge;
  Arr* F;
  unsigned Size;
  int S;
  inline unsigned DFS(Node* Fa) {
    // printf("DFS %u %u\n", this, Fa);
    Node* Heavy(NULL);
    unsigned BS(0), CurS(0);
    for (auto i : Edge)
      if (i.first != Fa) {
        Node* Cur(i.first);
        Cur->S = i.second, CurS = Cur->DFS(this);
        if (BS < CurS) BS = CurS, Heavy = Cur;
      }
    // printf("Done %u %u\n", this, Heavy);
    Arr* Nw(++CntF);
    if (!Heavy) {
      Nw->Init(S);
      F = Nw;
      // printf("F %u\n", this);
      // F->Prt();
      return F->Len;
    }
    Nw->Init(0);
    (F = Heavy->F)->PsUp(S);
    F->Update(Nw, S, S);
    for (auto i : Edge)
      if (i.first != Fa && i.first != Heavy) {
        F->Update(i.first->F, S, i.second);
      }
    // printf("F %u\n", this);
    // F->Prt();
    return F->Len;
  }
} N[100005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (long long i(0); i <= m; ++i) a[i] = i * (m - i);
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].Edge.push_back({N + B, C});
    N[B].Edge.push_back({N + A, C});
  }
  N[1].S = 0, N[1].DFS(NULL);
  printf("%lld\n", N[1].F->f[m] + a[m] * N[1].F->g);
  //  }
  //  system("pause");
  return Wild_Donkey;
}