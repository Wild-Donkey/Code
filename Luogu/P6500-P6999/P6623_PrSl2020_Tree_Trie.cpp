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
unsigned Cnt(0), Tmp(0);
unsigned long long Ans(0);
struct Node {
  Node *LS, *RS;
  unsigned Cnt, Sum;
  inline void Udt() {
    Sum = 0;
    if(LS) Sum = ((LS->Sum) << 1);
    if(RS) Sum ^= (((RS->Sum) << 1) ^ ((RS->Cnt) & 1));
  }
  inline void Insert(unsigned Len);
  inline void Add(unsigned Len) {
    if(!Len) return;
    swap(LS, RS); if(LS) LS->Add(Len - 1);
    Udt();
  }
}N[12000005], *CntN(N);
inline void Node::Insert(unsigned Len) { // Insert the Highest Len To this node
  ++Cnt, Sum ^= A;
  if(!Len) return;
  if(A & 1) {if(!RS) RS = ++CntN; A >>= 1, RS->Insert(Len - 1);}
  else {if(!LS) LS = ++CntN; A >>= 1, LS->Insert(Len - 1);}
}
inline void Merge(Node* x, Node* y, unsigned Len) {
  x->Cnt += y->Cnt, x->Sum ^= y->Sum;
  if(!Len) return;
  if(x->LS && y->LS) Merge(x->LS, y->LS, Len - 1);
  else { if(!(x->LS)) x->LS = y->LS; }
  if(x->RS && y->RS) Merge(x->RS, y->RS, Len - 1);
  else { if(!(x->RS)) x->RS = y->RS; }
}
inline Node* MERGE(Node* x, Node* y) {
  if(x->Cnt < y->Cnt) {Merge(y, x, 21); return y;}
  else {Merge(x, y, 21); return x;}
}
struct Tree {
  vector <Tree*> Son;
  Node* Root;
  inline void DFS() {
    for (auto i:Son) i->DFS(), Root = MERGE(Root, i->Root);
    Root->Add(21), Ans += Root->Sum;
//    printf("%u %u\n", Ans, Root->Sum);
  }
}T[525050];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) A = RD() - 1, (T[i].Root = ++CntN)->Insert(21);
  for (unsigned i(2); i <= n; ++i) T[RD()].Son.push_back(T + i);
  T[1].DFS();
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

