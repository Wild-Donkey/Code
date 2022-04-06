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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node;
struct Set {
  Set* Fa;
  Node* Val;
}S[200005], *Stack[200005], **STop(Stack);
struct Node {
  vector<Node*> E, IE, DFSSon, SemSon, Son;
  Node *Sem, *Fa, *J;
  unsigned DFN, Size;
  inline void DFSforDFN();
  inline void DFSforSize();
  inline char Les(Node* x) {return Sem->DFN < x->Sem->DFN;}
}N[200005], *Rk[200005];
inline Node* Find(Set* x) {
  while (x != x->Fa) *(++STop) = x, x = x->Fa;
  Node* Cur(x->Val);
  while (STop > Stack)
    Cur = ((*STop)->Val = (Cur->Les((*STop)->Val)) ? Cur : (*STop)->Val), (*(STop--))->Fa = x;
  return Cur;
}
inline void Node::DFSforDFN() {
  Rk[DFN = ++Cnt] = this;
  for (auto i:E) if(!(i->DFN)) DFSSon.push_back(i), i->DFSforDFN();
}
inline void Node::DFSforSize() {
  Size = 1;
  for (auto i:Son) i->DFSforSize(), Size += i->Size;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), m = RD(); 
  for (unsigned i(1); i <= m; ++i)
    A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].IE.push_back(N + A); 
  N[1].DFSforDFN(), N[n + 1].DFN = 0x3f3f3f3f;
  for (unsigned i(1); i <= n; ++i) S[i] = {S + i, N + i};
  for (unsigned i(1); i <= n; ++i) N[i].J = N + i;
  for (unsigned i(n); i; --i) {
    Node* Cur(Rk[i]);
    for (auto j:Cur->SemSon) {
      Node* Get(Find(S + (j - N)));
      if(Get->Les(j->J)) j->J = Get;
    }
    Cur->Sem = N + n + 1;
    for (auto j:Cur->IE) {
      if(j->DFN < Cur->DFN) Cur->Sem = (Cur->Sem->DFN > j->DFN) ? j : Cur->Sem;
      else {
        Node* Get(Find(S + (j - N)));
        Cur->Sem = (Get->Les(Cur)) ? Get->Sem : Cur->Sem;
      }
    }
    Cur->Sem->SemSon.push_back(Cur);
    for (auto j:Cur->DFSSon) S[j - N].Fa = S + (Cur - N);
  }
//  printf("DFN:"); for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].DFN); putchar(0x0A);
//  printf("Sem:"); for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Sem - N); putchar(0x0A);
//  printf("J:"); for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].J - N); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) {
    Node* Cur(Rk[i]);
    if(Cur->J->Sem == Cur->Sem) Cur->Fa = Cur->Sem;
    else Cur->Fa = Cur->J->Fa;
  }
//  for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Fa - N); putchar(0x0A);
//  for (unsigned i(1); i <= n; ++i) printf("%u %u\n", i, N[i].Fa - N); 
  for (unsigned i(2); i <= n; ++i) N[i].Fa->Son.push_back(N + i);
  N[1].DFSforSize();
  for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Size); putchar(0x0A);
  return Wild_Donkey;
}
/*
6 7
1 2
2 3
2 4
3 5
4 5
5 2
2 6

10 15
1 2
2 3
3 4
3 5
3 6
4 7
7 8
7 9
7 10
5 6
6 8
7 8
4 1
3 6
5 3
*/
