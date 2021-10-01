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
unsigned m, n, n2, SCC, Top(0);
unsigned A, B, C, D, t;
unsigned BinL(0), BinR(1000000000), BinMid; 
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
struct Node;
struct Seg;
struct Node {
  Node* Bro;
  unsigned RL, RR, Low, DFSr, Pos, Num, Bel;
  inline const char operator < (const Node &x) const {return Pos < x.Pos; }
}N[20005], ForFind, * Tlag[10005], *Stack[20005], * To;
struct Seg {
  Seg* LS, * RS;
  Node* Ava;
  unsigned Mn;
  inline void Chg(unsigned L, unsigned R) {
    if(L == R) {Mn = B;return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Chg(L, Mid);
    else RS->Chg(Mid + 1, R);
    Mn = min(LS->Mn, RS->Mn);
  }
  inline void Vis(unsigned L, unsigned R) {
    if(L == R) {Ava = NULL;return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Vis(L, Mid);
    else RS->Vis(Mid + 1, R);
    Ava = (LS->Ava) ? (LS->Ava) : (RS->Ava);
  }
  inline void Qry(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {Ans = min(Ans, Mn);return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Qry(L, Mid);
    if(B > Mid) RS->Qry(Mid + 1, R);
  }
  inline void Find(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {To = Ava;return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Find(L, Mid);
    if(To) return;
    if(B > Mid) RS->Find(Mid + 1, R);
  }
}S[40005], * CntS(0);
inline void Build(Seg* x, unsigned L, unsigned R) {
  x->Mn = 0x3f3f3f3f;
  if (L == R) {x->Ava = N[L].Bro;return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntS, L, Mid);
  Build(x->RS = ++CntS, Mid + 1, R);
  x->Ava = (x->LS->Ava) ? (x->LS->Ava) : (x->RS->Ava);
}
inline void Tarjan(Node* x) {
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x;
  Ans = 0x3f3f3f3f, A = x->RL, B = x - N - 1;
  if((B < 0x3f3f3f3f) && (A <= B)) S->Qry(0, n2 - 1);
  A = x + 1 - N, B = x->RR;
  if(A <= B) S->Qry(0, n2 - 1);
  x->Low = min(x->Low, Ans);
  A = x->Bro - N, B = x->Low, S->Chg(0, n2 - 1), S->Vis(0, n2 - 1);
  To = NULL, A = x->RL, B = x - N - 1; 
  if((B < 0x3f3f3f3f) && (A <= B)) S->Find(0, n2 - 1);
  A = x + 1 - N, B = x->RR;
  if(A <= B) S->Find(0, n2 - 1);
  Node* Cur(To);
  while(Cur) {
    Tarjan(Cur), x->Low = min(x->Low, Cur->Low);
    To = NULL, A = x->RL, B = x - N - 1;
    if((B < 0x3f3f3f3f) && (A <= B)) S->Find(0, n2 - 1);
    A = x + 1 - N, B = x->RR;
    if(A <= B) S->Find(0, n2 - 1);
    Cur = To;
  }
  A = x->Bro - N, B = x->Low, S->Chg(0, n2 - 1);
  if(x->Low == x->DFSr) {
    ++SCC, B = 0x3f3f3f3f;
    do{
      A = Stack[Top]->Bro - N, S->Chg(0, n2 - 1), Stack[Top]->Bel = SCC;
    }while(Stack[Top--] != x);
  }
}
inline char Judge(unsigned x) {
  SCC = 0, Flg = 0, CntS = S, Cnt = 0;
  Build(S, 0, n2 - 1);
  for (unsigned i(0); i < n2; ++i) {
    if(N[i].Pos >= x) ForFind.Pos = N[i].Pos - x + 1, N[i].RL = lower_bound(N, N + n2, ForFind) - N;
    else N[i].RL = 0;
    ForFind.Pos = N[i].Pos + x, N[i].RR = lower_bound(N, N + n2, ForFind) - N;
    if(N[i].RR >= n2) N[i].RR = n2 - 1; else --(N[i].RR);
  }
  for (unsigned i(0); i < n2; ++i) N[i].Low = N[i].DFSr = N[i].Bel = 0;
  for (unsigned i(0); i < n2; ++i) if(!N[i].DFSr) Tarjan(N + i);
  for (unsigned i(0); i < n2; ++i) if(N[i].Bel == N[i].Bro->Bel) {Flg = 1;break;}
  return Flg;
}
signed main() {
  n2 = ((n = RD()) << 1);
  for (unsigned i(0); i < n2; i += 2) {
    N[i].Pos = RD(), N[i ^ 1].Pos = RD();
    N[i].Num = N[i ^ 1].Num = i >> 1;
  }
  sort(N, N + n2);
  for (unsigned i(0); i < n2; ++i) {
    if(Tlag[N[i].Num]) Tlag[N[i].Num]->Bro = N + i, N[i].Bro = Tlag[N[i].Num];
    else Tlag[N[i].Num] = N + i;
  }
  while (BinL ^ BinR) {
    BinMid = (BinL + BinR + 1) >> 1;
    if(Judge(BinMid)) BinR = BinMid - 1;
    else BinL = BinMid;
  }
  printf("%u\n", BinL);
  return Wild_Donkey;
}
