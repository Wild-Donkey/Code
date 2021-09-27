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
unsigned m, M, n, q, Bd;
unsigned A, B, C, D, t;
unsigned STop(0), ETop(0), Hd, Tl;
unsigned Cnt(0), CntCo(0), Ans[3];
unsigned Sum[200005][2], Tmp(0);
struct Node;
struct NNode;
struct Edge {
  Node* To, * Frm;
  Edge* Nxt;
}E[200005], *EStack[200005];
struct Node {
  Edge* Fst;
  NNode* Last;
  Node* Fa, * Bro, * Son, * Heavy, * Top;
  unsigned DFSr, Low, Dep, Size, BelC;
  char Type;
}N[200005], * Stack[100005], * CntN;
struct NEdge {
  NNode* To;
  NEdge* Nxt;
}NE[400005], *CntNE(NE);
struct NNode{
  NEdge* Fst;
  Node* Old;
  char Col, Dist;
}NN[200005], * Q[200005], *CntNN(NN);
inline void Tarjan(Node* x) {
  x->Low = x->DFSr = ++Cnt, x->BelC = CntCo, Stack[++STop] = x;
  Edge* Sid(x->Fst);
  while (Sid) {
    EStack[++ETop] = Sid;
    if(Sid->To->DFSr) {
      if(Sid->To->Fa) --ETop;
      x->Low = min(x->Low, Sid->To->DFSr);
    }
    else {
      unsigned LastTop(ETop);
      Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
      if(Sid->To->Low == x->DFSr) {
        Node* Cur(++CntN);
        Cur->Fa = x, Cur->Bro = x->Son, x->Son = Cur;
        x->Last = Cur->Last = ++CntNN, CntNN->Old = x; 
        do {
          Stack[STop]->Bro = Cur->Son, Cur->Son = Stack[STop];
          Stack[STop]->Last = ++CntNN, (CntNN->Old = Stack[STop])->Fa = Cur;
        } while (Stack[STop--] != Sid->To);
        NNode * LiF, * LiT;
        do {
          LiF = EStack[ETop]->Frm->Last, LiT = EStack[ETop]->To->Last;
          (++CntNE)->Nxt = LiF->Fst, LiF->Fst = CntNE, CntNE->To = LiT;
          (++CntNE)->Nxt = LiT->Fst, LiT->Fst = CntNE, CntNE->To = LiF;
        } while ((ETop--) ^ LastTop);
      }
    }
    Sid = Sid->Nxt;
  }
}
inline void BFS(Node* x) {
  char Flg(0);
  Hd = Tl = 0, (Q[++Tl] = x->Last)->Col = 1, x->Last->Dist = 1;
  while (Hd ^ Tl) {
    NNode* Cur(Q[++Hd]);
    NEdge* Sid(Cur->Fst);
    while (Sid) {
      Sid->To->Col |= (Cur->Col ^ 3);
      if(Sid->To->Col == 3) {Flg = 1; break;}
      if(!(Sid->To->Dist)) (Q[++Tl] = Sid->To)->Dist = Cur->Dist + 1;
      Sid = Sid->Nxt;
    }
    if(Flg) break;
  } 
  if(Flg) x->Type = 2;
  else
    for (unsigned i(2); i <= Hd; ++i)
      Q[i]->Old->Type = ((Q[i]->Dist & 1) ? 0 : 1);
}
inline void PreDFS (Node* x) {
  x->Size = 1;
  Node* Cur(x->Son);
  unsigned Mx(0);
  while (Cur) {
    Cur->Dep = x->Dep + 1, PreDFS(Cur), x->Size += Cur->Size;
    if(Cur->Size > Mx) x->Heavy = Cur, Mx = Cur->Size;
    Cur = Cur->Bro;
  }
}
inline void DFS (Node* x) {
  x->DFSr = ++Cnt;
  if(x->Type) Sum[Cnt][x->Type - 1] = 1;
  if(!(x->Heavy)) return;
  x->Heavy->Top = x->Top, DFS(x->Heavy);
  Node* Cur(x->Son);
  while (Cur) {
    if(Cur != x->Heavy) Cur->Top = Cur, DFS(Cur);
    Cur = Cur->Bro;
  }
}
inline char Ask(Node* x, Node* y) {
  Ans[1] = Ans[2] = 0;
  while (x->Top != y->Top) {
    if(x->Top->Dep < y->Top->Dep) swap(x, y);
    C = x->Top->DFSr, D = x->DFSr, x = x->Top->Fa;
    Ans[1] += Sum[D][0] - Sum[C - 1][0];
    Ans[2] += Sum[D][1] - Sum[C - 1][1];
  }
  if(x->Dep < y->Dep) swap(x, y);
  C = y->DFSr, D = x->DFSr, x = y;
  Ans[1] += Sum[D][0] - Sum[C - 1][0];
  Ans[2] += Sum[D][1] - Sum[C - 1][1];
  --Ans[x->Type];
  if(Ans[2] || (Ans[1] & 1)) return 1;
  return 0;
}
signed main() {
  n = RD(), M = ((m = RD()) << 1), CntN = N + n;
  for (unsigned i(0); i < M; i += 2) {
    A = RD(), B = RD();
    E[i].Nxt = N[A].Fst, N[A].Fst = E + i;
    E[i ^ 1].Nxt = N[B].Fst, N[B].Fst = E + (i ^ 1);
    E[i].To = N + B, E[i].Frm = N + A;
    E[i ^ 1].To = N + A, E[i ^ 1].Frm = N + B;
  }
  for (unsigned i(1); i <= n; ++i) if(!(N[i].DFSr)) ++CntCo, Tarjan(N + i);
  Cnt = 0;
  for (Node* i(N + n + 1); i <= CntN; ++i) BFS(i);
  for (unsigned i(1); i <= n; ++i) if(N[i].Fa && N[i].Fa->Type) N[i].Type = 2;
  for (unsigned i(1); i <= n; ++i) if(!N[i].Size) N[i].Dep = 1, PreDFS(N + i);
  for (unsigned i(1); i <= n; ++i) if(!N[i].Top) N[i].Top = N + i, DFS(N + i);
  for (unsigned i(1); i <= Cnt; ++i) Sum[i][0] += Sum[i - 1][0], Sum[i][1] += Sum[i - 1][1];
  for (unsigned i(RD()); i; --i) {
    A = RD(), B = RD(), --q;
    if(A == B) {printf("No\n");continue;}
    if(N[A].BelC ^ N[B].BelC) {printf("No\n");continue;}
    printf(Ask(N + A, N + B) ? "Yes\n" : "No\n");
  } 
  return Wild_Donkey;
}
