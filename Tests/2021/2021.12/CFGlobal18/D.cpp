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
int a[200005];
unsigned b[200005][2];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned QO;
unsigned WDHd(0), WDTl(0), NoHd(0), NoTl(0);
char QC;
struct Tr {
  vector <Tr*> To;
  Tr* Fa, * Top, * Heavy;
  unsigned ToFaVal, Size, Dep, DFSr;
  char Dec;
}T[200005], * DFSA[200005];
struct Node {
  Node* LS, * RS;
  unsigned Cou;
  char OdEv;
}N[400005], * CntN(N);
struct Need {
  Tr* Fr, * To;
}Ne[200005], * QN[200005];
inline void Clr() {
  for (unsigned i = 0; i <= n; ++i) T[i].To.clear();
  n = RD(), m = RD(), CntN = N, Cnt = WDHd = WDTl = NoHd = NoTl = 0;
}
inline void PreDFS(Tr* x) {
  x->Size = 1, Tmp = 0;
  for (auto i : x->To)if (i != x->Fa) {
    i->Fa = x, i->Dep = x->Dep + 1;
    PreDFS(i);
    x->Size += i->Size;
    if (i->Size > Tmp) x->Heavy = i, Tmp = i->Size;
  }
}
inline void DFS(Tr* x) {
  x->DFSr = ++Cnt, DFSA[Cnt] = x;
  if (x->Heavy) x->Heavy->Top = x->Top, DFS(x->Heavy);
  for (auto i : x->To) if ((i != x->Heavy) && (i != x->Fa)) {
    i->Top = i, DFS(i);
  }
}
inline void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) {
    x->OdEv = (DFSA[L]->ToFaVal ? 1 : 0);
    x->Cou = DFSA[L]->Dec;
    return;
  }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->OdEv = x->LS->OdEv ^ x->RS->OdEv;
  x->Cou = x->LS->Cou + x->RS->Cou;
}
inline void Qry(Node* x, unsigned L, unsigned R) {
  if (A <= L && R <= B) {
    QO ^= x->OdEv, QC += x->Cou;
    return;
  }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid)Qry(x->LS, L, Mid);
  if (B > Mid)Qry(x->RS, Mid + 1, R);
}
inline void Chg(Node* x, unsigned L, unsigned R) {
  if (L == R) {
    x->OdEv = (DFSA[L]->ToFaVal ? 1 : 0);
    x->Cou = DFSA[L]->Dec;
    return;
  }
  unsigned Mid((L + R) >> 1);
  if (L <= Mid) Chg(x->LS, L, Mid);
  else Chg(x->RS, Mid + 1, R);
}
inline void Find(Tr* x, Tr* y) {
  QO = QC = 0;
  while (x != y) {
    if (x->Top != y->Top) {
      if (x->Top->Dep < y->Top->Dep) swap(x, y);
      A = x->Top->DFSr, B = x->DFSr, Qry(N, 1, n);
      x = x->Top->Fa;
    }
    else {
      if (x->Dep < y->Dep) swap(x, y);
      A = y->DFSr + 1, B = x->DFSr;
      if (A <= B) Qry(N, 1, n);
      break;
    }
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned TT(1); TT <= t; ++TT) {
    Clr();
    for (unsigned i(1); i < n; ++i) {
      b[i][0] = RD(), b[i][1] = RD(), a[i] = RDsg();
      T[b[i][0]].To.push_back(T + b[i][1]);
      T[b[i][1]].To.push_back(T + b[i][0]);
    }
    T[1].Fa = NULL, T[1].Dep = 1, PreDFS(T + 1);
    for (unsigned i(1); i < n; ++i) {
      if (T[b[i][0]].Fa == T + b[i][1]) {
        T[b[i][0]].ToFaVal = a[i], T[b[i][0]].Dec = 1;
        if (a[i] < 0) T[b[i][0]].ToFaVal = T[b[i][0]].Dec = 0;
      }
      else {
        T[b[i][1]].ToFaVal = a[i], T[b[i][1]].Dec = 1;
        if (a[i] < 0) T[b[i][1]].ToFaVal = T[b[i][1]].Dec = 0;
      }
    }
    T[1].Top = T + 1, DFS(T + 1), Build(N, 1, n);
    for (unsigned i(1); i <= m; ++i) {
      Ne[i].Fr = T + RD();
      Ne[i].To = T + RD();
      Find(Ne[i].Fr, Ne[i].To);
      if (QC) {
        if (QC == 1) {

        }
        else {

        }
      }
    }
  }
  //  system("pause");
  return Wild_Donkey;
}