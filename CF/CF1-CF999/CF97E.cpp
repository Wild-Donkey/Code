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
unsigned m, M, n, q, Bd, AskN(0);
unsigned A, B, C, D, t;
unsigned STop(0), ETop(0), Hd, Tl;
unsigned Cnt(0), CntCo(0), Ans1, Ans2;
unsigned Sum[200005][2], Tmp(0);
char Flg(0), DeBug(0);
struct Node;
struct NNode;
struct Seg {
  Seg* LS, * RS;
  unsigned Val1, Val2, Val3;
}S[400005], * CntS(S);
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
//  printf("Tarjan %u\n", x - N);
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
//        printf("Cut %u\n", x - N);  
        set<unsigned> SET;
        Node* Cur(++CntN);
        Cur->Fa = x, Cur->Bro = x->Son, x->Son = Cur;
        x->Last = Cur->Last = ++CntNN, CntNN->Old = x; 
        SET.insert(x - N);
        do {
//          printf("Stack %u\n", Stack[Top] - N);
          Stack[STop]->Bro = Cur->Son, Cur->Son = Stack[STop];
          Stack[STop]->Last = ++CntNN, (CntNN->Old = Stack[STop])->Fa = Cur;
          SET.insert(Stack[STop] - N);
//          printf("Insert %u\n", Stack[STop] - N);
        } while (Stack[STop--] != Sid->To);
        NNode * LiF, * LiT;
        do {
//          printf("Add (%u, %u)\n", EStack[ETop]->Frm - N, EStack[ETop]->To - N);
          LiF = EStack[ETop]->Frm->Last, LiT = EStack[ETop]->To->Last;
          if(!SET.count(LiF->Old - N)) printf("Caonima\n");
          if(!SET.count(LiT->Old - N)) printf("Caonima\n");
//          printf("Count %u %u\n", LiF->Old - N, LiT->Old - N);
          (++CntNE)->Nxt = LiF->Fst, LiF->Fst = CntNE, CntNE->To = LiT;
          (++CntNE)->Nxt = LiT->Fst, LiT->Fst = CntNE, CntNE->To = LiF;
        } while ((ETop--) ^ LastTop);
      }
    }
    Sid = Sid->Nxt;
  }
}
inline void BFS(Node* x) {
//  printf("BFS Before %u Now %u\n", x->Fa - N, x->Last - NN);
  Flg = Hd = Tl = 0, (Q[++Tl] = x->Last)->Col = 1, x->Last->Dist = 1;
  while (Hd ^ Tl) {
    NNode* Cur(Q[++Hd]);
    NEdge* Sid(Cur->Fst);
//    printf("Hd %u Col %u\n", Cur - NN, Cur->Col);
    while (Sid) {
//      printf("Search %u Old %u Col %u\n", Sid->To - NN, Sid->To->Old - N, Sid->To->Col);
      Sid->To->Col |= (Cur->Col ^ 3);
      if(Sid->To->Col == 3) {Flg = 1; break;}
      if(!(Sid->To->Dist)) (Q[++Tl] = Sid->To)->Dist = Cur->Dist + 1;
      Sid = Sid->Nxt;
    }
    if(Flg) break;
//    printf("Out %u\n", Cur - NN);
  }
//  printf("Have %u\n", Flg);
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
  if(x->Type == 1) Sum[Cnt][0] = 1;
  if(x->Type == 2) Sum[Cnt][1] = 1;
  if(!(x->Heavy)) return;
  x->Heavy->Top = x->Top, DFS(x->Heavy);
  Node* Cur(x->Son);
  while (Cur) {
    if(Cur != x->Heavy) Cur->Top = Cur, DFS(Cur);
    Cur = Cur->Bro;
  }
}
inline void Ask(Node* x, Node* y) {
  Flg = Ans1 = Ans2 = 0;
  while (x->Top != y->Top) {
    if(x->Top->Dep < y->Top->Dep) swap(x, y);
    C = x->Top->DFSr, D = x->DFSr, x = x->Top->Fa;
    Ans1 += Sum[D][0] - Sum[C - 1][0];
    Ans2 += Sum[D][1] - Sum[C - 1][1];
//    printf("Q[%u, %u]\n", C, D);
  }
  if(x->Dep < y->Dep) swap(x, y);
  C = y->DFSr, D = x->DFSr, x = y;
  Ans1 += Sum[D][0] - Sum[C - 1][0];
  Ans2 += Sum[D][1] - Sum[C - 1][1];
//  printf("Q[%u, %u] %u\n", C, D, x - N);
//  printf("Top %u DFAr %u\n", x - N, x->DFSr);
  if(x->Type == 1) --Ans1;
  if(x->Type == 2) --Ans2;
//  printf("Found %u %u %u\n", Ans1, Ans2, Ans3);
  if(Ans2) {Flg = 1;return;}
  if(Ans1 & 1) {Flg = 1;return;}
//  if((Ans1 + Ans3) & 1) {Flg = 1;return;}
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), M = ((m = RD()) << 1), CntN = N + n;
  if(m == 89848) DeBug = 1;
  for (unsigned i(0); i < M; i += 2) {
    A = RD(), B = RD();
    E[i].Nxt = N[A].Fst, N[A].Fst = E + i;
    E[i ^ 1].Nxt = N[B].Fst, N[B].Fst = E + (i ^ 1);
    E[i].To = N + B, E[i].Frm = N + A;
    E[i ^ 1].To = N + A, E[i ^ 1].Frm = N + B;
  }
  for (unsigned i(1); i <= n; ++i) if(!(N[i].DFSr)) ++CntCo, Tarjan(N + i);
//  printf("Done\n");
  Cnt = 0;
  for (Node* i(N + n + 1); i <= CntN; ++i) BFS(i);
  for (unsigned i(1); i <= n; ++i) if(N[i].Fa && N[i].Fa->Type) N[i].Type = 2;
  for (unsigned i(1); i <= n; ++i) if(!N[i].Size) N[i].Dep = 1, PreDFS(N + i);
  for (unsigned i(1); i <= n; ++i) if(!N[i].Top) N[i].Top = N + i, DFS(N + i);
//  for (unsigned i(1); i <= n; ++i) printf("Type[%u] %u\n", i, N[i].Type);
  for (unsigned i(1); i <= Cnt; ++i) Sum[i][0] += Sum[i - 1][0], Sum[i][1] += Sum[i - 1][1];
//  if(DeBug) {
//    printf("Cnt %u Cone %u Ed %u\n", Cnt, CntCo, CntNE - NE);
//  }
  q = RD();
  while (q) {
    A = RD(), B = RD(), --q, ++AskN;
//    if(DeBug && (AskN ^ 1432)) continue;
//    if(DeBug) {
//      printf("A B %u %u Type %u %u\n", A, B, N[A].Type, N[B].Type);
//      printf("Fa %u %u Dep %u %u\n", N[A].Fa - N, N[B].Fa - N, N[A].Dep, N[B].Dep);
//    }
    if(A == B) {printf("No\n");continue;}
    if(N[A].BelC ^ N[B].BelC) {printf("No\n");continue;}
    if(N[A].Fa == N[B].Fa) {
      if((N[A].Type == 2) || (N[B].Type == 2)) {printf("Yes\n");continue;}
      if((N[A].Type + N[B].Type) & 1){printf("Yes\n");continue;}
      printf("No\n"); continue; 
    }
    if(N[A].Dep < N[B].Dep) swap(A, B);
    if(N[A].Fa->Fa == N + B) {
      if(N[A].Type) {printf("Yes\n");continue;}
      printf("No\n"); continue; 
    }
    Ask(N + A, N + B), printf(Flg ? "Yes\n" : "No\n");
//    if(DeBug) {
//      printf("Ans %u %u %u\n", Ans1, Ans2);
//    }
  } 
//  }
//  system(\"pause\");
  return Wild_Donkey;
}
/*
14 18
1 2
2 3
3 1
2 4
4 5
5 3
5 6
5 7
6 8
7 8
6 9
8 10
9 10
4 11
4 13
11 12
13 12
14 4

11 15
1 3
1 2
2 3
3 4
3 5
4 5
5 6
5 7z
6 7
4 8
4 9
8 9
9 10
9 11
10 11

9 12
1 8
2 8
2 3
1 3
1 4
2 4
1 5
2 5
1 6
1 7
6 7
9 1
*/
