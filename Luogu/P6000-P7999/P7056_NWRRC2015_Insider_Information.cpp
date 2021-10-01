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
unsigned m, n, M;
unsigned Top(0), Tl(0), Hd(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans[100005], Tmp(0), BdL(0), BdR;
struct Node;
struct Que;
struct Edge {
  Node* To;
  Edge* Nxt;
  Que* Bel;
}E[200005], * CntE(E);
struct Que {
  Node* Le, * Ri;
  Edge* Fst, * Scd;
}Q[100005];
struct Node {
  Edge* Fst;
  unsigned Deg;
  char Vis, Le;
}N[100005], * Queue[100005];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  BdR = (n = RD()) + 1, M = ((m = RD()) << 1);
  for (unsigned i(0); i < M; i += 2) {
    A = RD(), B = RD(), C = RD(), ++N[B].Deg;
    E[i].Nxt = N[A].Fst, N[A].Fst = E + i, E[i].To = N + B, E[i].Bel = Q + (i >> 1);
    E[i ^ 1].Nxt = N[C].Fst, N[C].Fst = E + (i ^ 1), E[i ^ 1].To = N + B, E[i ^ 1].Bel = Q + (i >> 1);
    Q[i >> 1].Fst = E + i, Q[i >> 1].Scd = E + (i ^ 1), Q[i >> 1].Le = N + A, Q[i >> 1].Ri = N + C;
  }
  for (unsigned i(1); i <= n; ++i) if(!N[i].Deg) Queue[++Tl] = N + i;
  while (Tl ^ Hd) {
    Node* Cur(Queue[++Hd]);
    Edge* Sid(Cur->Fst);
    unsigned PutLeft(100000);
    Cur->Vis = 1;
    while (Sid) {
      Que* Prses(Sid->Bel);
      if(Cur == Sid->Bel->Le) {//Cur is A
        if(Sid->Bel->Ri->Vis) {//2nd or 3rd
          if(!(Sid->Bel->Fst->To->Vis)) {//2nd Add
            if(Sid->Bel->Ri->Le) --PutLeft;
            else ++PutLeft;
          }
        } else if(!(--(Sid->Bel->Fst->To->Deg))) //1st Add
          Queue[++Tl] = Sid->Bel->Fst->To;
      } else {
        if(Cur == Sid->Bel->Ri) {//Cur is C
          if(Sid->Bel->Le->Vis) {//2nd or 3rd
            if(!(Sid->Bel->Fst->To->Vis)) {//2nd Add
              if(Sid->Bel->Le->Le) --PutLeft;
              else ++PutLeft;
            }
          } else if(!(--(Sid->Bel->Fst->To->Deg))) //1st Add
            Queue[++Tl] = Sid->Bel->Fst->To;
        } else {//Cur is B
          if(!((Sid->Bel->Ri->Vis) & (Sid->Bel->Le->Vis))) {//2nd Add
            if(Sid->Bel->Ri->Vis) {//1st is C
              if(Sid->Bel->Ri->Le) ++PutLeft;
              else --PutLeft;
            } else {//1st is A
              if(Sid->Bel->Le->Le) ++PutLeft;
              else --PutLeft;
            }
          }
        }
      }
      Sid = Sid->Nxt;
    }
    Cur->Le = (PutLeft >= 100000);
    Ans[(PutLeft < 100000) ? (--BdR) : (++BdL)] = Cur - N; 
  }
  for (unsigned i(1); i <= n; ++i) printf("%u ", Ans[i]);
  return Wild_Donkey;
}
/*
5 10
1 2 3
2 3 4
3 4 5
1 2 4
1 3 4
2 3 5
2 4 5
1 2 5
1 3 5
1 4 5
5 2
1 2 4
3 4 5
*/
