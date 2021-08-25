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
unsigned m, n, Hd, Tl; 
int C, D, Flow(0), Cost(0), Tmp(0);
struct Node;
struct Edge {
  Node *To;
  Edge *Nxt;
  int Value, Contain;
}E[100005], *CntE(E - 1);
struct Node {
  Edge *Fst;
  int Dist;
  char InQue;
}N[5005], *S, *T, *A, *B, *Q[5005];
char SPFA() {
//  printf("Go\n");
  Tl = Hd = 0;
  for (register unsigned i(1); i <= n; ++i){
    N[i].Dist = 0x3f3f3f3f;
  }
  for (register unsigned i(1); i <= n; ++i){
//    N[i].InQue = 0;
  }
  Q[++Tl] = S;
  S->Dist = 0;
  S->InQue = 1;
  register Node *x;
  while (Hd ^ Tl) {
//    printf("Hd %u Tl %u\n", Hd, Tl);
    ++Hd; if(Hd > 5000) Hd -= 5000;
    x = Q[Hd];
//    printf("Exten %d %d\n", x - N, x->Dist);
    x->InQue = 0;
    register Edge *Sid(x->Fst);
    while (Sid) {
      if(Sid->Contain && Sid->To->Dist > x->Dist + Sid->Value) {
        Sid->To->Dist = x->Dist + Sid->Value;
        if(!(Sid->To->InQue)) {
          ++Tl; if(Tl > 5000) Tl -= 5000;
          Q[Tl] = Sid->To;
          Sid->To->InQue = 1;
        }
      }
      Sid = Sid->Nxt;
    }
  }
  return (T->Dist < 0x3f3f3f3f);
}
int DFS(Node *x, int Come){
  if(x == T) {
    return Come;
  }
//  printf("DFS %u\n", x - N);
  x->InQue = 1;
  register Edge *Sid(x->Fst);
  register unsigned Go, Flew(0);
  while (Sid) {
    if(Sid->To->Dist == x->Dist + Sid->Value && Sid->Contain && (!(Sid->To->InQue))) {
//      printf("Go %u %u\n", Sid->To - N, min(Sid->Contain, Come));
      Go = DFS(Sid->To, min(Sid->Contain, Come));
      Sid->Contain -= Go;
      Come -= Go;
      E[(Sid - E) ^ 1].Contain += Go;
      Cost += Sid->Value * Go;
      Flew += Go;
    }
    if(!Come) {
      break;
    }
    Sid = Sid->Nxt;
  }
  x->InQue = 0;
  return Flew;
};
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3381_8.in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), S = N + RD(), T = N + RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD(), C = RDsg(), D = RDsg();
    (++CntE)->Nxt = A->Fst;
    A->Fst = CntE;
    CntE->Contain = C;
    CntE->Value = D;
    CntE->To = B;
    (++CntE)->Nxt = B->Fst;
    B->Fst = CntE;
    CntE->Value = -D;
    CntE->To = A;
  }
  while (SPFA()) {
//    printf("%u\n", T->Dist); 
//    while (Tmp = DFS(S, 0x7fffffff)) Flow += Tmp;
    Flow += DFS(S, 0x7fffffff);
  }
  printf("%d %d\n", Flow, Cost);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
4 2 2
4 3 3
2 3 1
2 1 9
1 3 5
*/
