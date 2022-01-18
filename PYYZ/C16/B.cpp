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
unsigned a[100005], m, n;
unsigned A, B, C, D, t, QM;
unsigned Cnt(0), Tmp(0);
unsigned St1, En1, Tm1, St2, En2, Tm2;
unsigned long long Ans(0), AU(0);
struct Seg {
  Seg* LS, * RS;
  unsigned long long Sum;
  unsigned Min;
  inline void Add(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { AU += Sum;return; }
    unsigned Mid((L + R) >> 1);
    if (L <= Mid) LS->Add(L, Mid);
    if (Mid + 1 <= B) RS->Add(Mid + 1, R);
  }
  inline void Lit(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { QM = min(QM, Min);return; }
    unsigned Mid((L + R) >> 1);
    if (L <= Mid) LS->Lit(L, Mid);
    if (Mid + 1 <= B) RS->Lit(Mid + 1, R);
  }
}S[200005], * CntS(S);
inline void Build(Seg* x, unsigned L, unsigned R) {
  if (L == R) { x->Sum = x->Min = a[L]; return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntS, L, Mid);
  Build(x->RS = ++CntS, Mid + 1, R);
  x->Min = min(x->LS->Min, x->RS->Min);
  x->Sum = x->LS->Sum + x->RS->Sum;
}
struct Node {
  vector <pair<Node*, unsigned>> E;
  Node* Top, * Fa, * Heavy;
  unsigned long long Dep;
  unsigned Size, DFSr;
  inline void PreDFS() {
    Size = 1;
    unsigned TS(0);
    for (auto i : E) if (i.first != Fa) {
      i.first->Fa = this, i.first->Dep = Dep + i.second;
      i.first->PreDFS(), Size += i.first->Size;
      if (i.first->Size > TS) Heavy = i.first, TS = i.first->Size;
    }
  }
  inline void DFS() {
    DFSr = ++Cnt;
    if (Heavy) Heavy->Top = Top, Heavy->DFS();
    for (auto i : E) if (i.first == Fa) a[DFSr] = i.second;
    else if (i.first != Heavy) i.first->Top = i.first, i.first->DFS();
  }
  inline Node* LCA(Node* y) {
    Node* x(this);
    while (x->Top != y->Top) {
      if (x->Top->Dep < y->Top->Dep) swap(x, y);
      x = x->Top->Fa;
    }
    if (x->Dep < y->Dep) return y;
    return x;
  }
}N[100005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].E.push_back(make_pair(N + B, C));
    N[B].E.push_back(make_pair(N + A, C));
  }
  N[1].Dep = 0, N[1].Fa = NULL, N[1].Top = N + 1, N[1].PreDFS(), N[1].DFS();
  for (unsigned i(1); i <= m; ++i) {
    St1 = RD(), En1 = RD(), Tm1 = RD(), St2 = RD(), En2 = RD(), Tm2 = RD();
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}