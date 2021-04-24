#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Head(0), CntBelong(0);
bool b[10005];
struct Edge;
struct Node {
  unsigned DFSr, Low, Belong;
  Edge *First;
  char Instack, Clean;
}N[500005], *Stack[500005];
struct Edge {
  Node *To;
  Edge *Next; 
  char Tag;
}E[1000005], *Cnte(E);
void Link(Node *x, Node *y) {
  (++Cnte)->Next = x->First;
  x->First = Cnte;
  Cnte->To = y;
  return;
}
struct UnionEdge;
struct UnionNode {
  unsigned DFSr;
  UnionEdge *First;
}UnionN[500005];
struct UnionEdge {
  UnionNode *To;
  UnionEdge *Next; 
}UnionE[1000005], *UnionCnte(UnionE);
void UnionLink(UnionNode *x, UnionNode *y) {
  (++UnionCnte)->Next = x->First;
  x->First = UnionCnte;
  UnionCnte->To = y;
  return;
}
struct PrintTag {
  unsigned S, T;
  inline bool operator < (const PrintTag &x) const{
    return (this->S == x.S) ? (this->T < x.T) : (this->S < x.S);
  }
}PT[1000005], *CntPT(PT);
void DFS_1st(Node *x) {
  x->DFSr = ++Cnt; 
  Edge *Side(x->First);
  while (Side) {
    if(!(Side->To->DFSr)) {
      DFS_1st(Side->To);
    }
    Side = Side->Next; 
  }
  return;
}
void DFS_2nd(Node *x) {
  printf("DFS2 %u\n", x - N);
  Edge *Side(x->First);
  Stack[++Head] = x;
  x->Instack = 1;
  while (Side) {
    if(Side->To->DFSr < x->DFSr) {
      x->Low = Side->To->DFSr; 
    }
    else {
      if(!(Side->To->Instack)) { 
        DFS_2nd(Side->To);
        x->Low = Side->To->Low;
      }
    }
    Side = Side->Next;
  }
  if(x->Low == x->DFSr) { // Pop Stack
    ++CntBelong;
    if(Head <= 1) {
      Stack[Head]->Instack = 0;
      Head = 0;
    }
    while (Head) {
      Stack[Head]->Clean = 1;
      Stack[Head]->Instack = 0;
      Stack[Head--]->Belong = CntBelong;
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    Link(N + A, N + B);
    Link(N + B, N + A);
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!(N[i].DFSr)) {
      DFS_1st(N + i);
      DFS_2nd(N + i);
    }
  }
  for (register Node *i(N + 1); i <= N + n; ++i) {
    register Edge *Side(i->First);
    while (Side) {
      if(i->Belong != Side->To->Belong) {
        UnionLink(UnionN + i->Belong, UnionN + Side->To->Belong);
        UnionLink(UnionN + Side->To->Belong, UnionN + i->Belong);
      }
      Side = Side->Next;
    }
  }
  for (register Node *i(N + 1); i <= N + n; ++i) {
    if(i->Clean) {
      register Edge *Side(i->First);
      while (Side) {
        if(!(Side->To->Clean)) {
          (++CntPT)->S = i - N;
          CntPT->T = Side->To - N;
        }
        Side = Side->Next;
      }
    }
  }
  sort(PT + 1, CntPT + 1);
  printf("%u\n", CntPT - PT);
  for (register PrintTag *i(PT + 1); i <= CntPT; ++i) {
    printf("%u %u\n", i->S, i->T);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



