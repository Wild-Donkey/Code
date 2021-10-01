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
unsigned m, n, n2;
unsigned A, B, C, D, t;
unsigned Tmp(0);
unsigned DFSCnt(1), STop(0), SCC(0);
char TmpI[500005], Cr(0), Flg(0);
vector<char> Ans[500005];
struct Trie;
struct Node {
  vector<Node*> To;
  Trie* Tr;
  unsigned Bel, Low, DFSr;
  char InS;
}N[2000005], *List[2000005], * CntN, * Frm, * Root;
struct Trie {
  Trie* Son[2], * Top, * Fa;
  unsigned RL, RR, Size, Cnt;
  char Heavy;
  inline void PreDFS() {
    unsigned Mx(0);
    if(Son[0]) Son[0]->Fa = this, Son[0]->PreDFS(), Heavy = 0, Mx = Son[0]->Size;
    if(Son[1]) {
      Son[1]->Fa = this, Son[1]->PreDFS();
      if(Son[1]->Size > Mx) Heavy = 1;
    }
  }
  inline void DFS() {
    RL = DFSCnt, RR = RL + Cnt - 1, DFSCnt += Cnt;
    if(!Son[Heavy]) return;
    Son[Heavy]->Top = Top, Son[Heavy]->DFS();
    Trie* Cur(Son[Heavy ^ 1]);
    if(Cur) Cur->Top = Cur, Cur->DFS();
  }
}T[1000005], *CntT(T), *Lst1, *Lst2;
inline void Link(Node* x, unsigned L, unsigned R) {
  if((A <= L) && (R <= B)) {Frm->To.emplace_back(x);return;}
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Link(x->To[0], L, Mid);
  if(B > Mid) Link(x->To[1], Mid + 1, R);
}
inline Node* Build(unsigned L, unsigned R) {
  if(L == R) {return N + ((List[L] - N) ^ 1);}
  unsigned Mid((L + R) >> 1);
  Node* Cur(++CntN);
  Cur->To.emplace_back(Build(L, Mid));
  Cur->To.emplace_back(Build(Mid + 1, R));
  return Cur;
}
inline void Tarjan(Node* x) {
//  printf("Tar %u\n", x - N);
  x->DFSr = x->Low = ++DFSCnt, List[++STop] = x, x->InS = 1;
  for (auto Cur:x->To) {
    if(Cur->DFSr) {if(Cur->InS) x->Low = min(x->Low, Cur->Low);}
    else Tarjan(Cur), x->Low = min(x->Low, Cur->Low);
  }
  if(x->DFSr == x->Low) {
    ++SCC;
    do List[STop]->Bel = SCC, List[STop]->InS = 0;
    while(List[STop--] != x);
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr(); 
  CntN = N + (n2 = ((n = RD()) << 1)) - 1;
  for (unsigned i(0), j(1); i < n; ++i) {
    scanf("%s", TmpI + 1), Lst1 = Lst2 = T, j = 1;
    while (TmpI[j] >= '0') {
      ++(Lst1->Size), ++(Lst2->Size);
      Ans[i].push_back(TmpI[j]);
      if(TmpI[j] == '?') {
        if(!(Lst1->Son[0])) Lst1->Son[0] = ++CntT;
        if(!(Lst2->Son[1])) Lst2->Son[1] = ++CntT;
        Lst1 = Lst1->Son[0];
        Lst2 = Lst2->Son[1];
      } else {
        Cr = TmpI[j] - '0';
        if(!(Lst1->Son[Cr])) Lst1->Son[Cr] = ++CntT;
        if(!(Lst2->Son[Cr])) Lst2->Son[Cr] = ++CntT;
        Lst1 = Lst1->Son[Cr];
        Lst2 = Lst2->Son[Cr];
      }
      ++j;
    }
    ++(Lst1->Cnt), ++(Lst1->Size), N[i << 1].Tr = Lst1;
    ++(Lst2->Cnt), ++(Lst2->Size), N[(i << 1) ^ 1].Tr = Lst2; 
  }
  T->PreDFS(), T->Top = T, T->DFS();
  for (unsigned i(0); i < n2; ++i) List[(N[i].Tr)->RL + (--((N[i].Tr)->Cnt))] = N + i;
  for (unsigned i(1); i <= n2; ++i) List[i]->DFSr = i;
  Root = Build(1, n2);
  for (Frm = N + n2 - 1; Frm >= N; --Frm) {
    Trie* Cur(Frm->Tr);
    A = Frm->DFSr + 1, B = Cur->RL + Cur->Size - 1;
    if(A <= B) Link(Root, 1, n2);
    A = Cur->Top->RL, B = Frm->DFSr - 1;
    if(A <= B) Link(Root, 1, n2);
    Cur = Cur->Top->Fa;
    while (Cur) {
      A = Cur->Top->RL, B = Cur->RR;
      if(A <= B) Link(Root, 1, n2);
      Cur = Cur->Top->Fa;
    }
  }
  for (unsigned i(1); i <= n2; ++i) List[i]->DFSr = 0;
  DFSCnt = 0, Tarjan(Root);
  for (unsigned i(0); i < n; ++i) if(N[i << 1].Bel == N[(i << 1) ^ 1].Bel) {Flg = 1;break;}
  printf(Flg ? "NO\n" : "YES\n");
  return Wild_Donkey;
}
/*
4
100
1?0
?00
10?
*/
