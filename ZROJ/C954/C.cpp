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
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
struct EdIn {
  unsigned Fr, To;
  inline const char operator < (const EdIn &x) const {
    return (this->Fr ^ x.Fr) ? (this->Fr < x.Fr) : (this->To < x.To);
  }
  inline const char operator == (const EdIn &x) const {
    return (this->Fr == x.Fr) && (this->To == x.To);
  }
}EI[200005];
struct Edge;
struct Node {
  Node *In1, *In2;
  char Ava;
  unsigned Dep, ID, OD;
  Edge *Fst;
}N[100005], *Q[100005];
inline void Print(Node *x) {
  printf("Node %u ID %u OD %u Ava %u Dep %u\n", x - N, x->ID, x->OD, x->Ava, x->Dep);
  printf("In1 %u In2 %u\n", x->In1 - N, x->In2 - N);
}
struct Edge {
  Node *To;
  Edge *Nxt;
}E[200005];
unsigned m, n, Hd, Tl;
unsigned long long Cnt(0), Cnt0(0), Ans(0);
void DFS (Node *x) {
  register Edge *Sid(x->Fst);
  register unsigned TA(0);
  while (Sid) {
    if(Sid->To->Ava) {
      ++(x->OD);
      if((Sid->To->Dep == 2) && (Sid->To->ID == 1)) DFS(Sid->To);
      if(x->Dep == 1) {
        if(Sid->To->ID == 2) ++Ans;// 1, 1, 2
        else {
          Ans += Sid->To->OD;// 1, 2, 3
          Ans += 3 * (Cnt0 - 1); // 1, 2 + 1
          ++TA; // 1, 2, 2
        }
      }
    }
    Sid = Sid->Nxt;
  }
  Ans += ((unsigned long long)TA * (TA - 1));
}
int main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
  n = RD(), m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    EI[i].Fr = RD(), EI[i].To = RD();
  }
  sort(EI + 1, EI + m + 1);
  m = unique(EI + 1, EI + m + 1) - EI - 1;
  for (register unsigned i(1); i <= m; ++i) {
    ++N[EI[i].To].ID;
    E[i].Nxt = N[EI[i].Fr].Fst;
    N[EI[i].Fr].Fst = E + i;
    E[i].To = N + EI[i].To;
    if(N[EI[i].To].In1) N[EI[i].To].In2 = EI[i].Fr + N;
    else N[EI[i].To].In1 = EI[i].Fr + N;
  }
  Hd = Tl = 0;
  for (register unsigned i(1); i <= n; ++i) if(!(N[i].ID)) {
    ++Cnt0, N[i].Dep = 1, Q[++Tl] = N + i, N[i].Ava = 1;
    continue;
  }
  if(Cnt0 >= 3) Ans = (unsigned long long)Cnt0 * (Cnt0 - 1) * (Cnt0 - 2);
  register Node *Now;
  register Edge *Sid;
  while (Hd < Tl) {
    Now = Q[++Hd], Sid = Now->Fst;
    while (Sid) {
      if(!(Sid->To->Dep)) {
        Sid->To->Dep = Now->Dep + 1;
        Q[++Tl] = Sid->To;
        if(Now->Dep == 1) {
          if(Sid->To->ID <= 2) {
            Sid->To->Ava = 1, Sid = Sid->Nxt;
            continue;
          }
        } else {
          if((Sid->To->ID == 1) && (Now->Dep == 2)) { // Available
            Sid->To->Ava = 1, Sid = Sid->Nxt;
            continue;
          }
        }
      } else {// Visited
      	Sid->To->Dep = Now->Dep + 1;
      	if(Sid->To->Dep > 3) {
      	  Sid->To->Ava = 0;
          Sid = Sid->Nxt;
          continue;
        }
      	if(Sid->To->Dep == 3) {
      	  if((Now->ID == 1) && (Sid->To->ID == 2)) { // Available
            if(Sid->To->In1 == Now) {
              if((Sid->To->In2 == Now->In1) || (Sid->To->In2 == Now->In2)) {
                Sid->To->Ava = 1, --(Now->OD), Sid = Sid->Nxt;
                continue;
              }
            } else {
              if((Sid->To->In1 == Now->In1) || (Sid->To->In1 == Now->In2)) {
                Sid->To->Ava = 1, --(Now->OD), Sid = Sid->Nxt;
                continue;
              }
            }
          }
          Sid->To->Ava = 0;
        }
      }
      Sid = Sid->Nxt;
    }
  }
  for (register unsigned i(1); i <= n; ++i) if(!(N[i].ID)) DFS(N + i);
//  for (register unsigned i(1); i <= n; ++i) Print(N + i);
  printf("%llu\n", Ans);
  return Wild_Donkey;
}
/*
4 4
1 2
1 3
1 2
3 4

9 8
1 4
2 4
2 5
3 6
5 7
6 5
6 8
6 9

4 3
1 3
2 4
1 4

3 3
1 2
2 3
1 3

7 10
3 4
5 6
2 3
1 6
6 7
2 4
2 7
5 7
2 7
1 6
*/
