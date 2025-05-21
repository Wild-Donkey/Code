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
unsigned Lst[200005], FS[200005], Stack[200005], STop(0);
inline unsigned FindS(unsigned x) {
  while (FS[x] ^ x) Stack[++STop] = x, x = FS[x];
  while (STop) FS[Stack[STop--]] = x;
  return x;
}
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Seg {
  Seg *LS, *RS;
  unsigned Val;
}S[8000005], *Ver[200005], *CntS(S);
inline void Build(Seg* x, unsigned L, unsigned R) {
  x->Val = 0, x->LS = x->RS = NULL;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntS, L, Mid);
  Build(x->RS = ++CntS, Mid + 1, R);
}
inline void Add(Seg* x, Seg* y, unsigned L, unsigned R){
  y->Val = x->Val + 1;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) y->RS = x->RS, Add(x->LS, y->LS = ++CntS, L, Mid);
  else y->LS = x->LS, Add(x->RS, y->RS = ++CntS, Mid + 1, R);
}
inline unsigned Find(Seg* x, Seg* y, unsigned L, unsigned R) {
//  printf("Find [%u, %u] Val %u for [%u, %u]\n", L, R, y->Val - x->Val, A, B);
  if((A <= L) && (R <= B)) return y->Val - x->Val;
  unsigned Mid((L + R) >> 1);
  if((A <= Mid) && (Find(x->LS, y->LS, L, Mid))) return 1;
  if((B > Mid) && (Find(x->RS, y->RS, Mid + 1, R))) return 1;
  return 0;
}
struct Tree {
  vector<Tree*> Son;
  Tree* Fa[18];
  unsigned DFSr, Size;
  inline void GetF() { for (unsigned i(0); Fa[i]; ++i) Fa[i + 1] = Fa[i]->Fa[i]; }
  inline void DFS() {
    DFSr = ++Cnt, Size = 1;
    for (auto i:Son) i->DFS(), Size += i->Size;
  }
}T[400005], *T2;
struct Node {
  vector <Node*> E;
}N[200005];
inline Tree* Get1(Tree*x, unsigned y) {
  for (unsigned i(17); ~i; --i) if((x->Fa[i]) && (x->Fa[i] - T <= y)) x = x->Fa[i];
  return x;
}
inline Tree* Get2(Tree*x, unsigned y) {
  for (unsigned i(17); ~i; --i) if((x->Fa[i]) && (x->Fa[i] - T2 >= y)) x = x->Fa[i];
  return x;
}
unsigned m, n, Q;
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Q = RD(), T2 = T + n, Build(Ver[0] = S, 1, n);
  for (unsigned i(1); i <= m; ++i) A = RD() + 1, B = RD() + 1, N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  for (unsigned i(1); i <= n; ++i) {
    FS[i] = i;
    for (auto j:N[i].E) if((j < (N + i)) && (FindS(j - N) ^ i)) 
      T[FS[j - N]].Fa[0] = T + i, FS[FS[j - N]] = i;
  }
//  for (unsigned i(1); i <= n; ++i) printf("%u->%u ", i, T[i].Fa[0] - T); putchar(0x0A);
  for (unsigned i(n - 1); i; --i) T[i].GetF();
  for (unsigned i(1); i < n; ++i) T[i].Fa[0]->Son.push_back(T + i);
//  printf("Done\n");
  Cnt = 0, T[n].DFS();
  for (unsigned i(n); i; --i) {
    FS[i] = i;
    for (auto j:N[i].E) if((j > (N + i)) && (FindS(j - N) ^ i))
      T2[FS[j - N]].Fa[0] = T2 + i, FS[FS[j - N]] = i;
  }
  for (unsigned i(2); i <= n; ++i) T2[i].GetF();
  for (unsigned i(2); i <= n; ++i) T2[i].Fa[0]->Son.push_back(T2 + i);
  Cnt = 0, T2[1].DFS();
  for (unsigned i(1); i <= n; ++i) Lst[T2[i].DFSr] = i;
  for (unsigned i(1); i <= n; ++i) A = T[Lst[i]].DFSr, Add(Ver[i - 1], Ver[i] = ++CntS, 1, n);// printf("%u ", A); putchar(0x0A);
  for (unsigned i(1); i <= Q; ++i) {
    A = RD() + 1, B = RD() + 1, C = RD() + 1, D = RD() + 1;
    Tree *Fr(Get2(T2 + A, C)), *To(Get1(T + B, D));
    A = To->DFSr, B = To->DFSr + To->Size - 1;
//    printf("[%u, %u] [%u, %u]\n", A + 1, B, Fr->DFSr, Fr->DFSr + Fr->Size - 1);
    printf(Find(Ver[Fr->DFSr - 1], Ver[Fr->DFSr + Fr->Size - 1], 1, n) ? "1\n" : "0\n");
  }
//  }
  return Wild_Donkey;
}

