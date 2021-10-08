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
struct Que;
struct Node {
  vector<Que*> Bel; 
  unsigned Deg;
  char Vis, Le;
}N[100005], * Queue[100005];
struct Que {
  Node* Le, * Ri, * Mid;
  Que* Nxt;
}Q[100005];
signed main() {
  BdR = (n = RD()) + 1, m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), ++N[B].Deg;
    Q[i].Le = N + A, N[A].Bel.emplace_back(Q + i);
    Q[i].Mid = N + B, N[B].Bel.emplace_back(Q + i);
    Q[i].Ri = N + C, N[C].Bel.emplace_back(Q + i);
  }
  for (unsigned i(1); i <= n; ++i) if(!N[i].Deg) Queue[++Tl] = N + i;
  while (Tl ^ Hd) {//Topo and Solve 
    Node* Cur(Queue[++Hd]);
    unsigned PutLeft(100000);
    Cur->Vis = 1;
    for (auto Prs:Cur->Bel) {
      if(Cur == Prs->Le) {//Cur is A
        if(Prs->Ri->Vis) {//2nd or 3rd
          if(!(Prs->Mid->Vis)) {if(Prs->Ri->Le) --PutLeft; else ++PutLeft;}//2nd Add
        } else if(!(--(Prs->Mid->Deg))) Queue[++Tl] = Prs->Mid;//1st Add
      } else {//Cur is C or B
        if(Cur == Prs->Ri) {//Cur is C
          if(Prs->Le->Vis) {//2nd or 3rd
            if(!(Prs->Mid->Vis)) {if(Prs->Le->Le) --PutLeft; else ++PutLeft;}//2nd Add
          } else if(!(--(Prs->Mid->Deg)))Queue[++Tl] = Prs->Mid; //1st Add
        } else {//Cur is B
          if(!((Prs->Ri->Vis) & (Prs->Le->Vis))) {//2nd Add
            if(Prs->Ri->Vis) {if(Prs->Ri->Le) ++PutLeft;else --PutLeft;}//1st is C
            else {if(Prs->Le->Le) ++PutLeft;else --PutLeft;}//1st is A
          }
        }
      }
    }
    Cur->Le = (PutLeft >= 100000);
    Ans[(PutLeft < 100000) ? (--BdR) : (++BdL)] = Cur - N; 
  }
  for (unsigned i(1); i <= n; ++i) printf("%u ", Ans[i]);
  return Wild_Donkey;
}
