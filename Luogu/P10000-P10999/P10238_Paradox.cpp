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
struct Node;
struct Edge {
  Node *x, *y;
  unsigned Time;
  const char operator<(Edge& x) { return Time < x.Time; }
} E[100005];
struct Node {
  Node *Fa[18], *Dom, *TipL, *TipR;
  unsigned long long Len[18], Dis;
  unsigned Dep;
  vector<pair<Node*, unsigned> > Sons;
  void DFS(Node* Fat) {
    // printf("DFS %u\n", this);
    if (Fat) {
      for (unsigned i(0); Fa[i]->Fa[i] && i <= 17; ++i) {
        Fa[i + 1] = Fa[i]->Fa[i];
        Len[i + 1] = Len[i] + Fa[i]->Len[i];
      }
    }
    for (auto i : Sons)
      if (i.first != Fat) {
        i.first->Fa[0] = this;
        i.first->Len[0] = i.second;
        i.first->Dep = Dep + 1;
        i.first->DFS(this);
      }
  }
  void Init() { Dom = TipL = TipR = this, Dis = 0; }
  Node* Find();
} N[100005], *Stack[100005], **STop(Stack);
Node* Node::Find() {
  Node* Cur(this);
  while (Cur->Dom != Cur) *(STop++) = Cur, Cur = Cur->Dom;
  while (STop > Stack) (*(--STop))->Dom = Cur;
  return Cur;
}
unsigned long long Dist(Node* x, Node* y) {
  if (x == y) return 0;
  unsigned long long Rt(0);
  if (x->Dep < y->Dep) swap(x, y);
  for (unsigned i(17); ~i; --i)
    if ((1 << i) <= x->Dep - y->Dep) Rt += x->Len[i], x = x->Fa[i];
  if (x == y) return Rt;
  for (unsigned i(17); ~i; --i)
    if (x->Fa[i] && (x->Fa[i] != y->Fa[i]))
      Rt += x->Len[i] + y->Len[i], x = x->Fa[i], y = y->Fa[i];
  Rt += x->Len[0] + y->Len[0];
  return Rt;
}
unsigned m, n;
unsigned A, B, C, t;
unsigned long long Ans(0), Tmp(0), AList[100005];
inline void Clr() {
  for (unsigned i(1); i <= n; ++i)
    memset(N[i].Fa, 0, sizeof(N[i].Fa)), N[i].Sons.clear();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    E[i].x = N + A;
    E[i].y = N + B;
    E[i].Time = m + 1;
    N[A].Sons.push_back({N + B, C});
    N[B].Sons.push_back({N + A, C});
  }
  for (unsigned i(1); i <= n; ++i) N[i].Init();
  N[1].Dep = 1, N[1].DFS(NULL), Ans = 0;
}
void Merge(Node* x, Node* y) {
  // printf("Merge %u %u ", x - N, y - N);
  unsigned long long TmD(0);
  Node *TmL, *TmR;
  if (x->Dis < y->Dis)
    TmD = y->Dis, TmL = y->TipL, TmR = y->TipR;
  else
    TmD = x->Dis, TmL = x->TipL, TmR = x->TipR;
  Tmp = Dist(x->TipL, y->TipL);
  if (TmD < Tmp) TmD = Tmp, TmL = x->TipL, TmR = y->TipL;
  Tmp = Dist(x->TipL, y->TipR);
  if (TmD < Tmp) TmD = Tmp, TmL = x->TipL, TmR = y->TipR;
  Tmp = Dist(x->TipR, y->TipL);
  if (TmD < Tmp) TmD = Tmp, TmL = x->TipR, TmR = y->TipL;
  Tmp = Dist(x->TipR, y->TipR);
  if (TmD < Tmp) TmD = Tmp, TmL = x->TipR, TmR = y->TipR;
  x->Dis = TmD, x->TipL = TmL, x->TipR = TmR, y->Dom = x;
  Ans = max(Ans, TmD);
  // printf("Got %llu\n", TmD);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    // printf("Done\n");
    for (unsigned i(1); i <= m; ++i) A = RD(), E[A].Time = i;
    sort(E + 1, E + n);
    for (unsigned i(n - 1); i; --i) {
      // printf("%u %u %u\n", E[i].x - N, E[i].y - N, E[i].Time);
      if (E[i].Time <= m) AList[E[i].Time] = Ans;
      Merge(E[i].x->Find(), E[i].y->Find());
    }
    for (unsigned i(1); i <= m; ++i) printf("%llu\n", AList[i]);
  }
  //  system("pause");
  return Wild_Donkey;
}